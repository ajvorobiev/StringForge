using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RHSStringTableTools.Services
{
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

        /// <summary>
        /// Prevents a default instance of the <see cref="TranslitService"/> class from being created.
        /// </summary>
        private TranslitService()
        {
            // initialize dictionary
            this.words.Add("а", "a");
            this.words.Add("б", "b");
            this.words.Add("в", "v");
            this.words.Add("г", "g");
            this.words.Add("д", "d");
            this.words.Add("е", "e");
            this.wordsTwoLetter.Add("ё", "yo");
            this.wordsTwoLetter.Add("ж", "zh");
            this.words.Add("з", "z");
            this.words.Add("и", "i");
            this.words.Add("й", "j");
            this.words.Add("к", "k");
            this.words.Add("л", "l");
            this.words.Add("м", "m");
            this.words.Add("н", "n");
            this.words.Add("о", "o");
            this.words.Add("п", "p");
            this.words.Add("р", "r");
            this.words.Add("с", "s");
            this.words.Add("т", "t");
            this.words.Add("у", "u");
            this.words.Add("ф", "f");
            this.words.Add("х", "h");
            this.words.Add("ц", "c");
            this.wordsTwoLetter.Add("ч", "ch");
            this.wordsTwoLetter.Add("ш", "sh");
            this.wordsThreeLetter.Add("щ", "sch");
            this.words.Add("ъ", "j");
            this.words.Add("ы", "y");
            this.words.Add("ь", "j");
            this.words.Add("э", "e");
            this.wordsTwoLetter.Add("ю", "yu");
            this.wordsTwoLetter.Add("я", "ya");
            this.words.Add("А", "A");
            this.words.Add("Б", "B");
            this.words.Add("В", "V");
            this.words.Add("Г", "G");
            this.words.Add("Д", "D");
            this.words.Add("Е", "E");
            this.wordsTwoLetter.Add("Ё", "Yo");
            this.wordsTwoLetter.Add("Ж", "Zh");
            this.words.Add("З", "Z");
            this.words.Add("И", "I");
            this.words.Add("Й", "J");
            this.words.Add("К", "K");
            this.words.Add("Л", "L");
            this.words.Add("М", "M");
            this.words.Add("Н", "N");
            this.words.Add("О", "O");
            this.words.Add("П", "P");
            this.words.Add("Р", "R");
            this.words.Add("С", "S");
            this.words.Add("Т", "T");
            this.words.Add("У", "U");
            this.words.Add("Ф", "F");
            this.words.Add("Х", "H");
            this.words.Add("Ц", "C");
            this.wordsTwoLetter.Add("Ч", "Ch");
            this.wordsTwoLetter.Add("Ш", "Sh");
            this.wordsThreeLetter.Add("Щ", "Sch");
            this.words.Add("Ъ", "J");
            this.words.Add("Ы", "Y");
            this.words.Add("Ь", "J");
            this.words.Add("Э", "E");
            this.wordsTwoLetter.Add("Ю", "Yu");
            this.wordsTwoLetter.Add("Я", "Ya");
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
            // three letter subs first
            capturedString = this.wordsThreeLetter.Aggregate(capturedString, (current, pair) => current.Replace(pair.Value, pair.Key));

            // two letter subs later
            capturedString = this.wordsTwoLetter.Aggregate(capturedString, (current, pair) => current.Replace(pair.Value, pair.Key));

            // finally one letter
            return this.words.Aggregate(capturedString, (current, pair) => current.Replace(pair.Value, pair.Key));
        }
    }
}
