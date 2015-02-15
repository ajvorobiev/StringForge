// --------------------------------------------------------------------------------------------------------------------
// <copyright file="StringTableConverterViewModel.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="StringTableConverterViewModel" /> view model for the converter
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.ViewModel
{
    using Microsoft.WindowsAPICodePack.Dialogs;
    using ReactiveUI;
    using RHSStringTableTools;
    using RHSStringTableTools.Model;
    using System;
    using System.IO;
    using System.Threading.Tasks;
    using System.Windows;
    using System.Windows.Input;

    /// <summary>
    /// The <see cref="StringTableConverterViewModel" /> view model for the converter
    /// </summary>
    internal class StringTableConverterViewModel : ReactiveObject
    {
        /// <summary>
        /// Backing field the source path
        /// </summary>
        private string sourcePath;

        /// <summary>
        /// Backing field for the destination name
        /// </summary>
        private string destinationPath;

        /// <summary>
        /// The selected source action
        /// </summary>
        private SourceAction selectedSourceAction;

        /// <summary>
        /// Backing fields to fill missing
        /// </summary>
        private bool fillMissing;

        /// <summary>
        /// The is progress visible
        /// </summary>
        private Visibility isProgressVisible;
        private bool isBusy;

        /// <summary>
        /// Gets or sets the source path
        /// </summary>
        public string SourcePath
        {
            get { return this.sourcePath; }
            set { this.RaiseAndSetIfChanged(ref this.sourcePath, value); }
        }

        /// <summary>
        /// Gets or sets the destination path
        /// </summary>
        public string DestinationPath
        {
            get { return this.destinationPath; }
            set { this.RaiseAndSetIfChanged(ref this.destinationPath, value); }
        }

        /// <summary>
        /// Gets or sets the selected source action
        /// </summary>
        public SourceAction SelectedSourceAction
        {
            get { return this.selectedSourceAction; }
            set { this.RaiseAndSetIfChanged(ref this.selectedSourceAction, value); }
        }

        /// <summary>
        /// Gets or sets the fill missing
        /// </summary>
        public bool FillMissing
        {
            get { return this.fillMissing; }
            set { this.RaiseAndSetIfChanged(ref this.fillMissing, value); }
        }

        /// <summary>
        /// Gets or sets whether the progress bar is visible
        /// </summary>
        public Visibility IsProgressVisible
        {
            get { return this.isProgressVisible; }
            set { this.RaiseAndSetIfChanged(ref this.isProgressVisible, value); }
        }

        /// <summary>
        /// Gets or sets whether the dialog is busy
        /// </summary>
        public bool IsBusy
        {
            get { return this.isBusy; }
            set { this.RaiseAndSetIfChanged(ref this.isBusy, value); }
        }

        public ReactiveCommand<object> BrowseSourceCommand { get; protected set; }

        public ReactiveCommand<object> BrowseDestinationCommand { get; protected set; }

        public ReactiveCommand<object> OkCommand { get; protected set; }

        public ReactiveCommand<object> CloseCommand { get; protected set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="StringTableConverterViewModel"/> class.
        /// </summary>
        public StringTableConverterViewModel()
        {
            // connect subscriptions
            this.BrowseSourceCommand = ReactiveCommand.Create();
            this.BrowseSourceCommand.Subscribe(_ => this.BrowseSourceExecute());

            this.BrowseDestinationCommand = ReactiveCommand.Create();
            this.BrowseDestinationCommand.Subscribe(_ => this.BrowseDestinationExecute());

            var canConvert = this.WhenAny(x => x.SourcePath, y => y.DestinationPath,
                (x, y) => !string.IsNullOrWhiteSpace(x.Value) & !string.IsNullOrWhiteSpace(y.Value));

            this.OkCommand = ReactiveCommand.Create(canConvert);
            this.OkCommand.Subscribe(_ => this.OkExecute());

            // set default properties
            this.SetProperties();
        }

        /// <summary>
        /// Execute the ok command
        /// </summary>
        private async void OkExecute()
        {
            // ask if the user wants to proceed if the selected source modifier is not nothing
            if (this.SelectedSourceAction != SourceAction.Nothing)
            {
                var dlg =
                        MessageBox.Show(
                            "You chose to modify the source. This is a unreversible action. Do you want to proceed?", "Warning",
                            MessageBoxButton.YesNo, MessageBoxImage.Exclamation);

                if (dlg != MessageBoxResult.Yes)
                    return;
            }

            this.isBusy = true;
            this.IsProgressVisible = Visibility.Visible;
            Mouse.OverrideCursor = Cursors.Wait;

            var prjct = await Task.Run(() => CsvParser.ParseProject(this.SourcePath, this.SelectedSourceAction, this.FillMissing));

            this.isBusy = false;
            this.IsProgressVisible = Visibility.Hidden;
            Mouse.OverrideCursor = null;

            // check for override
            if (File.Exists(this.DestinationPath))
            {
                var dlg =
                        MessageBox.Show(
                            "The selected destination file already exists. Do you want to proceed?", "Warning",
                            MessageBoxButton.YesNo, MessageBoxImage.Exclamation);

                if (dlg != MessageBoxResult.Yes)
                    return;
            }

            XmlDeSerializer.WriteXml(prjct, this.DestinationPath);
        }

        /// <summary>
        /// Executes the browse destination execute
        /// </summary>
        private void BrowseDestinationExecute()
        {
            var dlg = new CommonSaveFileDialog();
            dlg.Filters.Add(new CommonFileDialogFilter("XML file", "*.xml"));
            dlg.DefaultFileName = "Stringtable.xml";

            if (!string.IsNullOrWhiteSpace(this.SourcePath)) dlg.DefaultDirectory = this.SourcePath;

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok)
            {
                this.DestinationPath = dlg.FileName;
            }
        }

        /// <summary>
        /// Executes the browse command
        /// </summary>
        private void BrowseSourceExecute()
        {
            var dlg = new CommonOpenFileDialog();

            dlg.IsFolderPicker = true;

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok)
            {
                this.SourcePath = dlg.FileName;
            }
        }

        /// <summary>
        /// Sets the view model properties
        /// </summary>
        private void SetProperties()
        {
            this.SelectedSourceAction = SourceAction.Nothing;
            this.IsProgressVisible = Visibility.Hidden;
            this.IsBusy = false;
        }
    }
}