// --------------------------------------------------------------------------------------------------------------------
// <copyright file="StringTableEditorViewModel.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="StringTableEditorViewModel" /> class specifying the view model for the string table editor
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using StringForge.View;

namespace StringForge.ViewModel
{
    using Microsoft.WindowsAPICodePack.Dialogs;
    using ReactiveUI;
    using RHSStringTableTools;
    using RHSStringTableTools.Model;
    using System;
    using System.Collections.ObjectModel;
    using System.IO;

    /// <summary>
    /// The view model for the string table editor
    /// </summary>
    internal class StringTableEditorViewModel : ReactiveObject
    {
        private Key selectedKey;
        private ObservableCollection<Project> project;
        private ObservableCollection<Key> keys;
        private object selectedNode;

        /// <summary>
        /// Get or sets the selected key
        /// </summary>
        public Key SelectedKey
        {
            get { return this.selectedKey; }
            set { this.RaiseAndSetIfChanged(ref this.selectedKey, value); }
        }

        /// <summary>
        /// Get or sets the project collection
        /// </summary>
        public ObservableCollection<Project> Project
        {
            get { return this.project; }
            set { this.RaiseAndSetIfChanged(ref this.project, value); }
        }

        /// <summary>
        /// Get or sets the collectionof keys
        /// </summary>
        public ObservableCollection<Key> Keys
        {
            get { return this.keys; }
            set { this.RaiseAndSetIfChanged(ref this.keys, value); }
        }

        /// <summary>
        /// Get or sets the selected tree node
        /// </summary>
        public object SelectedNode
        {
            get { return selectedNode; }
            set { this.RaiseAndSetIfChanged(ref this.selectedNode, value); }
        }

        public ReactiveCommand<object> OpenCommand { get; protected set; }

        public ReactiveCommand<object> SaveCommand { get; protected set; }

        public ReactiveCommand<object> StringTableConvertCommand { get; protected set; }

        public StringTableEditorViewModel()
        {
            this.OpenCommand = ReactiveCommand.Create();
            this.OpenCommand.Subscribe(_ => this.OpenCommandExecute());

            this.StringTableConvertCommand = ReactiveCommand.Create();
            this.StringTableConvertCommand.Subscribe(_ => StringTableConvertCommandExecute());

            this.WhenAny(vm => vm.SelectedNode, vm => vm.Value != null).Subscribe(_ => this.RecomputeGridKeys());

            this.SetPropertis();
        }

        private void StringTableConvertCommandExecute()
        {
            var converterV = new StringTableConverterView();
            converterV.ShowDialog();
        }

        /// <summary>
        /// Recomputes the <see cref="Key"/> collection required by the grid based on the selected mode
        /// </summary>
        private void RecomputeGridKeys()
        {
            if (this.SelectedNode != null)
            {
                var item = this.SelectedNode;
                var collectionOfKeys = new ObservableCollection<Key>();

                if (item.GetType() == typeof(Project))
                {
                    foreach (var package in ((Project)item).Packages)
                    {
                        foreach (var container in package.Containers)
                        {
                            foreach (var key in container.Keys)
                            {
                                collectionOfKeys.Add(key);
                            }
                        }
                    }
                }
                else if (item.GetType() == typeof(Package))
                {
                    foreach (var container in ((Package)item).Containers)
                    {
                        foreach (var key in container.Keys)
                        {
                            collectionOfKeys.Add(key);
                        }
                    }
                }
                else if (item.GetType() == typeof(Container))
                {
                    foreach (var key in ((Container)item).Keys)
                    {
                        collectionOfKeys.Add(key);
                    }
                }
                else if (item.GetType() == typeof(Key))
                {
                    collectionOfKeys.Add((Key)item);
                }

                this.Keys = collectionOfKeys;
            }
        }

        /// <summary>
        /// Set the properties
        /// </summary>
        private void SetPropertis()
        {
            this.Project = new ObservableCollection<Project>();
        }

        /// <summary>
        /// Execute the open command
        /// </summary>
        private void OpenCommandExecute()
        {
            var dlg = new CommonOpenFileDialog();
            dlg.Filters.Add(new CommonFileDialogFilter("XML file", "*.xml"));
            dlg.DefaultFileName = "Stringtable.xml";

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok && File.Exists(dlg.FileName))
            {
                this.Project.Add(XmlDeSerializer.LoadXml(dlg.FileName));
            }
        }
    }
}