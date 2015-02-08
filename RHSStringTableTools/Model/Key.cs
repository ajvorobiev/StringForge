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
    using System.Collections.Generic;
    using System.Xml.Serialization;

    /// <summary>
    /// The key model class.
    /// </summary>
    public class Key
    {
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
        public string Russian { get; set; }

        /// <summary>
        /// Gets or sets the german language.
        /// </summary>
        public string German { get; set; }

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
        /// Fills all empty values with english translation with english.
        /// </summary>
        public void FillEmptyKeysWithEnglish()
        {
            if (string.IsNullOrWhiteSpace(this.Czech))
            {
                this.Czech = this.English;
            }

            if (string.IsNullOrWhiteSpace(this.French))
            {
                this.French = this.English;
            }

            if (string.IsNullOrWhiteSpace(this.Spanish))
            {
                this.Spanish = this.English;
            }

            if (string.IsNullOrWhiteSpace(this.Italian))
            {
                this.Italian = this.English;
            }

            if (string.IsNullOrWhiteSpace(this.Polish))
            {
                this.Polish = this.English;
            }

            if (string.IsNullOrWhiteSpace(this.Portuguese))
            {
                this.Portuguese = this.English;
            }

            if (string.IsNullOrWhiteSpace(this.Russian))
            {
                this.Russian = this.English;
            }

            if (string.IsNullOrWhiteSpace(this.German))
            {
                this.German = this.English;
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
    }
}