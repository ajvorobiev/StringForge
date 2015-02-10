using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ReactiveUI;

namespace StringForge.ViewModel
{
    public abstract class EditViewModel : ReactiveObject
    {
        public ReactiveCommand<object> OkCommand { get; protected set; }
        public ReactiveCommand<object> CancelCommand { get; protected set; }
        
    }
}
