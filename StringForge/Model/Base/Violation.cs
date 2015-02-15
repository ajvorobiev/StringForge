using System.Collections.ObjectModel;
using RHSStringTableTools.Model;

namespace StringForge.Model
{
    internal interface IViolation
    {
        ViolationLevel Level { get; }

        string Message { get; }

        ObservableCollection<Key> Keys { get; set; } 
    }
}