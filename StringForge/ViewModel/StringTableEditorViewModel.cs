// --------------------------------------------------------------------------------------------------------------------
// <copyright file="StringTableEditorViewModel.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class specifying the view model for the string table editor
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using StringForge.Model.Templates;

namespace StringForge.ViewModel
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.Collections.ObjectModel;
    using System.ComponentModel;
    using System.IO;
    using System.Linq;
    using System.Reflection;
    using System.Threading.Tasks;
    using System.Windows;
    using System.Windows.Controls;
    using GongSolutions.Wpf.DragDrop;
    using Microsoft.WindowsAPICodePack.Dialogs;
    using ReactiveUI;
    using RHSStringTableTools;
    using RHSStringTableTools.Model;
    using Model;
    using View;

    /// <summary>
    /// The view model for the string table editor
    /// </summary>
    internal class StringTableEditorViewModel : ReactiveObject, IDropTarget
    {
        /// <summary>
        /// The selected key.
        /// </summary>
        private Key selectedKey;

        /// <summary>
        /// The projects.
        /// </summary>
        private ObservableCollection<Project> projects;

        /// <summary>
        /// The keys.
        /// </summary>
        private ObservableCollection<Key> keys;

        /// <summary>
        /// The selected node.
        /// </summary>
        private object selectedNode;

        /// <summary>
        /// The violations.
        /// </summary>
        private ObservableCollection<IViolation> violations;

        /// <summary>
        /// Gets or sets the selected key.
        /// </summary>
        public Key SelectedKey
        {
            get { return this.selectedKey; }
            set { this.RaiseAndSetIfChanged(ref this.selectedKey, value); }
        }

        /// <summary>
        /// Gets or sets the projects.
        /// </summary>
        public ObservableCollection<Project> Projects
        {
            get { return this.projects; }
            set { this.RaiseAndSetIfChanged(ref this.projects, value); }
        }

        /// <summary>
        /// Gets or sets the keys.
        /// </summary>
        public ObservableCollection<Key> Keys
        {
            get { return this.keys; }
            set { this.RaiseAndSetIfChanged(ref this.keys, value); }
        }

        /// <summary>
        /// Gets or sets the selected node.
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

        /// <summary>
        /// Gets or sets the open single project command.
        /// </summary>
        public ReactiveCommand<object> OpenCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the open folder command.
        /// </summary>
        public ReactiveCommand<object> OpenFolderCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the save command.
        /// </summary>
        public ReactiveCommand<object> SaveCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the save as command.
        /// </summary>
        public ReactiveCommand<object> SaveAsCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the string table convert command.
        /// </summary>
        public ReactiveCommand<object> StringTableConvertCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the fill missing command.
        /// </summary>
        public ReactiveCommand<object> FillMissingCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the wipe command.
        /// </summary>
        public ReactiveCommand<object> WipeCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the about command.
        /// </summary>
        public ReactiveCommand<object> AboutCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the unload project command.
        /// </summary>
        public ReactiveCommand<object> UnloadProjectCommand { get; protected set; }

/*
        public ReactiveCommand<object> FillMissingFromLanguageCommand { get; protected set; }
*/

        /// <summary>
        /// Gets or sets the find in tree command.
        /// </summary>
        public ReactiveCommand<object> FindInTreeCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the edit project command.
        /// </summary>
        public ReactiveCommand<object> EditProjectCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the add package command.
        /// </summary>
        public ReactiveCommand<object> AddPackageCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the edit package command.
        /// </summary>
        public ReactiveCommand<object> EditPackageCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the remove package command.
        /// </summary>
        public ReactiveCommand<object> RemovePackageCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the add container command.
        /// </summary>
        public ReactiveCommand<object> AddContainerCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the edit container command.
        /// </summary>
        public ReactiveCommand<object> EditContainerCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the remove container command.
        /// </summary>
        public ReactiveCommand<object> RemoveContainerCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the add key command.
        /// </summary>
        public ReactiveCommand<object> AddKeyCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the duplicate key command.
        /// </summary>
        public ReactiveCommand<object> DuplicateKeyCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the remove key command.
        /// </summary>
        public ReactiveCommand<object> RemoveKeyCommand { get; protected set; }

        /// <summary>
        /// Initiates the templates window
        /// </summary>
        public ReactiveCommand<object> TemplatesCommand { get; protected set; }

        /// <summary>
        /// Gets the window title.
        /// </summary>
        public string WindowTitle
        {
            get { return string.Format("StringForge v{0}", Assembly.GetEntryAssembly().GetName().Version); }
        }

        /// <summary>
        /// Gets or sets the violations.
        /// </summary>
        public ObservableCollection<IViolation> Violations
        {
            get { return this.violations; }
            set { this.RaiseAndSetIfChanged(ref this.violations, value); }
        }


        /// <summary>
        /// Backing field for the violations background worker
        /// </summary>
        private readonly BackgroundWorker violationsBackgroundWorker;

        /// <summary>
        /// Backing field for selected violation
        /// </summary>
        private IViolation selectedViolation;

        /// <summary>
        /// Initializes a new instance of the <see cref="StringTableEditorViewModel"/> class.
        /// </summary>
        public StringTableEditorViewModel()
        {
            TemplateMaster.Instance.Load("templates.xml");

            this.violationsBackgroundWorker = new BackgroundWorker
            {
                WorkerSupportsCancellation = true,
                WorkerReportsProgress = true
            };

            this.violationsBackgroundWorker.DoWork += this.violationsBackgroundWorker_DoWork;
            this.violationsBackgroundWorker.RunWorkerCompleted += this.violationsBackgroundWorker_RunWorkerCompleted;

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

            var canSave = this.WhenAny(x => x.Projects, x => x.Value.Count >= 1);
            this.SaveCommand = ReactiveCommand.Create(canSave);
            this.SaveCommand.Subscribe(_ => this.QuickSaveCommandExecute());

            var canSaveAs = this.WhenAny(x => x.Projects, x => x.Value.Count == 1);
            this.SaveAsCommand = ReactiveCommand.Create(canSaveAs);
            this.SaveAsCommand.Subscribe(_ => this.SaveAsCommandExecute());

            this.StringTableConvertCommand = ReactiveCommand.Create();
            this.StringTableConvertCommand.Subscribe(_ => this.StringTableConvertCommandExecute());

            var canFill = this.WhenAny(x => x.Keys, x => x.Value.Count > 0);
            this.FillMissingCommand = ReactiveCommand.Create(canFill);
            this.FillMissingCommand.Subscribe(_ => this.FillMissingInSelectionCommandExecute());

            this.WipeCommand = ReactiveCommand.Create(canFill);
            this.WipeCommand.Subscribe(_ => this.WipeCommandExecute());

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
            this.WhenAny(vm => vm.SelectedViolation, vm => vm.Value != null).Subscribe(_ =>
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

            this.TemplatesCommand = ReactiveCommand.Create();
            this.TemplatesCommand.Subscribe(_ => this.ExecuteTemplatesCommand());

            this.SetPropertis();
        }

        private void ExecuteTemplatesCommand()
        {
            var templatesview = new TemplateView();
            templatesview.ShowDialog();
        }

        /// <summary>
        /// Runs a violations check
        /// </summary>
        private void RunViolationsCheck()
        {
            this.violationsBackgroundWorker.RunWorkerAsync(this.Projects);
        }

        /// <summary>
        /// The worker execution method.
        /// </summary>
        /// <param name="sender">
        /// The sender.
        /// </param>
        /// <param name="e">
        /// The arguments.
        /// </param>
        private void violationsBackgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            var worker = sender as BackgroundWorker;

            var violationsList = new ObservableCollection<IViolation>();
            var keyList = new Dictionary<string, Key>();

            foreach (var project in (ObservableCollection<Project>)e.Argument)
            {
                if (worker != null && worker.CancellationPending)
                {
                    e.Cancel = true;
                    break;
                }

                foreach (var key in from package in project.Packages from container in package.Containers from key in container.Keys select key)
                {
                    try
                    {
                        keyList.Add(key.Id, key);
                    }
                    catch (Exception)
                    {
                        // create the violation with the two keys
                        violationsList.Add(new DuplicateKeyViolation(new List<Key> { key, keyList[key.Id] }));

                        // remove the key to stop it causing the violation and move on
                        keyList.Remove(key.Id);
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
            if (e.Cancelled)
            {
            }
            else if (e.Error != null)
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
                var viewModel = new KeyEditViewModel(newKey, parentContainer, parentContainer.Keys.IndexOf(original));

                var view = new KeyEditView { DataContext = viewModel };

                view.ShowDialog();
            }
        }

        /// <summary>
        /// Executes the add key command.
        /// </summary>
        private void ExecuteAddKeyCommand()
        {
            var newObject = new Key();
            var viewModel = new KeyEditViewModel(newObject, (RHSStringTableTools.Model.Container)this.SelectedNode);

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
                var container = this.SelectedNode as RHSStringTableTools.Model.Container;

                if (container != null)
                {
                    container.Parent.Containers.Remove(container);
                }
            }
        }

        /// <summary>
        /// Executes the edit container command.
        /// </summary>
        private void ExecuteEditContainerCommand()
        {
            var viewModel = new ContainerEditViewModel((RHSStringTableTools.Model.Container)this.SelectedNode);

            var view = new ContainerEditView { DataContext = viewModel };

            view.ShowDialog();
        }

        /// <summary>
        /// Executes the add container command.
        /// </summary>
        private void ExecuteAddContainerCommand()
        {
            var newObject = new RHSStringTableTools.Model.Container();
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
                var dlg = MessageBox.Show("Would you like to save the project before unloading it?", "Warning", MessageBoxButton.YesNoCancel, MessageBoxImage.Question);

                var selectedProject = (Project)this.SelectedNode;

                var projectsCollection = new ObservableCollection<Project>(this.Projects);

                // canceling will return
                switch (dlg)
                {
                    case MessageBoxResult.Cancel:
                        return;
                    case MessageBoxResult.Yes:
                        QuickSaveProject(selectedProject);
                        break;
                }

                // remove the selected project
                projectsCollection.Remove(selectedProject);

                // force ui refresh
                this.Projects = projectsCollection;
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
        /// Wipe all languages except original and english
        /// </summary>
        private async void WipeCommandExecute()
        {
            await Task.Run(() =>
            {
                foreach (var key in this.Keys)
                {
                    key.WipeAllExceptEnglishOrOriginal();
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
        /// Re-computes the <see cref="Key"/> collection required by the grid based on the selected mode
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
        /// Extracts the collection of keys from the selected parent. Using shallow clones to prevent throws on modified collection
        /// </summary>
        /// <param name="item">The selected item</param>
        /// <param name="collectionOfKeys">The collection of keys to be filled</param>
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
            else if (item.GetType() == typeof(RHSStringTableTools.Model.Container))
            {
                foreach (var key in ((RHSStringTableTools.Model.Container)item).Clone().Keys)
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
            this.Projects = new ObservableCollection<Project>();
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

            this.Projects = collection;
        }

        /// <summary>
        /// Execute the open folder command
        /// </summary>
        private void OpenFolderCommandExecute()
        {
            var dlg = new CommonOpenFileDialog { IsFolderPicker = true };

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok && Directory.Exists(dlg.FileName))
            {
                this.Projects = XmlDeSerializer.LoadXmlFolder(dlg.FileName);
            }
        }

        /// <summary>
        /// Execute the quick save command
        /// </summary>
        private void QuickSaveCommandExecute()
        {
            if (this.Projects.Count < 1)
            {
                return;
            }

            foreach (var prj in this.Projects)
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
            if (this.Projects.Count != 1)
            {
                return;
            }

            var prjct = this.Projects[0];

            var dlg = new CommonSaveFileDialog { DefaultFileName = "Stringtable.xml" };

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok)
            {
                XmlDeSerializer.WriteXml(prjct, dlg.FileName);
            }
        }

        /// <summary>
        /// The drag over handling.
        /// </summary>
        /// <param name="dropInfo">
        /// The drop info.
        /// </param>
        public void DragOver(IDropInfo dropInfo)
        {
            if (dropInfo.Data is Key && dropInfo.TargetItem is RHSStringTableTools.Model.Container)
            {
                dropInfo.DropTargetAdorner = DropTargetAdorners.Highlight;
                dropInfo.Effects = DragDropEffects.Move;
            }
            else if (dropInfo.Data is Key && dropInfo.TargetItem is Key)
            {
                dropInfo.DropTargetAdorner = DropTargetAdorners.Insert;
                dropInfo.Effects = DragDropEffects.Move;
            }
            else if (dropInfo.Data is RHSStringTableTools.Model.Container && dropInfo.TargetItem is RHSStringTableTools.Model.Container)
            {
                dropInfo.DropTargetAdorner = DropTargetAdorners.Insert;
                dropInfo.Effects = DragDropEffects.Move;
            }
            else if (dropInfo.Data is RHSStringTableTools.Model.Container && dropInfo.TargetItem is Package)
            {
                dropInfo.DropTargetAdorner = DropTargetAdorners.Highlight;
                dropInfo.Effects = DragDropEffects.Move;
            }
            else if (dropInfo.Data is Package && dropInfo.TargetItem is Package)
            {
                dropInfo.DropTargetAdorner = DropTargetAdorners.Insert;
                dropInfo.Effects = DragDropEffects.Move;
            }
            else if (dropInfo.Data is Package && dropInfo.TargetItem is Project)
            {
                dropInfo.DropTargetAdorner = DropTargetAdorners.Highlight;
                dropInfo.Effects = DragDropEffects.Move;
            }
            else
            {
                dropInfo.Effects = DragDropEffects.None;
            }
        }

        /// <summary>
        /// The drop handler.
        /// </summary>
        /// <param name="dropInfo">
        /// The drop info.
        /// </param>
        public void Drop(IDropInfo dropInfo)
        {
            if (dropInfo.Data is Key && dropInfo.TargetItem is RHSStringTableTools.Model.Container)
            {
                var movingKey = dropInfo.Data as Key;
                var targetContainer = dropInfo.TargetItem as RHSStringTableTools.Model.Container;

                targetContainer.Keys.Add(movingKey);
                movingKey.Parent = targetContainer;

                ((IList)dropInfo.DragInfo.SourceCollection).Remove(movingKey);
            }
            else if (dropInfo.Data is Key && dropInfo.TargetItem is Key)
            {
                var movingKey = dropInfo.Data as Key;

                ((IList)dropInfo.TargetCollection).Insert(dropInfo.InsertIndex, movingKey);

                movingKey.Parent = ((Key)dropInfo.TargetItem).Parent;

                ((IList)dropInfo.DragInfo.SourceCollection).Remove(movingKey);
            }
            else if (dropInfo.Data is RHSStringTableTools.Model.Container && dropInfo.TargetItem is RHSStringTableTools.Model.Container)
            {
                var movingContainer = dropInfo.Data as RHSStringTableTools.Model.Container;

                ((IList)dropInfo.TargetCollection).Insert(dropInfo.InsertIndex, movingContainer);

                movingContainer.Parent = ((RHSStringTableTools.Model.Container)dropInfo.TargetItem).Parent;

                ((IList)dropInfo.DragInfo.SourceCollection).Remove(movingContainer);
            }
            else if (dropInfo.Data is RHSStringTableTools.Model.Container && dropInfo.TargetItem is Package)
            {
                var movingContainer = dropInfo.Data as RHSStringTableTools.Model.Container;
                var targetPackage = dropInfo.TargetItem as Package;

                targetPackage.Containers.Add(movingContainer);

                movingContainer.Parent = targetPackage;

                ((IList)dropInfo.DragInfo.SourceCollection).Remove(movingContainer);
            }
            else if (dropInfo.Data is Package && dropInfo.TargetItem is Package)
            {
                var movingPackage = dropInfo.Data as Package;

                ((IList)dropInfo.TargetCollection).Insert(dropInfo.InsertIndex, movingPackage);

                movingPackage.Parent = ((Package)dropInfo.TargetItem).Parent;

                ((IList)dropInfo.DragInfo.SourceCollection).Remove(movingPackage);
            }
            else if (dropInfo.Data is Package && dropInfo.TargetItem is Project)
            {
                var movingPackage = dropInfo.Data as Package;
                var targetProject = dropInfo.TargetItem as Project;

                targetProject.Packages.Add(movingPackage);

                movingPackage.Parent = targetProject;

                ((IList)dropInfo.DragInfo.SourceCollection).Remove(movingPackage);
            }
        }
    }
}