// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Project.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class specifying the project
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace RHSStringTableTools.Model
{
    using System.Collections.ObjectModel;
    using System.IO;
    using System.Xml.Serialization;
    using ReactiveUI;

    /// <summary>
    /// The project class.
    /// </summary>
    public class Project : ReactiveObject
    {
        /// <summary>
        /// Backing field for the <see cref="Name"/>
        /// </summary>
        private string name;

        /// <summary>
        /// Backing field for the <see cref="NodeName"/>
        /// </summary>
        private string nodeName;

        /// <summary>
        /// Initializes a new instance of the <see cref="Project"/> class.
        /// </summary>
        public Project()
        {
            this.Packages = new ObservableCollection<Package>();
        }

        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        [XmlAttribute("name")]
        public string Name
        {
            get { return this.name; }
            set { this.RaiseAndSetIfChanged(ref this.name, value); }
        }

        /// <summary>
        /// Gets or sets the packages.
        /// </summary>
        [XmlElement("Package")]
        public ObservableCollection<Package> Packages { get; set; }

        /// <summary>
        /// Gets or sets the file path to the xml that the project belongs to
        /// </summary>
        [XmlIgnore]
        public string FileName { get; set; }
        
        /// <summary>
        /// Gets or sets the node name.
        /// </summary>
        [XmlIgnore]
        public string NodeName
        {
            get { return this.nodeName; }
            set { this.RaiseAndSetIfChanged(ref this.nodeName, value); }
        }

        /// <summary>
        /// Creates a node name to be displayed in the tree
        /// </summary>
        public void RecalculateNodeName()
        {
            this.NodeName = string.Format("{0} ({1}\\{2})", this.Name, new DirectoryInfo(Path.GetDirectoryName(this.FileName)).Name, Path.GetFileName(this.FileName));
        }
    }
}