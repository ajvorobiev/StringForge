using System;
using System.Reactive.Linq;
using System.Windows;
using RHSStringTableTools.Model;

namespace StringForge.ViewModel
{
    using ReactiveUI;

    class KeyEditViewModel : EditViewModel
    {
        private string id;
        private string original;
        private string english;
        private string czech;
        private string french;
        private string spanish;
        private string italian;
        private string polish;
        private string portuguese;
        private string russian;
        private string german;
        private bool autoFill;
        private bool translit;

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
        /// Gets or sets whether the form is auto filling from <see cref="Original"/>
        /// </summary>
        public bool AutoFill
        {
            get { return this.autoFill; }
            set { this.RaiseAndSetIfChanged(ref this.autoFill, value); }
        }

        /// <summary>
        /// Gets or sets whether the russian key text is being transliterated in real time
        /// </summary>
        public bool Translit
        {
            get { return translit; }
            set { this.RaiseAndSetIfChanged(ref this.translit, value); }
        }

        /// <summary>
        /// Gets or sets the thing
        /// </summary>
        public Key Thing { get; set; }

        /// <summary>
        /// Gets or sets the parent of the thing
        /// </summary>
        public Container Parent { get; set; }

        public KeyEditViewModel(Key item, Container container)
        {
            this.Thing = item;
            this.Parent = container;

            var canOk = this.WhenAny(x => x.Id, y => y.Original, z => z.English, (x, y, z) => !string.IsNullOrWhiteSpace(x.Value) && !string.IsNullOrWhiteSpace(y.Value) && !string.IsNullOrWhiteSpace(z.Value));
            this.OkCommand = ReactiveCommand.Create(canOk);
            this.OkCommand.Subscribe(this.OkCommandExecute);


            this.WhenAnyValue(vm=>vm.Original).Subscribe(_=>this.FillLanguages());

            this.SetProperties();
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
        }

        /// <summary>
        /// Execute the ok command
        /// </summary>
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
                this.Parent.Keys.Add(this.Thing);
            }

            ((Window)window).Close();
        }
    }
}
