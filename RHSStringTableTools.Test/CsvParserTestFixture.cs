using System.IO;
using System.Linq;
using RHSStringTableTools.Model;

namespace RHSStringTableTools.Test
{
    using System.Collections.Generic;
    using NUnit.Framework;

    [TestFixture]
    public class CsvParserTestFixture
    {
        private string languageString = @"LANGUAGE,					English,				Russian,					German";

        private string commentString = @" // Object names: ///////////////////////////////////////////////////////////////";

        private string commentString1 = @"//M1083A1P2 Variants//";

        private string emptyString = @"";

        private string emptyString1 = @" ";

        private string properString = @"STR_M1083A1P2_Name,					M1083A1P2,						T-72B (obr. 1984g.),						T-72B (obr. 1984g.)";

        private string properString1 = "STR_M1083A1P3_Name,					\"M1083A1P2 is abstract, this\" ,						T-72B (obr. 1984g.),						T-72B (obr. 1984g.)";

        private List<string> languages = new List<string>() { "English", "Russian", "German" };

        [SetUp]
        public void SetUp()
        {
            DirectoryCopy("testdata", "testdatarename", true);
            DirectoryCopy("testdata", "testdatadelete", true);
        }

        private static void DirectoryCopy(string sourceDirName, string destDirName, bool copySubDirs)
        {
            // Get the subdirectories for the specified directory.
            DirectoryInfo dir = new DirectoryInfo(sourceDirName);
            DirectoryInfo[] dirs = dir.GetDirectories();

            if (!dir.Exists)
            {
                throw new DirectoryNotFoundException(
                    "Source directory does not exist or could not be found: "
                    + sourceDirName);
            }

            // If the destination directory doesn't exist, create it. 
            if (!Directory.Exists(destDirName))
            {
                Directory.CreateDirectory(destDirName);
            }

            // Get the files in the directory and copy them to the new location.
            FileInfo[] files = dir.GetFiles();
            foreach (FileInfo file in files)
            {
                string temppath = Path.Combine(destDirName, file.Name);
                file.CopyTo(temppath, false);
            }

            // If copying subdirectories, copy them and their contents to new location. 
            if (copySubDirs)
            {
                foreach (DirectoryInfo subdir in dirs)
                {
                    string temppath = Path.Combine(destDirName, subdir.Name);
                    DirectoryCopy(subdir.FullName, temppath, copySubDirs);
                }
            }
        }

        [TearDown]
        public void TearDown()
        {
            Directory.Delete("testdatarename", true);
            Directory.Delete("testdatadelete", true);
        }

        [Test]
        public void VerifyThatParseLanguagesWorks()
        {
            var languageList = CsvParser.ParseLanguages(languageString);

            Assert.AreEqual(languages.Count, languageList.Count);

            Assert.AreEqual(languages[0], languageList[0]);
            Assert.AreEqual(languages[1], languageList[1]);
            Assert.AreEqual(languages[2], languageList[2]);
        }

        [Test]
        public void VerifyThatParseLineWorks()
        {
            Assert.IsNull(CsvParser.ParseLine(commentString,CsvParser.ParseLanguages(languageString)));
            Assert.IsNull(CsvParser.ParseLine(commentString1, CsvParser.ParseLanguages(languageString)));
            Assert.IsNull(CsvParser.ParseLine(emptyString, CsvParser.ParseLanguages(languageString)));
            Assert.IsNull(CsvParser.ParseLine(emptyString1, CsvParser.ParseLanguages(languageString)));

            Key key = CsvParser.ParseLine(properString, CsvParser.ParseLanguages(languageString));

            Assert.IsNotNull(key);

            Key key2 = CsvParser.ParseLine(properString1, CsvParser.ParseLanguages(languageString));

            Assert.IsNotNull(key2);

            Assert.AreEqual("STR_M1083A1P2_Name", key.Id);
            Assert.AreEqual("M1083A1P2", key.GetLanguage("English"));
            Assert.AreEqual("T-72B (obr. 1984g.)", key.GetLanguage("Russian"));
            Assert.AreEqual("T-72B (obr. 1984g.)", key.GetLanguage("German"));

            Assert.AreEqual("M1083A1P2", key.GetLanguage("Original"));

            Assert.IsNull(key.GetLanguage("Spanish"));

            Assert.AreEqual("STR_M1083A1P3_Name", key2.Id);
            Assert.AreEqual("M1083A1P2 is abstract, this", key2.GetLanguage("English"));
            Assert.AreEqual("T-72B (obr. 1984g.)", key2.GetLanguage("Russian"));
            Assert.AreEqual("T-72B (obr. 1984g.)", key2.GetLanguage("German"));

            Assert.IsNull(key2.GetLanguage("Czech"));

            Key key3 = CsvParser.ParseLine(properString1, CsvParser.ParseLanguages(languageString), true);

            Assert.IsNotNull(key3);

            Assert.AreEqual("M1083A1P2 is abstract, this", key3.GetLanguage("Original"));

            Assert.IsNotNull(key3.GetLanguage("Spanish"));
            Assert.AreEqual("M1083A1P2 is abstract, this", key3.GetLanguage("Spanish"));

            Assert.AreEqual("STR_M1083A1P3_Name", key3.Id);
            Assert.AreEqual("M1083A1P2 is abstract, this", key3.GetLanguage("English"));
            Assert.AreEqual("T-72B (obr. 1984g.)", key3.GetLanguage("Russian"));
            Assert.AreEqual("T-72B (obr. 1984g.)", key3.GetLanguage("German"));

            Assert.IsNotNull(key3.GetLanguage("Czech"));

            //Assert.AreEqual("M1083A1P2 is abstract, this", key2.GetLanguage("Czech"));
        }

        [Test]
        public void VerifyThatFileBecomesAPackage()
        {
            var obj = CsvParser.Parse("testdata\\folder1\\Stringtable.csv");
            Assert.IsNotNull(obj);
            Assert.IsInstanceOfType(typeof(Package), obj);

            Assert.AreEqual("folder1", obj.Name);

            Assert.AreEqual(1, obj.Containers.Count);
            Assert.AreEqual("folder1_container", obj.Containers.First().Name);
            Assert.AreEqual(21, obj.Containers.First().Keys.Count);

            obj = CsvParser.Parse("testdata\\folder2\\Stringtable.csv");
            Assert.IsNotNull(obj);
            Assert.IsInstanceOfType(typeof(Package), obj);

            Assert.AreEqual("folder2", obj.Name);

            Assert.AreEqual(1, obj.Containers.Count);
            Assert.AreEqual("folder2_container", obj.Containers.First().Name);
            Assert.AreEqual(44, obj.Containers.First().Keys.Count);
        }

        [Test]
        public void VerifyThatFolderBecomesAProject()
        {
            var obj = CsvParser.ParseProject("testdata");

            Assert.IsNotNull(obj);
            Assert.IsInstanceOfType(typeof(Project), obj);
            Assert.AreEqual("testdata", obj.Name);

            Assert.AreEqual(2, obj.Packages.Count);
            Assert.AreEqual("folder1", obj.Packages.First().Name);
        }

        [Test]
        public void VerifyThatFilesRename()
        {
            Assert.IsTrue(File.Exists("testdatarename\\folder1\\Stringtable.csv"));
            Assert.IsTrue(File.Exists("testdatarename\\folder2\\Stringtable.csv"));

            var obj = CsvParser.ParseProject("testdatarename", sourceAction: SourceAction.Rename);

            Assert.IsTrue(File.Exists("testdatarename\\folder1\\Stringtable.csv.bkup"));
            Assert.IsTrue(File.Exists("testdatarename\\folder2\\Stringtable.csv.bkup"));

            Assert.IsFalse(File.Exists("testdatarename\\folder1\\Stringtable.csv"));
            Assert.IsFalse(File.Exists("testdatarename\\folder2\\Stringtable.csv"));
        }

        [Test]
        public void VerifyThatFilesDelete()
        {
            Assert.IsTrue(File.Exists("testdatadelete\\folder1\\Stringtable.csv"));
            Assert.IsTrue(File.Exists("testdatadelete\\folder2\\Stringtable.csv"));

            var obj = CsvParser.ParseProject("testdatadelete", sourceAction: SourceAction.Rename);

            Assert.IsFalse(File.Exists("testdatadelete\\folder1\\Stringtable.csv"));
            Assert.IsFalse(File.Exists("testdatadelete\\folder2\\Stringtable.csv"));
        }
    }
}
