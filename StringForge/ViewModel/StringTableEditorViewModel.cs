// --------------------------------------------------------------------------------------------------------------------
// <copyright file="StringTableEditorViewModel.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="StringTableEditorViewModel" /> class specifying the view model for the string table editor
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.ComponentModel;

namespace StringForge.ViewModel
{
    using Microsoft.WindowsAPICodePack.Dialogs;
    using ReactiveUI;
    using RHSStringTableTools;
    using RHSStringTableTools.Model;
    using StringForge.Model;
    using StringForge.View;
    using System;
    using System.Collections.Generic;
    using System.Collections.ObjectModel;
    using System.IO;
    using System.Reflection;
    using System.Threading.Tasks;
    using System.Windows;
    using System.Windows.Controls;

    /// <summary>
    /// The view model for the string table editor
    /// </summary>
    internal class StringTableEditorViewModel : ReactiveObject
    {
        private Key selectedKey;
        private ObservableCollection<Project> project;
        private ObservableCollection<Key> keys;
        private object selectedNode;
        private ObservableCollection<IViolation> violations;

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
            get { return this.selectedNode; }
            set { this.RaiseAndSetIfChanged(ref this.selectedNode, value); }
        }

        /// <summary>
        /// Gets or sets the selected violation.
        /// </summary>
        public IViolation SelectedViolation
        {
            get { return this.selectedViolation; }
            set { this.RaiseAndSetIfChanged(ref this.selectedViolation, value); }
        }

        /// <summary>
        /// Gets or sets the tree.
        /// </summary>
        public TreeView Tree { get; set; }

        public ReactiveCommand<object> OpenCommand { get; protected set; }

        public ReactiveCommand<object> OpenFolderCommand { get; protected set; }

        public ReactiveCommand<object> SaveCommand { get; protected set; }

        public ReactiveCommand<object> SaveAsCommand { get; protected set; }

        public ReactiveCommand<object> StringTableConvertCommand { get; protected set; }

        public ReactiveCommand<object> FillMissingCommand { get; protected set; }

        public ReactiveCommand<object> AboutCommand { get; protected set; }

        public ReactiveCommand<object> UnloadProjectCommand { get; protected set; }

        public ReactiveCommand<object> FillMissingFromLanguageCommand { get; protected set; }

        public ReactiveCommand<object> FindInTreeCommand { get; protected set; }

        public ReactiveCommand<object> EditProjectCommand { get; protected set; }

        public ReactiveCommand<object> AddPackageCommand { get; protected set; }

        public ReactiveCommand<object> EditPackageCommand { get; protected set; }

        public ReactiveCommand<object> RemovePackageCommand { get; protected set; }

        public ReactiveCommand<object> AddContainerCommand { get; protected set; }

        public ReactiveCommand<object> EditContainerCommand { get; protected set; }

        public ReactiveCommand<object> RemoveContainerCommand { get; protected set; }

        public ReactiveCommand<object> AddKeyCommand { get; protected set; }

        public ReactiveCommand<object> DuplicateKeyCommand { get; protected set; }

        public ReactiveCommand<object> RemoveKeyCommand { get; protected set; }

        /// <summary>
        /// Gets the window title.
        /// </summary>
        public string WindowTitle
        {
            get { return string.Format("StringForge v{0}", Assembly.GetEntryAssembly().GetName().Version.ToString()); }
        }

        /// <summary>
        /// Gets or sets the violations.
        /// </summary>
        public ObservableCollection<IViolation> Violations
        {
            get { return violations; }
            set { this.RaiseAndSetIfChanged(ref this.violations, value); }
        }

        /// <summary>
        /// Backing field for the violations background worker
        /// </summary>
        private BackgroundWorker violationsBackgroundWorker;

        /// <summary>
        /// Backing field for selected violation
        /// </summary>
        private IViolation selectedViolation;

        /// <summary>
        /// Initializes a new instance of the <see cref="StringTableEditorViewModel"/> class.
        /// </summary>
        public StringTableEditorViewModel()
        {
            violationsBackgroundWorker = new BackgroundWorker();
            violationsBackgroundWorker.WorkerSupportsCancellation = true;
            violationsBackgroundWorker.WorkerReportsProgress = true;
            violationsBackgroundWorker.DoWork += violationsBackgroundWorker_DoWork;
            violationsBackgroundWorker.RunWorkerCompleted += violationsBackgroundWorker_RunWorkerCompleted;

            this.Violations = new ObservableCollection<IViolation>();

            this.AboutCommand = ReactiveCommand.Create();
            this.AboutCommand.Subscribe(_ =>
            {
                var aboutV = new AboutView();
                aboutV.ShowDialog();
            });

            this.UnloadProjectCommand = ReactiveCommand.Create();
            this.UnloadProjectCommand.Subscribe(_ => this.UnloadProjectCommandExecute());

            this.OpenCommand = ReactiveCommand.Create();
            this.OpenCommand.Subscribe(_ => this.OpenCommandExecute());
            this.OpenFolderCommand = ReactiveCommand.Create();
            this.OpenFolderCommand.Subscribe(_ => this.OpenFolderCommandExecute());

            var canSave = this.WhenAny(x => x.Project, x => x.Value.Count >= 1);
            this.SaveCommand = ReactiveCommand.Create(canSave);
            this.SaveCommand.Subscribe(_ => this.QuickSaveCommandExecute());

            var canSaveAs = this.WhenAny(x => x.Project, x => x.Value.Count == 1);
            this.SaveAsCommand = ReactiveCommand.Create(canSaveAs);
            this.SaveAsCommand.Subscribe(_ => this.SaveAsCommandExecute());

            this.StringTableConvertCommand = ReactiveCommand.Create();
            this.StringTableConvertCommand.Subscribe(_ => StringTableConvertCommandExecute());

            var canFill = this.WhenAny(x => x.Keys, x => x.Value.Count > 0);
            this.FillMissingCommand = ReactiveCommand.Create(canFill);
            this.FillMissingCommand.Subscribe(_ => FillMissingInSelectionCommandExecute());

            var canFindInTree = this.WhenAny(x => x.SelectedKey, x => x.Value != null);
            this.FindInTreeCommand = ReactiveCommand.Create(canFindInTree);
            this.FindInTreeCommand.Subscribe(_ =>
            {
                this.SelectedNode = this.SelectedKey;
            });

            this.WhenAny(vm => vm.SelectedNode, vm => vm.Value != null).Subscribe(async _ =>
            {
                await Task.Run(() => this.RecomputeGridKeys());
                this.RunViolationsCheck();
            });

            // display the violation keys
            this.WhenAny(vm => vm.SelectedViolation, vm => vm.Value != null).Subscribe(async _ =>
            {
                if (this.SelectedViolation != null)
                {
                    this.Keys = this.SelectedViolation.Keys;
                }
            });

            this.EditProjectCommand = ReactiveCommand.Create();
            this.EditProjectCommand.Subscribe(_ => this.ExecuteEditProjectCommand());

            this.AddPackageCommand = ReactiveCommand.Create();
            this.AddPackageCommand.Subscribe(_ => this.ExecuteAddPackageCommand());

            this.EditPackageCommand = ReactiveCommand.Create();
            this.EditPackageCommand.Subscribe(_ => this.ExecuteEditPackageCommand());

            this.RemovePackageCommand = ReactiveCommand.Create();
            this.RemovePackageCommand.Subscribe(_ => this.ExecuteRemovePackageCommand());

            this.AddContainerCommand = ReactiveCommand.Create();
            this.AddContainerCommand.Subscribe(_ => this.ExecuteAddContainerCommand());

            this.EditContainerCommand = ReactiveCommand.Create();
            this.EditContainerCommand.Subscribe(_ => this.ExecuteEditContainerCommand());

            this.RemoveContainerCommand = ReactiveCommand.Create();
            this.RemoveContainerCommand.Subscribe(_ => this.ExecuteRemoveContainerCommand());

            this.AddKeyCommand = ReactiveCommand.Create();
            this.AddKeyCommand.Subscribe(_ => this.ExecuteAddKeyCommand());

            this.DuplicateKeyCommand = ReactiveCommand.Create();
            this.DuplicateKeyCommand.Subscribe(_ => this.ExecuteDuplicateKeyCommand());

            this.RemoveKeyCommand = ReactiveCommand.Create();
            this.RemoveKeyCommand.Subscribe(_ => this.ExecuteRemoveKeyCommand());

            this.SetPropertis();
        }

        private void RunViolationsCheck()
        {
            this.violationsBackgroundWorker.RunWorkerAsync(this.Project);
        }

        private void violationsBackgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            BackgroundWorker worker = sender as BackgroundWorker;

            var violationsList = new ObservableCollection<IViolation>();
            var keyList = new Dictionary<string, Key>();

            foreach (var project in (ObservableCollection<Project>)e.Argument)
            {
                if ((worker.CancellationPending == true))
                {
                    e.Cancel = true;
                    break;
                }
                else
                {
                    foreach (var package in project.Packages)
                    {
                        foreach (var container in package.Containers)
                        {
                            foreach (var key in container.Keys)
                            {
                                try
                                {
                                    keyList.Add(key.Id, key);
                                }
                                catch (Exception ex)
                                {
                                    // create the violation with the two keys
                                    violationsList.Add(new DuplicateKeyViolation(new List<Key>() { key, keyList[key.Id] }));

                                    // remove the key to stop it causing the violation and move on
                                    keyList.Remove(key.Id);
                                }
                            }
                        }
                    }
                }
            }

            e.Result = violationsList;
        }

        /// <summary>
        /// Handles the RunWorkerCompleted event of the violationsBackgroundWorker control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="RunWorkerCompletedEventArgs"/> instance containing the event data.</param>
        private void violationsBackgroundWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if ((e.Cancelled == true))
            {
            }
            else if (!(e.Error == null))
            {
            }
            else
            {
                this.Violations = (ObservableCollection<IViolation>)e.Result;
            }
        }

        /// <summary>
        /// Executes the remove key command.
        /// </summary>
        private void ExecuteRemoveKeyCommand()
        {
            if (MessageBox.Show("This is an irreversable command, are you sure?", "Delete", MessageBoxButton.YesNo, MessageBoxImage.Exclamation) == MessageBoxResult.Yes)
            {
                var key = this.SelectedNode as Key;

                if (key != null)
                {
                    key.Parent.Keys.Remove(key);
                    key = null;
                }
            }
        }

        /// <summary>
        /// Executes the duplicate key command.
        /// </summary>
        private void ExecuteDuplicateKeyCommand()
        {
            var original = this.SelectedNode as Key;

            if (original != null)
            {
                var parentContainer = original.Parent;

                var newKey = original.Clone();

                newKey.Id = string.Format("{0}_COPY", original.Id);

                parentContainer.Keys.Insert(parentContainer.Keys.IndexOf(original) + 1, newKey);
            }
        }

        /// <summary>
        /// Executes the add key command.
        /// </summary>
        private void ExecuteAddKeyCommand()
        {
            var newObject = new Key();
            var viewModel = new KeyEditViewModel(newObject, (Container)this.SelectedNode);

            var view = new KeyEditView { DataContext = viewModel };

            view.ShowDialog();
        }

        /// <summary>
        /// Executes the remove container command.
        /// </summary>
        private void ExecuteRemoveContainerCommand()
        {
            if (MessageBox.Show("This is an irreversable command, are you sure?", "Delete", MessageBoxButton.YesNo, MessageBoxImage.Exclamation) == MessageBoxResult.Yes)
            {
                var container = this.SelectedNode as Container;

                if (container != null)
                {
                    container.Parent.Containers.Remove(container);
                    container = null;
                }
            }
        }

        /// <summary>
        /// Executes the edit container command.
        /// </summary>
        private void ExecuteEditContainerCommand()
        {
            var viewModel = new ContainerEditViewModel((Container)this.SelectedNode);

            var view = new ContainerEditView { DataContext = viewModel };

            view.ShowDialog();
        }

        /// <summary>
        /// Executes the add container command.
        /// </summary>
        private void ExecuteAddContainerCommand()
        {
            var newObject = new Container();
            var viewModel = new ContainerEditViewModel(newObject, (Package)this.SelectedNode);

            var view = new ContainerEditView { DataContext = viewModel };

            view.ShowDialog();
        }

        /// <summary>
        /// Executes the remove package command.
        /// </summary>
        private void ExecuteRemovePackageCommand()
        {
            if (MessageBox.Show("This is an irreversable command, are you sure?", "Delete", MessageBoxButton.YesNo, MessageBoxImage.Exclamation) == MessageBoxResult.Yes)
            {
                var package = this.SelectedNode as Package;

                if (package != null)
                {
                    package.Parent.Packages.Remove(package);
                    package = null;
                }
            }
        }

        /// <summary>
        /// Executes the edit package command.
        /// </summary>
        private void ExecuteEditPackageCommand()
        {
            var viewModel = new PackageEditViewModel((Package)this.SelectedNode);

            var view = new PackageEditView { DataContext = viewModel };

            view.ShowDialog();
        }

        /// <summary>
        /// Executes the add package command.
        /// </summary>
        private void ExecuteAddPackageCommand()
        {
            var newObject = new Package();
            var viewModel = new PackageEditViewModel(newObject, (Project)this.SelectedNode);

            var view = new PackageEditView { DataContext = viewModel };

            view.ShowDialog();
        }

        /// <summary>
        /// Executes the edit project command.
        /// </summary>
        private void ExecuteEditProjectCommand()
        {
            var viewModel = new ProjectEditViewModel((Project)this.SelectedNode);

            var view = new ProjectEditView { DataContext = viewModel };

            view.ShowDialog();

            // recalculate node name based on new package name
            viewModel.Thing.RecalculateNodeName();
        }

        /// <summary>
        /// Execute an unload project command on selected note
        /// </summary>
        private void UnloadProjectCommandExecute()
        {
            if (this.SelectedNode != null && this.SelectedNode.GetType() == typeof(Project))
            {
                var dlg = MessageBox.Show("Would you like to save the project before unloading it?", "Warning",
                    MessageBoxButton.YesNoCancel, MessageBoxImage.Question);

                var selectedProject = (Project)this.SelectedNode;

                var projects = new ObservableCollection<Project>(this.Project);

                // canceling will return
                if (dlg == MessageBoxResult.Cancel) return;
                else if (dlg == MessageBoxResult.Yes)
                {
                    QuickSaveProject(selectedProject);
                }

                // remove the selected project
                projects.Remove(selectedProject);

                // force ui refresh
                this.Project = projects;
            }
        }

        /// <summary>
        /// Fills the missing keys in the entire collection of keys that is displayed in the grid.
        /// </summary>
        private async void FillMissingInSelectionCommandExecute()
        {
            await Task.Run(() =>
            {
                foreach (var key in this.Keys)
                {
                    key.FillEmptyKeysWithEnglishOrOriginal();
                }

                RecomputeGridKeys();
            });
        }

        /// <summary>
        /// Brings up the converter
        /// </summary>
        private void StringTableConvertCommandExecute()
        {
            var converterV = new StringTableConverterView();
            converterV.ShowDialog();
        }

        /// <summary>
        /// Recomputes the <see cref="Key"/> collection required by the grid based on the selected mode
        /// </summary>
        private async void RecomputeGridKeys()
        {
            if (this.SelectedNode != null)
            {
                var item = this.SelectedNode;

                var collectionOfKeys = new ObservableCollection<Key>();

                await Task.Run(() => ExtractKeyCollection(item, collectionOfKeys));

                this.Keys = collectionOfKeys;
            }
        }

        /// <summary>
        /// Extracts the collection of keys from the selected parent. Using shallow clones to prevent throwns on modified collection
        /// </summary>
        /// <param name="item">The slected item</param>
        /// <param name="collectionOfKeys">The collectio of keys to be filled</param>
        public static void ExtractKeyCollection(object item, ObservableCollection<Key> collectionOfKeys)
        {
            if (item.GetType() == typeof(Project))
            {
                foreach (var package in ((Project)item).Clone().Packages)
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
                foreach (var container in ((Package)item).Clone().Containers)
                {
                    foreach (var key in container.Keys)
                    {
                        collectionOfKeys.Add(key);
                    }
                }
            }
            else if (item.GetType() == typeof(Container))
            {
                foreach (var key in ((Container)item).Clone().Keys)
                {
                    collectionOfKeys.Add(key);
                }
            }
            else if (item.GetType() == typeof(Key))
            {
                collectionOfKeys.Add((Key)item);
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
            // clear previous
            var collection = new ObservableCollection<Project>();

            var dlg = new CommonOpenFileDialog();
            dlg.Filters.Add(new CommonFileDialogFilter("XML file", "*.xml"));
            dlg.DefaultFileName = "Stringtable.xml";

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok && File.Exists(dlg.FileName))
            {
                collection.Add(XmlDeSerializer.LoadXml(dlg.FileName));
            }

            this.Project = collection;
        }

        /// <summary>
        /// Execute the open folder command
        /// </summary>
        private void OpenFolderCommandExecute()
        {
            var dlg = new CommonOpenFileDialog();
            dlg.IsFolderPicker = true;

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok && Directory.Exists(dlg.FileName))
            {
                this.Project = XmlDeSerializer.LoadXmlFolder(dlg.FileName);
            }
        }

        /// <summary>
        /// Execute the quick save command
        /// </summary>
        private void QuickSaveCommandExecute()
        {
            if (this.Project.Count < 1) return;

            foreach (var prj in this.Project)
            {
                QuickSaveProject(prj);
            }
        }

        /// <summary>
        /// Quick save a single project
        /// </summary>
        /// <param name="prj">The project to save</param>
        private static void QuickSaveProject(Project prj)
        {
            if (!string.IsNullOrWhiteSpace(prj.FileName))
            {
                XmlDeSerializer.WriteXml(prj, prj.FileName);
            }
        }

        /// <summary>
        /// Execute the save as command
        /// </summary>
        private void SaveAsCommandExecute()
        {
            if (this.Project.Count != 1) return;

            var prjct = this.Project[0];

            var dlg = new CommonSaveFileDialog();
            dlg.DefaultFileName = "Stringtable.xml";

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok)
            {
                XmlDeSerializer.WriteXml(prjct, dlg.FileName);
            }
        }
    }
}