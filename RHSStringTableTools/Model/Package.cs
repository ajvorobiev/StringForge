// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Package.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Package" /> class specifying the package container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.Xml.Serialization;

namespace RHSStringTableTools.Model
{
    using System.Collections.Generic;

    /// <summary>
    /// The package class. Used only for grouping.
    /// </summary>
    public class Package
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Package"/> class.
        /// </summary>
        public Package()
        {
            this.Containers = new List<Container>();
        }

        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        [XmlAttribute("name")]
        public string Name { get; set; }

        /// <summary>
        /// Gets or sets the containers.
        /// </summary>
        [XmlElement("Container")]
        public List<Container> Containers { get; set; }
    }
}