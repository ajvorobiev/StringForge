// --------------------------------------------------------------------------------------------------------------------
// <copyright file="TranslitService.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="TranslitService" /> transliterates from latin to cyrillic
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace RHSStringTableTools.Services
{
    using System.Collections.Generic;
    using System.Linq;

    public sealed class TranslitService
    {
        /// <summary>
        /// The instance.
        /// </summary>
        private static readonly TranslitService Instance = new TranslitService();

        /// <summary>
        /// The words.
        /// </summary>
        private Dictionary<string, string> words = new Dictionary<string, string>();

        private Dictionary<string, string> wordsTwoLetter = new Dictionary<string, string>();
        private Dictionary<string, string> wordsThreeLetter = new Dictionary<string, string>();
        private List<string> holdLetters = new List<string>();

        /// <summary>
        /// Prevents a default instance of the <see cref="TranslitService"/> class from being created.
        /// </summary>
        private TranslitService()
        {
            // initialize dictionary
            this.words.Add("a", "а");
            this.words.Add("b", "б");
            this.words.Add("v", "в");
            this.words.Add("w", "в");
            this.wordsTwoLetter.Add("w/", "с");
            this.words.Add("g", "г");
            this.words.Add("d", "д");
            this.words.Add("e", "е");
            this.wordsTwoLetter.Add("ыo", "ё");
            this.wordsTwoLetter.Add("yo", "ё");
            //this.holdLetters.Add("y");
            this.wordsTwoLetter.Add("зh", "ж");
            this.wordsTwoLetter.Add("zh", "ж");
            //this.holdLetters.Add("z");
            this.words.Add("z", "з");
            this.words.Add("i", "и");
            this.wordsTwoLetter.Add("ij", "й");
            this.wordsTwoLetter.Add("иj", "й");
            this.words.Add("k", "к");
            this.words.Add("l", "л");
            this.words.Add("m", "м");
            this.words.Add("n", "н");
            this.words.Add("o", "о");
            this.words.Add("p", "п");
            this.words.Add("r", "р");
            this.words.Add("s", "с");
            this.words.Add("t", "т");
            this.words.Add("u", "у");
            this.words.Add("f", "ф");
            this.words.Add("h", "х");
            this.words.Add("c", "ц");
            this.wordsTwoLetter.Add("цh", "ч");
            this.wordsTwoLetter.Add("ch", "ч");
            //this.holdLetters.Add("c");
            this.wordsTwoLetter.Add("сh", "ш");
            this.wordsTwoLetter.Add("sh", "ш");
            //this.holdLetters.Add("s");
            this.wordsThreeLetter.Add("сцh", "щ");
            this.wordsThreeLetter.Add("сch", "щ");
            this.wordsThreeLetter.Add("sch", "щ");
            //this.holdLetters.Add("sc");
            this.wordsTwoLetter.Add("j'", "ъ");
            this.wordsTwoLetter.Add("ь'", "ъ");
            this.words.Add("y", "ы");
            this.words.Add("j", "ь");
            this.wordsTwoLetter.Add("ьe", "э");
            this.wordsTwoLetter.Add("je", "э");
            this.wordsTwoLetter.Add("ыu", "ю");
            this.wordsTwoLetter.Add("ыa", "я");
            this.wordsTwoLetter.Add("yu", "ю");
            this.wordsTwoLetter.Add("ya", "я");

            this.words.Add("A", "А");
            this.words.Add("B", "Б");
            this.words.Add("V", "В");
            this.words.Add("W", "В");
            this.wordsTwoLetter.Add("W/", "С");
            this.words.Add("G", "Г");
            this.words.Add("D", "Д");
            this.words.Add("E", "Е");
            this.wordsTwoLetter.Add("Ыo", "Ё");
            this.wordsTwoLetter.Add("Yo", "Ё");
            //this.holdLetters.Add("Y");
            this.wordsTwoLetter.Add("Зh", "Ж");
            this.wordsTwoLetter.Add("Zh", "Ж");
            //this.holdLetters.Add("Z");
            this.words.Add("Z", "З");
            this.words.Add("I", "И");
            this.wordsTwoLetter.Add("Ij", "Й");
            this.wordsTwoLetter.Add("Иj", "Й");
            this.words.Add("K", "К");
            this.words.Add("L", "Л");
            this.words.Add("M", "М");
            this.words.Add("N", "Н");
            this.words.Add("O", "О");
            this.words.Add("P", "П");
            this.words.Add("R", "Р");
            this.words.Add("S", "С");
            this.words.Add("T", "Т");
            this.words.Add("U", "У");
            this.words.Add("F", "Ф");
            this.words.Add("H", "Х");
            this.words.Add("C", "Ц");
            this.wordsTwoLetter.Add("Цh", "Ч");
            this.wordsTwoLetter.Add("Ch", "Ч");
            //this.holdLetters.Add("C");
            this.wordsTwoLetter.Add("Сh", "Ш");
            this.wordsTwoLetter.Add("Sh", "Ш");
            //this.holdLetters.Add("S");
            this.wordsThreeLetter.Add("Сцh", "Щ");
            this.wordsThreeLetter.Add("Sch", "Щ");
            this.wordsThreeLetter.Add("Сch", "Щ");
            //this.holdLetters.Add("Sc");
            this.wordsTwoLetter.Add("J'", "Ъ");
            this.wordsTwoLetter.Add("Ь'", "Ъ");
            this.words.Add("Y", "Ы");
            this.words.Add("J", "Ь");
            this.wordsTwoLetter.Add("Je", "Э");
            this.wordsTwoLetter.Add("Ьe", "Э");
            this.wordsTwoLetter.Add("Ыu", "Ю");
            this.wordsTwoLetter.Add("Ыa", "Я");
            this.wordsTwoLetter.Add("Yu", "Ю");
            this.wordsTwoLetter.Add("Ya", "Я");

            // ignores
            this.words.Add("&amp;lt;br/&amp;gt;", "&lt;br/&gt;");
            this.words.Add("&lt;br/&gt;", "&lt;br/&gt;");
            this.words.Add("&амп;лт;бр/&амп;гт;", "&lt;br/&gt;");
            this.words.Add("&лт;бр/&гт;", "&lt;br/&gt;");
        }

        /// <summary>
        /// Gets the instance.
        /// </summary>
        public static TranslitService Singleton
        {
            get { return Instance; }
        }

        /// <summary>
        /// The transliterate method. Takes latin text and transliterates to cyrillic type.
        /// </summary>
        /// <param name="capturedString">
        /// The captured string.
        /// </param>
        /// <returns>
        /// The <see cref="string"/> in cyrillic.
        /// </returns>
        public string Transliterate(string capturedString)
        {
            string result = null;

            if (!string.IsNullOrWhiteSpace(capturedString))
            {
                // three letter subs first
                capturedString = this.wordsThreeLetter.Aggregate(capturedString, (current, pair) => current.Replace(pair.Key, pair.Value));

                // two letter subs later
                capturedString = this.wordsTwoLetter.Aggregate(capturedString, (current, pair) => current.Replace(pair.Key, pair.Value));

                // first pass
                capturedString = this.words.Aggregate(capturedString,
                    (current, pair) => current.Replace(pair.Key, pair.Value));

                result = this.words.Aggregate(capturedString, (current, pair) => current.Replace(pair.Key, pair.Value));
            }

            // finally one letter
            return result;
        }
    }
}