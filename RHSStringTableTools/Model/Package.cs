// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Package.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Package" /> class specifying the package container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;
using ReactiveUI;
using RHSStringTableTools.Annotations;

namespace RHSStringTableTools.Model
{
    using System.Collections.Generic;

    /// <summary>
    /// The package class. Used only for grouping.
    /// </summary>
    public class Package : ReactiveObject
    {
        private string name;

        /// <summary>
        /// Initializes a new instance of the <see cref="Package"/> class.
        /// </summary>
        public Package()
        {
            this.Containers = new ObservableCollection<Container>();
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
        /// Gets or sets the containers.
        /// </summary>
        [XmlElement("Container")]
        public ObservableCollection<Container> Containers { get; set; }
    }
}