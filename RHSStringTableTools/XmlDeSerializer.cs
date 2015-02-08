// --------------------------------------------------------------------------------------------------------------------
// <copyright file="XmlDeSerializer.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="XmlDeSerializer" /> class provides the methods neede to serialize and deserialize xml stringtables
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System;
using System.Collections.ObjectModel;
using System.IO;
using System.Xml.Serialization;

namespace RHSStringTableTools
{
    using RHSStringTableTools.Model;
    using System.Collections.Generic;

    /// <summary>
    /// Deals with xml stringtables
    /// </summary>
    public class XmlDeSerializer
    {
        private static List<string> allowedLanguages = new List<string>() { "Original", "English", "Czech", "French", "Spanish", "Italian", "Polish", "Portuguese", "Russian", "German" };

        /// <summary>
        /// Gets the list of allowed languages
        /// </summary>
        public static List<string> AllowedLanguages
        {
            get
            {
                return allowedLanguages;
            }
        }

        /// <summary>
        /// Writes a <see cref="Project"/> to file.
        /// </summary>
        /// <param name="project">The <see cref="Project"/> to be written to file.</param>
        /// <param name="path">The path to the xml file.</param>
        public static void WriteXml(Project project, string path)
        {
            // create the directories of the path if they dont exist
            Directory.CreateDirectory(Path.GetDirectoryName(path));

            // remove default namespace information
            var ns = new XmlSerializerNamespaces();
            ns.Add("", ""); 

            var serializer = new XmlSerializer(typeof(Project));
            using (TextWriter writer = new StreamWriter(path))
            {
                serializer.Serialize(writer, project, ns);
            }
        }

        /// <summary>
        /// Loads a xml file into a <see cref="Project"/>
        /// </summary>
        /// <param name="path">The path to the xml file</param>
        /// <returns>The <see cref="Project"/> containing the keys from the xml file.</returns>
        public static Project LoadXml(string path)
        {
            var deserializer = new XmlSerializer(typeof(Project));
            TextReader reader = new StreamReader(path);
            
            object obj = deserializer.Deserialize(reader);
            var XmlData = (Project)obj;
            
            reader.Close();

            // assign path to file
            XmlData.FileName = path;

            return XmlData;
        }

        /// <summary>
        /// Loads all xml files from a folder path recursively
        /// </summary>
        /// <param name="folderPath">The path to the folder</param>
        /// <returns>An <see cref="ObservableCollection{T}"/> of <see cref="Project"/>s found in that folder.</returns>
        public static ObservableCollection<Project> LoadXmlFolder(string folderPath)
        {
            var result = new ObservableCollection<Project>();

            if (!Directory.Exists(folderPath)) throw new ApplicationException(string.Format("The specified folder does not exist: {0}", folderPath));

            // get all stringtables
            foreach (var stringtablefile in Directory.EnumerateFiles(folderPath, "Stringtable.xml", SearchOption.AllDirectories))
            {
                try
                {
                    var project = LoadXml(stringtablefile);
                    result.Add(project);
                }
                catch (Exception ex)
                {
                    throw new ApplicationException(string.Format("Failed parsing file: {0} Error: {1}", stringtablefile, ex.Message));
                }
            }

            return result;
        }
    }
}