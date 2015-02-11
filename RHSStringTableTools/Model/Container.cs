// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Container.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Container" /> class specifying the container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.Collections.ObjectModel;
using System.Xml.Serialization;
using ReactiveUI;

namespace RHSStringTableTools.Model
{
    using System.Collections.Generic;

    /// <summary>
    /// The container class. Used for grouping.
    /// </summary>
    public class Container : ReactiveObject
    {
        private string name;

        /// <summary>
        /// Initializes a new instance of the <see cref="Container"/> class.
        /// </summary>
        public Container()
        {
            this.Keys = new ObservableCollection<Key>();
        }

        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        [XmlAttribute("name")]
        public string Name
        {
            get { return name; }
            set { this.RaiseAndSetIfChanged(ref this.name, value); }
        }

        /// <summary>
        /// Gets or sets the keys.
        /// </summary>
        [XmlElement("Key")]
        public ObservableCollection<Key> Keys { get; set; }
    }
}