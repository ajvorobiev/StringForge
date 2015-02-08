// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Container.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Container" /> class specifying the container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.Xml.Serialization;

namespace RHSStringTableTools.Model
{
    using System.Collections.Generic;

    /// <summary>
    /// The container class. Used for grouping.
    /// </summary>
    public class Container
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Container"/> class.
        /// </summary>
        public Container()
        {
            this.Keys = new List<Key>();
        }

        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        [XmlAttribute("name")]
        public string Name { get; set; }

        /// <summary>
        /// Gets or sets the keys.
        /// </summary>
        [XmlElement("Key")]
        public List<Key> Keys { get; set; }
    }
}