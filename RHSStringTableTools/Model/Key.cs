// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Key.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class specifying the stringtable key
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.ComponentModel;

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
        /// The Korean.
        /// </summary>
        private string korean;

        /// <summary>
        /// The Japanese.
        /// </summary>
        private string japanese;

        /// <summary>
        /// The Chinese.
        /// </summary>
        private string chinese;

        /// <summary>
        /// The Simplified Chinese.
        /// </summary>
        private string chinesesimp;

        /// <summary>
        /// The Turkish.
        /// </summary>
        private string turkish;

        /// <summary>
        /// The russian strings get automatically transliterated
        /// </summary>
        private bool russianAutoTranslit;

        /// <summary>
        /// The original string is used to fill other languages
        /// </summary>
        private bool autoFillFromOriginal;

        /// <summary>
        /// Gets or sets the id.
        /// </summary>
        [XmlAttribute("ID")]
        [Category("Key")]
        public string Id
        {
            get { return this.id; }
            set { this.RaiseAndSetIfChanged(ref this.id, value); }
        }

        /// <summary>
        /// Gets or sets the original language (default).
        /// </summary>
        [Category("Languages")]
        public string Original
        {
            get { return this.original; }
            set { this.RaiseAndSetIfChanged(ref this.original, value); }
        }

        /// <summary>
        /// Gets or sets the english language.
        /// </summary>
        [Category("Languages")]
        public string English
        {
            get { return this.english; }
            set { this.RaiseAndSetIfChanged(ref this.english, value); }
        }

        /// <summary>
        /// Gets or sets the czech language.
        /// </summary>
        [Category("Languages")]
        public string Czech
        {
            get { return this.czech; }
            set { this.RaiseAndSetIfChanged(ref this.czech, value); }
        }

        /// <summary>
        /// Gets or sets the french language.
        /// </summary>
        [Category("Languages")]
        public string French
        {
            get { return this.french; }
            set { this.RaiseAndSetIfChanged(ref this.french, value); }
        }

        /// <summary>
        /// Gets or sets the spanish language.
        /// </summary>
        [Category("Languages")]
        public string Spanish
        {
            get { return this.spanish; }
            set { this.RaiseAndSetIfChanged(ref this.spanish, value); }
        }

        /// <summary>
        /// Gets or sets the italian language.
        /// </summary>
        [Category("Languages")]
        public string Italian
        {
            get { return this.italian; }
            set { this.RaiseAndSetIfChanged(ref this.italian, value); }
        }

        /// <summary>
        /// Gets or sets the polish language.
        /// </summary>
        [Category("Languages")]
        public string Polish
        {
            get { return this.polish; }
            set { this.RaiseAndSetIfChanged(ref this.polish, value); }
        }

        /// <summary>
        /// Gets or sets the portuguese language.
        /// </summary>
        [Category("Languages")]
        public string Portuguese
        {
            get { return this.portuguese; }
            set { this.RaiseAndSetIfChanged(ref this.portuguese, value); }
        }

        /// <summary>
        /// Gets or sets the russian language.
        /// </summary>
        [Category("Languages")]
        public string Russian
        {
            get { return this.russian; }
            set { this.RaiseAndSetIfChanged(ref this.russian, value); }
        }

        /// <summary>
        /// Gets or sets whether the language is autotransated
        /// </summary>
        [Category("Options")]
        [XmlIgnore]
        public bool RussianAutoTranslit
        {
            get { return this.russianAutoTranslit; }
            set { this.RaiseAndSetIfChanged(ref this.russianAutoTranslit, value); }
        }

        /// <summary>
        /// Gets or sets whether the language is autotransated
        /// </summary>
        [Category("Options")]
        [XmlIgnore]
        public bool AutoFillFromOriginal
        {
            get { return this.autoFillFromOriginal; }
            set { this.RaiseAndSetIfChanged(ref this.autoFillFromOriginal, value); }
        }

        /// <summary>
        /// Gets or sets the german language.
        /// </summary>
        [Category("Languages")]
        public string German
        {
            get { return this.german; }
            set { this.RaiseAndSetIfChanged(ref this.german, value); }
        }

        /// <summary>
        /// Gets or sets the korean language.
        /// </summary>
        [Category("Languages")]
        public string Korean
        {
            get { return this.korean; }
            set { this.RaiseAndSetIfChanged(ref this.korean, value); }
        }

        /// <summary>
        /// Gets or sets the japanese language.
        /// </summary>
        [Category("Languages")]
        public string Japanese
        {
            get { return this.japanese; }
            set { this.RaiseAndSetIfChanged(ref this.japanese, value); }
        }

        /// <summary>
        /// Gets or sets the chinese language.
        /// </summary>
        [Category("Languages")]
        public string Chinese
        {
            get { return this.chinese; }
            set { this.RaiseAndSetIfChanged(ref this.chinese, value); }
        }

        /// <summary>
        /// Gets or sets the chinese simplified language.
        /// </summary>
        [Category("Languages")]
        public string Chinesesimp
        {
            get { return this.chinesesimp; }
            set { this.RaiseAndSetIfChanged(ref this.chinesesimp, value); }
        }

        /// <summary>
        /// Gets or sets the turkish language.
        /// </summary>
        [Category("Languages")]
        public string Turkish
        {
            get { return this.turkish; }
            set { this.RaiseAndSetIfChanged(ref this.turkish, value); }
        }

        /// <summary>
        /// Gets or sets the parent
        /// </summary>
        [XmlIgnore]
        [Browsable(false)]
        public Container Parent { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="Key"/> class. 
        /// </summary>
        public Key()
        {
            this.WhenAnyValue(vm => vm.Russian).Subscribe(_ => this.Transliterate());
            this.WhenAnyValue(vm => vm.Original).Subscribe(_ => this.FillAllKeysFromOriginal());
            this.RussianAutoTranslit = false;
        }

        /// <summary>
        /// Calls on the <see cref="TranslitService"/> to transliterate the <see cref="Russian"/> string.
        /// </summary>
        private void Transliterate()
        {
            if (this.RussianAutoTranslit)
            {
                this.Russian = TranslitService.Singleton.Transliterate(this.Russian); 
            }
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
        /// Fills all empty values with english translation with english or original.
        /// </summary>
        public void FillAllKeysFromOriginal()
        {
            if (this.AutoFillFromOriginal)
            {
                if (string.IsNullOrWhiteSpace(this.Original))
                {
                    // if stringtable doesnt have english or original then you cannot fill empty languages
                    return;
                }

                var replacement = this.Original;

                this.English = replacement;

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

        /// <summary>
        /// Wipes all properties except <see cref="English"/> and <see cref="Original"/>
        /// </summary>
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