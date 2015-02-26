// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Key.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class specifying the stringtable key
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace RHSStringTableTools.Model
{
    using System;
    using System.Xml.Serialization;
    using ReactiveUI;
    using Services;

    /// <summary>
    /// The key model class.
    /// </summary>
    public class Key : ReactiveObject
    {
        /// <summary>
        /// Backing field for the <see cref="Russian"/> language.
        /// </summary>
        private string russian;

        /// <summary>
        /// The id.
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
        /// The german.
        /// </summary>
        private string german;

        /// <summary>
        /// Gets or sets the id.
        /// </summary>
        [XmlAttribute("ID")]
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
        /// Gets or sets the parent
        /// </summary>
        [XmlIgnore]
        public Container Parent { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="Key"/> class. 
        /// </summary>
        public Key()
        {
            this.WhenAnyValue(vm => vm.Russian).Subscribe(_ => this.Transliterate());
        }

        /// <summary>
        /// Calls on the <see cref="TranslitService"/> to transliterate the <see cref="Russian"/> string.
        /// </summary>
        private void Transliterate()
        {
            this.Russian = TranslitService.Singleton.Transliterate(this.Russian);
        }

        /// <summary>
        /// Gets the string based on the language string.
        /// </summary>
        /// <param name="language">
        /// The language.
        /// </param>
        /// <returns>
        /// The <see cref="string"/>.
        /// </returns>
        public string GetLanguage(string language)
        {
            return (string)this.GetType().GetProperty(language).GetValue(this);
        }

        /// <summary>
        /// Fills all empty values with english translation with english or original.
        /// </summary>
        public void FillEmptyKeysWithEnglishOrOriginal()
        {
            if (string.IsNullOrWhiteSpace(this.English) && string.IsNullOrWhiteSpace(this.Original))
            {
                // if stringtable doesnt have english or original then you cannot fill empty languages
                return;
            }

            string replacement;
            if (string.IsNullOrWhiteSpace(this.English))
            {
                replacement = this.Original;
                this.English = replacement;
            }
            else
            {
                replacement = this.English;
                this.Original = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.Czech))
            {
                this.Czech = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.French))
            {
                this.French = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.Spanish))
            {
                this.Spanish = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.Italian))
            {
                this.Italian = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.Polish))
            {
                this.Polish = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.Portuguese))
            {
                this.Portuguese = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.Russian))
            {
                this.Russian = replacement;
            }

            if (string.IsNullOrWhiteSpace(this.German))
            {
                this.German = replacement;
            }
        }

        /// <summary>
        /// Fills the original key.
        /// </summary>
        public void FillOriginalKeyWithEnglish()
        {
            if (string.IsNullOrWhiteSpace(this.Original))
            {
                this.Original = this.English;
            }
        }

        public void WipeAllExceptEnglishOrOriginal()
        {
            var replacement = string.Empty;

            this.Czech = replacement;

            this.French = replacement;

            this.Spanish = replacement;

            this.Italian = replacement;

            this.Polish = replacement;

            this.Portuguese = replacement;

            this.Russian = replacement;

            this.German = replacement;
        }
    }
}