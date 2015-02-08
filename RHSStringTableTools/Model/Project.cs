// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Project.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Project" /> class specifying the project
// </summary>
// --------------------------------------------------------------------------------------------------------------------

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
    }
}