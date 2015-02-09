using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace StringForge.ViewModel
{
    class AboutViewModel
    {
        public string Title
        {
            get { return "StringForge"; }
        }

        public string Version
        {
            get { return Assembly.GetEntryAssembly().GetName().Version.ToString(); }
        }

        public string Copyright
        {
            get { return "By Alex \"Soul_Assassin\" Vorobiev. Distributed under the MIT license."; }
        }
    }
}
