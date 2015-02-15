// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Package.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Package" /> class specifying the package container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace RHSStringTableTools.Model
{
    using ReactiveUI;
    using System.Collections.ObjectModel;
    using System.Xml.Serialization;

    /// <summary>
    /// The package class. Used only for grouping.
    /// </summary>
    public class Package : ReactiveObject
    {
        /// <summary>
        /// Backing field for the <see cref="Name"/>
        /// </summary>
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

        /// <summary>
        /// Gets or sets the parent
        /// </summary>
        [XmlIgnore]
        public Project Parent { get; set; }
    }
}