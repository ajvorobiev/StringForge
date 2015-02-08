// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Project.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Project" /> class specifying the project
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.IO;

namespace RHSStringTableTools.Model
{
    using System.Collections.Generic;
    using System.Xml.Serialization;

    /// <summary>
    /// The project class.
    /// </summary>
    public class Project
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Project"/> class.
        /// </summary>
        public Project()
        {
            this.Packages = new List<Package>();
        }

        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        [XmlAttribute("name")]
        public string Name { get; set; }

        /// <summary>
        /// Gets or sets the packages.
        /// </summary>
        [XmlElement("Package")]
        public List<Package> Packages { get; set; }

        /// <summary>
        /// Gets or sets the filepath to the xml that the project belongs to
        /// </summary>
        [XmlIgnore]
        public string FileName { get; set; }

        /// <summary>
        /// Gets the short path of the file
        /// </summary>
        [XmlIgnore]
        public string NodeName
        {
            get { return GetNodeName(); }
        }

        /// <summary>
        /// Creates a node name to be displayed in the tree
        /// </summary>
        /// <returns>A node name suitable for a tree.</returns>
        public string GetNodeName()
        {
            return string.Format("{0} ({1}\\{2})", this.Name, new DirectoryInfo(Path.GetDirectoryName(this.FileName)).Name, Path.GetFileName(this.FileName));
        }
    }
}