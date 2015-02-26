// --------------------------------------------------------------------------------------------------------------------
// <copyright file="CsvParser.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class provides the methods neede to parse a CSV file into a package.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace RHSStringTableTools
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Text.RegularExpressions;
    using Model;

    /// <summary>
    /// The CSV file parser
    /// </summary>
    public static class CsvParser
    {
        /// <summary>
        /// Parses a given folder into a Project
        /// </summary>
        /// <param name="folderPath">The path to a csv file</param>
        /// <param name="sourceAction">The action to be performed on the source files</param>
        /// <param name="fillMissing">Whether to fill the missing values</param>
        /// <returns>
        /// A <see cref="Project"/> containing a <see cref="Package"/> per found string table csv file.
        /// </returns>
        public static Project ParseProject(string folderPath, SourceAction sourceAction = SourceAction.Nothing, bool fillMissing = false)
        {
            if (!Directory.Exists(folderPath))
                throw new ApplicationException(string.Format("The specified folder does not exist: {0}", folderPath));

            var project = new Project()
            {
                Name = new DirectoryInfo(folderPath).Name
            };

            // get all stringtables
            foreach (var stringtablefile in Directory.EnumerateFiles(folderPath, "*.csv", SearchOption.AllDirectories))
            {
                try
                {
                    var package = Parse(stringtablefile, fillMissing);
                    project.Packages.Add(package);

                    // perform action on the source files
                    switch (sourceAction)
                    {
                        case SourceAction.Delete:
                            File.Delete(stringtablefile);
                            break;

                        case SourceAction.Rename:
                            File.Move(stringtablefile, string.Format("{0}.bkup", stringtablefile));
                            break;

                        case SourceAction.Nothing:
                            break;
                    }
                }
                catch (Exception ex)
                {
                    throw new ApplicationException(string.Format("Failed parsing file: {0} Error: {1}", stringtablefile, ex.Message));
                }
            }

            return project;
        }

        /// <summary>
        /// Parses a given file into a Package which can then be used to make a large project.
        /// </summary>
        /// <param name="filePath">The path to a csv file</param>
        /// <param name="fillMissing">Whether to fill the missing values</param>
        /// <returns>
        /// A package containing a <see cref="Container"/> with all the keys or null if unsuccessful.
        /// </returns>
        public static Package Parse(string filePath, bool fillMissing = false)
        {
            // check that the file is valid
            if (!File.Exists(filePath))
                throw new ApplicationException(string.Format("The specified csv file does not exist: {0}", filePath));
            var extension = Path.GetExtension(filePath);
            if (extension != null && !extension.Equals(".csv"))
                throw new ApplicationException(string.Format("The specified file is not a csv file: {0}", filePath));

            // get package name from the folder that the file is in
            var packageName = Path.GetFileName(Path.GetDirectoryName(filePath));

            // create the package with the container
            var result = new Package
            {
                Name = packageName
            };

            result.Containers.Add(new Container { Name = string.Format("{0}_{1}", packageName, "container") });

            // read the file in to strings
            List<string> lines = File.ReadAllLines(filePath).ToList();

            // parse languages
            var languageString = lines.FirstOrDefault(l => l.Contains("LANGUAGE,"));

            if (languageString == null)
                throw new ApplicationException(string.Format("The specified csv file does not have language line: {0}",
                    filePath));

            var fileLanguages = ParseLanguages(languageString);

            // check that languages are indeed allowed
            foreach (var language in fileLanguages)
            {
                if (!XmlDeSerializer.AllowedLanguages.Contains(language))
                    throw new ApplicationException(
                        string.Format("The specified csv file contains an unrecognised language: {0} -> {1}", filePath,
                            language));
            }

            // parse by line
            foreach (var line in lines)
            {
                var key = ParseLine(line, fileLanguages, fillMissing);

                if (key != null)
                {
                    result.Containers[0].Keys.Add(key);
                }
            }

            return result;
        }

        /// <summary>
        /// Parses a string into the languages it contains
        /// </summary>
        /// <param name="languageString">The string from the string table file that contains all the languages.</param>
        /// <returns>The list of languages that are contained with in the file.</returns>
        public static List<string> ParseLanguages(string languageString)
        {
            // replace any stray quotes, some files inexplicably have this
            languageString = Regex.Replace(languageString, "\"", string.Empty);

            // trim the whitespace
            languageString = Regex.Replace(languageString, @"\s+", string.Empty);

            var languageArray = languageString.Split(new[] { ',' });

            // remove the first entry
            List<string> result = languageArray.ToList();
            result.RemoveAt(0);

            return result;
        }

        /// <summary>
        /// Parses a line from the csv file and constructs a key from it.
        /// </summary>
        /// <param name="line">The line to be parsed.</param>
        /// <param name="languages">The languages</param>
        /// <param name="fillMissing">Whether to fill the missing values</param>
        /// <returns>The key constructed from the line of csv. Null if line is irrelevant.</returns>
        public static Key ParseLine(string line, List<string> languages, bool fillMissing = false)
        {
            // return null if line is invalid or irrelevant
            if (string.IsNullOrWhiteSpace(line) || line.Trim().StartsWith("//") || line.Trim().StartsWith("\"//") ||
                line.Contains("LANGUAGE,"))
            {
                return null;
            }

            // replace all whitespace with spaces
            line = Regex.Replace(line, @"\s+", " ");

            // split the string by commas taking into account that commas might be in quotes
            var resultArray = Regex.Split(line.Trim(), ",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");

            // the first value becomes the key
            var result = new Key
            {
                Id = resultArray[0]
            };

            // if mismatch in number of values do nothing with the extra
            // if (resultArray.GetLength(0) - 1 != languages.Count) throw new ApplicationException(string.Format("The provided line contains more values than specified languages: {0}", line));

            // add the languages and the values to the dictionary
            for (int i = 1; i <= languages.Count; i++)
            {
                // trim
                resultArray[i] = resultArray[i].Trim();

                // remove unnecessary quotes
                if (resultArray[i].StartsWith("\"") && resultArray[i].EndsWith("\""))
                {
                    resultArray[i] = resultArray[i].Substring(1, resultArray[i].Length - (1 * 2));
                }

                try
                {
                    result.GetType().GetProperty(languages[i - 1]).SetValue(result, resultArray[i]);
                }
                catch (Exception ex)
                {
                    throw new ApplicationException(string.Format("Could not set key value. Lang: {1}, Val: {2}. Error: {0}", ex.Message, languages[i - 1], resultArray[i]));
                }
            }

            result.FillOriginalKeyWithEnglish();

            // fill the languages that were not found
            if (fillMissing)
            {
                result.FillEmptyKeysWithEnglishOrOriginal();
            }

            return result;
        }
    }
}