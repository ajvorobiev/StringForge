using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RHSStringTableTools.Model;

namespace StringForge.Model
{
    class DuplicateKeyViolation : IViolation
    {
        public ViolationLevel Level
        {
            get { return ViolationLevel.Error; }
            
        }

        public string Message
        {
            get { return CompileMessage(); }
        }

        private string CompileMessage()
        {
            return string.Format("Duplicate Key ID: {0}", Keys[0].Id);
        }

        public ObservableCollection<Key> Keys { get; set; }

        public DuplicateKeyViolation(List<Key> keys)
        {
            this.Keys = new ObservableCollection<Key>(keys);
        }
    }
}
