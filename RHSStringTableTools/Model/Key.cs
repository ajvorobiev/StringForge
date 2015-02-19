// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Key.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Key" /> class specifying the stringtable key
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace RHSStringTableTools.Model
{
    using ReactiveUI;
    using Services;
    using System;
    using System.Xml.Serialization;

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
        /// Gets or sets the id.
        /// </summary>
        [XmlAttribute("ID")]
        public string Id { get; set; }

        /// <summary>
        /// Gets or sets the original language (default).
        /// </summary>
        public string Original { get; set; }

        /// <summary>
        /// Gets or sets the english language.
        /// </summary>
        public string English { get; set; }

        /// <summary>
        /// Gets or sets the czech language.
        /// </summary>
        public string Czech { get; set; }

        /// <summary>
        /// Gets or sets the french language.
        /// </summary>
        public string French { get; set; }

        /// <summary>
        /// Gets or sets the spanish language.
        /// </summary>
        public string Spanish { get; set; }

        /// <summary>
        /// Gets or sets the italian language.
        /// </summary>
        public string Italian { get; set; }

        /// <summary>
        /// Gets or sets the polish language.
        /// </summary>
        public string Polish { get; set; }

        /// <summary>
        /// Gets or sets the portuguese language.
        /// </summary>
        public string Portuguese { get; set; }

        /// <summary>
        /// Gets or sets the russian language.
        /// </summary>
        public string Russian
        {
            get { return russian; }
            set { this.RaiseAndSetIfChanged(ref this.russian, value); }
        }

        /// <summary>
        /// Gets or sets the german language.
        /// </summary>
        public string German { get; set; }

        /// <summary>
        /// Gets or sets the parent
        /// </summary>
        [XmlIgnore]
        public Container Parent { get; set; }

        /// <summary>
        /// Creates an instance of the <see cref="Key"/> class.
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