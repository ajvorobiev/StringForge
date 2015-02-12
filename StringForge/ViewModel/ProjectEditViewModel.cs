// --------------------------------------------------------------------------------------------------------------------
// <copyright file="ProjectEditViewModel.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Package" /> class specifying the package container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.ViewModel
{
    using ReactiveUI;
    using RHSStringTableTools.Model;
    using System;
    using System.Windows;

    internal class ProjectEditViewModel : EditViewModel
    {
        private string name;

        /// <summary>
        /// Gets or sets the name
        /// </summary>
        public string Name
        {
            get { return this.name; }
            set { this.RaiseAndSetIfChanged(ref this.name, value); }
        }

        /// <summary>
        /// Gets or sets the thing
        /// </summary>
        public Project Thing { get; set; }

        public ProjectEditViewModel(Project item)
        {
            this.Thing = item;

            var canOk = this.WhenAny(vm => vm.Name, vm => !string.IsNullOrWhiteSpace(vm.Value));
            this.OkCommand = ReactiveCommand.Create(canOk);
            this.OkCommand.Subscribe(this.OkCommandExecute);

            this.SetProperties();
        }

        /// <summary>
        /// Set the properties
        /// </summary>
        private void SetProperties()
        {
            this.Name = this.Thing.Name;
        }

        /// <summary>
        /// Execute the ok command
        /// </summary>
        private void OkCommandExecute(object window)
        {
            this.Thing.Name = this.Name;

            ((Window)window).Close();
        }
    }
}