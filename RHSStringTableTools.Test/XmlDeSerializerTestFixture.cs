
using System.IO;
using System.Xml;

namespace RHSStringTableTools.Test
{
    using System.Collections.Generic;
    using RHSStringTableTools.Model;

    using NUnit.Framework;

    [TestFixture]
    public class XmlDeSerializerTestFixture
    {
        private const string pathToXml = @"testoutput\Stringtable.xml";
        private const string pathToSaveXml = @"testoutput\save\Stringtable.xml";

        [Test]
        public void VerifyThatSerializeDeSerializeWorks()
        {
            var obj = CsvParser.ParseProject("testdata");

            if (!Directory.Exists(Path.GetDirectoryName(pathToXml)))
                Directory.CreateDirectory(Path.GetDirectoryName(pathToXml));

            XmlDeSerializer.WriteXml(obj, pathToXml);

            Assert.IsTrue(File.Exists(pathToXml));

            var obj2 = XmlDeSerializer.LoadXml(pathToXml);

            Assert.IsNotNull(obj2);
            Assert.AreEqual(2, obj2.Packages.Count);

            Assert.IsTrue(pathToXml.Equals(obj2.FileName));
            Assert.AreEqual("testdata (testoutput\\Stringtable.xml)", obj2.NodeName);

            XmlDeSerializer.WriteXml(obj, pathToSaveXml);

        }

        [Test]
        public void VerifyThatLoadingFromFoldersWorks()
        {
            var projects = XmlDeSerializer.LoadXmlFolder("xmltestdata");

            Assert.IsNotNull(projects);
            Assert.AreEqual(3, projects.Count);

            Assert.IsTrue(projects[0].Name.Equals("testdata"));
            Assert.IsTrue(projects[1].Name.Equals("testdata2"));
            Assert.IsTrue(projects[2].Name.Equals("testdata3"));
        }
    }
}
