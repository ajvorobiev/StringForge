// --------------------------------------------------------------------------------------------------------------------
// <copyright file="ConfigScannerViewModel.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   Defines the ConfigScannerViewModel type.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using RHSStringTableTools.Model;
using StringForge.View;

namespace StringForge.ViewModel
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using ClassForge;
    using ClassForge.Model;
    using Microsoft.WindowsAPICodePack.Dialogs;
    using ReactiveUI;

    /// <summary>
    /// The config scanner view model.
    /// </summary>
    public class ConfigScannerViewModel : ReactiveObject
    {
        /// <summary>
        /// The model.
        /// </summary>
        private ClassForge.Model.Model model;

        /// <summary>
        /// The filter string.
        /// </summary>
        private string filterString;

        /// <summary>
        /// The path fed to the config parser, only folder
        /// </summary>
        private string configPath;

        /// <summary>
        /// The console text
        /// </summary>
        private string consoleText;

        /// <summary>
        /// Is the action busy
        /// </summary>
        private bool isBusy;

        /// <summary>
        /// The selected property
        /// </summary>
        private KeyValuePair<Property, Class> selectedProperty;

        /// <summary>
        /// The dictionary containing all the properties and their corresponding classes
        /// </summary>
        private Dictionary<Property, Class> allProperties;

        /// <summary>
        /// Gets or sets the array of property filter strings.
        /// </summary>
        public List<string> FilterArray { get; set; }
        
        /// <summary>
        /// Gets or sets all the properties that have been found in the model that match the filter and are not in a string table
        /// </summary>
        public Dictionary<Property, Class> AllProperties 
        { 
            get { return this.allProperties; }
            set { this.RaiseAndSetIfChanged(ref this.allProperties, value); }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ConfigScannerViewModel"/> class.
        /// </summary>
        public ConfigScannerViewModel()
        {
            this.FilterArray = new List<string>();
            this.FilterString = "displayName, descriptionShort";
#if DEBUG
            this.ConfigPath = "C:\\Alex\\StringForge\\StringForge.Test\\classtest\\rhsusf_c_weapons";
#endif
            this.InitializeCommands();
        }

        /// <summary>
        /// Initializes the reactive commands.
        /// </summary>
        private void InitializeCommands()
        {
            this.BrowseConfigCommand = ReactiveCommand.Create();
            this.BrowseConfigCommand.Subscribe(_ => this.BrowseConfigCommandExecute());

            var canScan = this.WhenAny(vm => vm.ConfigPath, vd => vd.IsBusy, (cp, ib) => !string.IsNullOrEmpty(cp.Value) && !ib.Value);

            this.ScanCommand = ReactiveCommand.Create(canScan);
            this.ScanCommand.Subscribe(_ => this.ScanCommandExecute());

            var canAdd = this.WhenAny(vm => vm.SelectedProperty, vp => vp.ParentViewModel.SelectedNode,
                (sp, sc) => sp != null && sc.Value is Container);

            this.AddCommand = ReactiveCommand.Create(canAdd);
            this.AddCommand.Subscribe(_ => this.AddCommandExecute());
        }

        /// <summary>
        /// Adds the property to the stringtable
        /// </summary>
        private void AddCommandExecute()
        {
            this.ConsoleWriteLine(string.Format("Adding {0} to the stringtable.", this.SelectedProperty.Key.Value));

            var newObject = new Key()
            {
                Id =
                    string.Format("STR_{0}_{1}", this.AllProperties[this.SelectedProperty.Key].Name.ToUpper(),
                        this.SelectedProperty.Key.Name.ToUpper()),
                Original = this.SelectedProperty.Key.Value,
                English = this.SelectedProperty.Key.Value
            };

            newObject.FillEmptyKeysWithEnglishOrOriginal();

            var viewModel = new KeyEditViewModel(newObject, (RHSStringTableTools.Model.Container)this.ParentViewModel.SelectedNode);

            var view = new KeyEditView { DataContext = viewModel };

            view.ShowDialog();
        }

        /// <summary>
        /// Scans the configs in the specified folder
        /// </summary>
        private void ScanCommandExecute()
        {
            this.ClearConsole();
            this.ConsoleWriteLine(string.Format("Starting parse of {0}. Give it a bit...", this.ConfigPath));
            
            this.GetModel(this.ConfigPath);
        }

        /// <summary>
        /// Clears the console.
        /// </summary>
        private void ClearConsole()
        {
            this.ConsoleText = string.Empty;
        }
        
        /// <summary>
        /// Writes the specified text the the console.
        /// </summary>
        /// <param name="line">
        /// The line.
        /// </param>
        private void ConsoleWriteLine(string line)
        {
            var sb = new StringBuilder(this.ConsoleText);
            this.ConsoleText = sb.AppendLine(line).ToString();
        }

        /// <summary>
        /// Add to the last line of the console
        /// </summary>
        /// <param name="line">The line to append.</param>
        private void ConsoleAppendToLine(string line)
        {
            var sb = new StringBuilder(this.ConsoleText);
            this.ConsoleText = sb.Append(" " + line).ToString();
        }

        /// <summary>
        /// The browse config command execute.
        /// </summary>
        private void BrowseConfigCommandExecute()
        {
            var dlg = new CommonOpenFileDialog { IsFolderPicker = true };

            if (dlg.ShowDialog() == CommonFileDialogResult.Ok && Directory.Exists(dlg.FileName))
            {
                this.ConfigPath = dlg.FileName;
            }
        }

        /// <summary>
        /// Gets or sets the parent view model.
        /// </summary>
        public StringTableEditorViewModel ParentViewModel { get; set; }

        /// <summary>
        /// Gets or sets the <see cref="Model"/>.
        /// </summary>
        public ClassForge.Model.Model Model 
        {
            get { return this.model; }
            set { this.RaiseAndSetIfChanged(ref this.model, value); }
        }

        /// <summary>
        /// Gets or sets the selected property
        /// </summary>
        public KeyValuePair<Property, Class> SelectedProperty
        {
            get { return this.selectedProperty; }
            set { this.RaiseAndSetIfChanged(ref this.selectedProperty, value); }
        }

        /// <summary>
        /// Gets or sets the filter string
        /// </summary>
        public string FilterString
        {
            get { return this.filterString; }
            set { this.RaiseAndSetIfChanged(ref this.filterString, value); }
        }

        /// <summary>
        /// Gets or sets the config path.
        /// </summary>
        public string ConfigPath
        {
            get { return this.configPath; }
            set { this.RaiseAndSetIfChanged(ref this.configPath, value); }
        }

        /// <summary>
        /// Gets or sets the console text
        /// </summary>
        public string ConsoleText
        {
            get { return this.consoleText; }
            set { this.RaiseAndSetIfChanged(ref this.consoleText, value); }
        }

        /// <summary>
        /// Gets or sets a value indicating whether is busy.
        /// </summary>
        public bool IsBusy
        {
            get { return this.isBusy; }
            set { this.RaiseAndSetIfChanged(ref this.isBusy, value); }
        }

        /// <summary>
        /// Gets the browse config command.
        /// </summary>
        public ReactiveCommand<object> BrowseConfigCommand { get; private set; } 

        /// <summary>
        /// Gets the scan command
        /// </summary>
        public ReactiveCommand<object> ScanCommand { get; private set; }

        /// <summary>
        /// Gets the add command
        /// </summary>
        public ReactiveCommand<object> AddCommand { get; private set; } 

        /// <summary>
        /// Gets the <see cref="Model"/> contained in a specified folder
        /// </summary>
        /// <param name="path">
        /// The path to the directory with configs.
        /// </param>
        /// <exception cref="ArgumentException">
        /// If the indicated folder is bogus.
        /// </exception>
        public async void GetModel(string path)
        {
            if (!Directory.Exists(path))
            {
                throw new ArgumentException("The indicated folder does not exist!", "path");
            }

            this.IsBusy = true;
            try
            {
                this.Model = await this.GetModelAsync(path);
                this.ConsoleWriteLine(string.Format("Finished parsing. Filtering..."));
                this.AllProperties = await this.FilterModel();
                this.ConsoleWriteLine(string.Format("Finished filtering, found {0} properties with no stringtable entry. Displaying Results...", this.AllProperties.Count));
                this.ConsoleWriteLine(string.Format("Done"));
            }
            catch (Exception ex)
            {
                this.ConsoleWriteLine(string.Format("Error parsing {0}: {1}", this.ConfigPath, ex.Message));
            }
            finally
            {
                this.IsBusy = false;
            }
        }

        /// <summary>
        /// Gets the model async.
        /// </summary>
        /// <param name="path">
        /// The path.
        /// </param>
        /// <returns>
        /// The <see cref="Task"/>.
        /// </returns>
        public Task<Model> GetModelAsync(string path)
        {
            var parser = new CfgSimpleParser();
            return Task.Run(() => parser.ParseDirectoryMerged(path));
        }

        /// <summary>
        /// Decomposes the filter string into the filter array
        /// </summary>
        public void DecomposeFilters()
        {
            if (string.IsNullOrWhiteSpace(this.FilterString))
            {
                // reset the array in any case
                this.FilterArray = new List<string>();
                return;
            }

            this.FilterArray = this.FilterString.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries).Select(f => f.Trim()).ToList();
        }

        /// <summary>
        /// Filters the whole <see cref="Model"/> for the selected <see cref="Property"/>s.
        /// </summary>
        /// <exception cref="NullReferenceException">
        /// If the model is null.
        /// </exception>
        /// <returns>
        /// The <see cref="Task"/> containing the properties.
        /// </returns>
        public Task<Dictionary<Property, Class>> FilterModel()
        {
            this.DecomposeFilters();

            if (this.Model == null)
            {
                throw new NullReferenceException("The Model is not set.");
            }
            
            return Task.Run(() => this.FilterModelAsync());
        }

        /// <summary>
        /// Filters the model asynchronously.
        /// </summary>
        /// <returns>
        /// The <see cref="List{T}"/> containing all properties.
        /// </returns>
        public Dictionary<Property, Class> FilterModelAsync()
        {
            var allProps = new Dictionary<Property, Class>();

            foreach (var c in this.Model.Classes)
            {
                this.FilterClass(c, ref allProps);
            }

            return allProps;
        }

        /// <summary>
        /// Filters a <see cref="Class"/> for the filter properties.
        /// </summary>
        /// <param name="c">
        /// The c.
        /// </param>
        /// <param name="allProps">
        /// The <see cref="List{T}"/> of all properties
        /// </param>
        private void FilterClass(Class c, ref Dictionary<Property, Class> allProps)
        {
            foreach (var property in c.Properties)
            {
                foreach (var filter in this.FilterArray)
                {
                    if (filter.ToLower().Equals(property.Name.ToLower()) && !property.Value.Contains("$"))
                    {
                        allProps.Add(property, c);
                    }
                }
            }

            foreach (var cc in c.Classes)
            {
                this.FilterClass(cc, ref allProps);
            }
        }
    }
}
