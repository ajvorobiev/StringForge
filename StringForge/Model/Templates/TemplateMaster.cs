// --------------------------------------------------------------------------------------------------------------------
// <copyright file="TemplateMaster.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The master collection holder
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.IO;
using System.Xml.Serialization;
using RHSStringTableTools.Model;

namespace StringForge.Model.Templates
{
    using ReactiveUI;
    using System.Collections.ObjectModel;

    /// <summary>
    /// The key id template
    /// </summary>
    public sealed class TemplateMaster : ReactiveObject
    {
        /// <summary>
        /// The instance
        /// </summary>
        private static TemplateMaster instance = null;

        /// <summary>
        /// The padlock
        /// </summary>
        private static readonly object padlock = new object();

        private bool loaded = false; 

        /// <summary>
        /// Backing field for key templates
        /// </summary>
        private ObservableCollection<KeyTemplate> keyTemplates;

        /// <summary>
        /// Gets or sets the templates list
        /// </summary>
        public ObservableCollection<KeyTemplate> KeyTemplates
        {
            get { return this.keyTemplates; }
            set { this.RaiseAndSetIfChanged(ref this.keyTemplates, value); }
        }

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <value>
        /// The instance.
        /// </value>
        public static TemplateMaster Instance
        {
            get
            {
                lock (padlock)
                {
                    if (instance == null)
                    {
                        instance = new TemplateMaster();
                    }
                    return instance;
                }
            }
        }

        /// <summary>
        /// Prevents a default instance of the <see cref="TemplateMaster"/> class from being created.
        /// </summary>
        TemplateMaster()
        {
            this.KeyTemplates = new ObservableCollection<KeyTemplate>();
        }

        /// <summary>
        /// Saves this instance.
        /// </summary>
        public void Save()
        {
            // remove default namespace information
            var ns = new XmlSerializerNamespaces();
            ns.Add("", "");

            var serializer = new XmlSerializer(typeof(TemplateMaster));
            using (TextWriter writer = new StreamWriter("templates.xml"))
            {
                serializer.Serialize(writer, this, ns);
            }
        }

        /// <summary>
        /// Loads the specified path.
        /// </summary>
        /// <param name="path">The path.</param>
        public void Load(string path)
        {
            if (File.Exists(path))
            {
                var deserializer = new XmlSerializer(typeof(TemplateMaster));
                TextReader reader = new StreamReader(path);

                object obj = deserializer.Deserialize(reader);
                var xmlData = (TemplateMaster)obj;

                reader.Close();

                this.KeyTemplates = xmlData.KeyTemplates;
                this.loaded = true;
            }
        }

    }
}