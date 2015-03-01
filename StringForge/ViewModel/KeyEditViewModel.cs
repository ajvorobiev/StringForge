// --------------------------------------------------------------------------------------------------------------------
// <copyright file="KeyEditViewModel.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  viewmodel for the keys winddow
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using StringForge.Model.Templates;
using System.Collections.ObjectModel;
using System.Linq;

namespace StringForge.ViewModel
{
    using ReactiveUI;
    using RHSStringTableTools.Model;
    using RHSStringTableTools.Services;
    using System;
    using System.Windows;
    using System.Windows.Forms;

    /// <summary>
    /// The <see cref="KeyEditViewModel" /> view model for the keys window
    /// </summary>
    public class KeyEditViewModel : EditViewModel
    {
        /// <summary>
        /// Backing fields fro the languages
        /// </summary>
        private string id;

        /// <summary>
        /// The original.
        /// </summary>
        private string original;

        /// <summary>
        /// The english.
        /// </summary>
        private string english;

        /// <summary>
        /// The czech.
        /// </summary>
        private string czech;

        /// <summary>
        /// The french.
        /// </summary>
        private string french;

        /// <summary>
        /// The spanish.
        /// </summary>
        private string spanish;

        /// <summary>
        /// The italian.
        /// </summary>
        private string italian;

        /// <summary>
        /// The polish.
        /// </summary>
        private string polish;

        /// <summary>
        /// The portuguese.
        /// </summary>
        private string portuguese;

        /// <summary>
        /// The russian.
        /// </summary>
        private string russian;

        /// <summary>
        /// The german.
        /// </summary>
        private string german;

        /// <summary>
        /// The auto fill.
        /// </summary>
        private bool autoFill;

        /// <summary>
        /// The transliteration.
        /// </summary>
        private bool translit;

        private KeyTemplate selectedTemplate;

        /// <summary>
        /// Gets or sets the identifier.
        /// </summary>
        public string Id
        {
            get { return this.id; }
            set { this.RaiseAndSetIfChanged(ref this.id, value); }
        }

        /// <summary>
        /// Gets or sets the original language (default).
        /// </summary>
        public string Original
        {
            get { return this.original; }
            set { this.RaiseAndSetIfChanged(ref this.original, value); }
        }

        /// <summary>
        /// Gets or sets the english language.
        /// </summary>
        public string English
        {
            get { return this.english; }
            set { this.RaiseAndSetIfChanged(ref this.english, value); }
        }

        /// <summary>
        /// Gets or sets the czech language.
        /// </summary>
        public string Czech
        {
            get { return this.czech; }
            set { this.RaiseAndSetIfChanged(ref this.czech, value); }
        }

        /// <summary>
        /// Gets or sets the french language.
        /// </summary>
        public string French
        {
            get { return this.french; }
            set { this.RaiseAndSetIfChanged(ref this.french, value); }
        }

        /// <summary>
        /// Gets or sets the spanish language.
        /// </summary>
        public string Spanish
        {
            get { return this.spanish; }
            set { this.RaiseAndSetIfChanged(ref this.spanish, value); }
        }

        /// <summary>
        /// Gets or sets the italian language.
        /// </summary>
        public string Italian
        {
            get { return this.italian; }
            set { this.RaiseAndSetIfChanged(ref this.italian, value); }
        }

        /// <summary>
        /// Gets or sets the polish language.
        /// </summary>
        public string Polish
        {
            get { return this.polish; }
            set { this.RaiseAndSetIfChanged(ref this.polish, value); }
        }

        /// <summary>
        /// Gets or sets the portuguese language.
        /// </summary>
        public string Portuguese
        {
            get { return this.portuguese; }
            set { this.RaiseAndSetIfChanged(ref this.portuguese, value); }
        }

        /// <summary>
        /// Gets or sets the russian language.
        /// </summary>
        public string Russian
        {
            get { return this.russian; }
            set { this.RaiseAndSetIfChanged(ref this.russian, value); }
        }

        /// <summary>
        /// Gets or sets the german language.
        /// </summary>
        public string German
        {
            get { return this.german; }
            set { this.RaiseAndSetIfChanged(ref this.german, value); }
        }

        /// <summary>
        /// Gets or sets a value indicating whether auto fill.
        /// </summary>
        public bool AutoFill
        {
            get { return this.autoFill; }
            set { this.RaiseAndSetIfChanged(ref this.autoFill, value); }
        }

        /// <summary>
        /// Gets or sets a value indicating whether transliteration is enabled.
        /// </summary>
        public bool Translit
        {
            get { return this.translit; }
            set { this.RaiseAndSetIfChanged(ref this.translit, value); }
        }

        /// <summary>
        /// Gets or sets the list of templates
        /// </summary>
        public ObservableCollection<KeyTemplate> Templates { get; set; }

        /// <summary>
        /// Gets or sets the selected template
        /// </summary>
        public KeyTemplate SelectedTemplate
        {
            get { return this.selectedTemplate; }
            set { this.RaiseAndSetIfChanged(ref this.selectedTemplate, value); }
        }

        /// <summary>
        /// Gets or sets the thing
        /// </summary>
        public Key Thing { get; set; }

        /// <summary>
        /// Gets or sets the parent of the thing
        /// </summary>
        public Container Parent { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="KeyEditViewModel"/> class.
        /// </summary>
        /// <param name="item">
        /// The item.
        /// </param>
        /// <param name="container">
        /// The container.
        /// </param>
        /// <param name="position">
        /// The position.
        /// </param>
        public KeyEditViewModel(Key item, Container container = null, int position = -1)
        {
            this.Templates = TemplateMaster.Instance.KeyTemplates;

            this.Thing = item;
            this.Thing.Parent = container;
            this.Parent = container;
            this.InsertAfter = position;

            var canOk = this.WhenAny(x => x.Id, y => y.Original, z => z.English, (x, y, z) => !string.IsNullOrWhiteSpace(x.Value) && !string.IsNullOrWhiteSpace(y.Value) && !string.IsNullOrWhiteSpace(z.Value));
            this.OkCommand = ReactiveCommand.Create(canOk);
            this.OkCommand.Subscribe(this.OkCommandExecute);

            this.WhenAnyValue(vm => vm.Original).Subscribe(_ => this.FillLanguages());
            this.WhenAnyValue(vm => vm.Russian).Subscribe(_ => this.Transliterate());
            this.WhenAny(vm => vm.SelectedTemplate, vm => vm.Value != null).Subscribe(_ => this.ApplyTemplate());

            this.SetProperties();
        }

        /// <summary>
        /// Applies the template to the string id
        /// </summary>
        private void ApplyTemplate()
        {
            if (this.SelectedTemplate != null)
            {
                this.Id = this.SelectedTemplate.Template;
            }
        }

        /// <summary>
        /// Gets or sets the index to insert after in the <see cref="Keys"/> collection of the <see cref="Container"/>
        /// </summary>
        public int InsertAfter { get; set; }

        /// <summary>
        /// Transliterates this instance.
        /// </summary>
        private void Transliterate()
        {
            if (this.Translit)
            {
                this.Russian = TranslitService.Singleton.Transliterate(this.Russian);
            }
        }

        /// <summary>
        /// Auto fills the languages from <see cref="Original"/>
        /// </summary>
        private void FillLanguages()
        {
            if (this.AutoFill)
            {
                this.English = this.Original;
                this.Czech = this.Original;
                this.French = this.Original;
                this.Spanish = this.Original;
                this.Italian = this.Original;
                this.Polish = this.Original;
                this.Portuguese = this.Original;
                this.Russian = this.Original;
                this.German = this.Original;
            }
        }

        /// <summary>
        /// Set the properties
        /// </summary>
        private void SetProperties()
        {
            this.Id = this.Thing.Id;
            this.Original = this.Thing.Original;
            this.English = this.Thing.English;
            this.Czech = this.Thing.Czech;
            this.French = this.Thing.French;
            this.Spanish = this.Thing.Spanish;
            this.Italian = this.Thing.Italian;
            this.Polish = this.Thing.Polish;
            this.Portuguese = this.Thing.Portuguese;
            this.Russian = this.Thing.Russian;
            this.German = this.Thing.German;

            this.AutoFill = true;
            this.Translit = true;

            if (string.IsNullOrWhiteSpace(this.Id))
            {
                this.SelectedTemplate = this.Templates.FirstOrDefault();
            }

        }

        /// <summary>
        /// Execute the ok command
        /// </summary>
        /// <param name="window">
        /// The window.
        /// </param>
        private void OkCommandExecute(object window)
        {
            this.Thing.Id = this.Id;
            this.Thing.Original = this.Original;
            this.Thing.English = this.English;
            this.Thing.Czech = this.Czech;
            this.Thing.French = this.French;
            this.Thing.Spanish = this.Spanish;
            this.Thing.Italian = this.Italian;
            this.Thing.Polish = this.Polish;
            this.Thing.Portuguese = this.Portuguese;
            this.Thing.Russian = this.Russian;
            this.Thing.German = this.German;

            // add the new container to the package at the very end
            if (this.Parent != null)
            {
                if (this.InsertAfter == -1)
                {
                    this.Parent.Keys.Add(this.Thing);
                }
                else
                {
                    this.Parent.Keys.Insert(this.InsertAfter + 1, this.Thing);
                }
            }

            ((Window)window).Close();
        }
    }
}