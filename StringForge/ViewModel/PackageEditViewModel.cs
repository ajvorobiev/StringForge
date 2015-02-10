using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ReactiveUI;
using RHSStringTableTools.Model;

namespace StringForge.ViewModel
{
    class PackageEditViewModel : EditViewModel
    {
        private string name;
        public string Name
        {
            get { return this.name; }
            set { this.RaiseAndSetIfChanged(ref this.name, value); }
        }

        public Package Thing { get; set; }

        public Project Parent { get; set; }

        public PackageEditViewModel(Package item, Project container = null)
        {
            this.Thing = item;
            this.Parent = container;

            var canOk = this.WhenAny(vm => vm.Name, vm => !string.IsNullOrWhiteSpace(vm.Value));
            this.OkCommand = ReactiveCommand.Create(canOk);
            this.OkCommand.Subscribe(_ => this.OkCommandExecute());

            this.CancelCommand = ReactiveCommand.Create();
            this.CancelCommand.Subscribe(_ => this.CancelCommandExecute());
        }

        private object CancelCommandExecute()
        {
            throw new NotImplementedException();
        }

        private object OkCommandExecute()
        {
            throw new NotImplementedException();
        }
    }
}
