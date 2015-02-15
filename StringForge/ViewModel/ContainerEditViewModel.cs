// --------------------------------------------------------------------------------------------------------------------
// <copyright file="ContainerEditViewModel.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="Container" /> class specifying the Container container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.ViewModel
{
    using ReactiveUI;
    using RHSStringTableTools.Model;
    using System;
    using System.Windows;

    /// <summary>
    /// The container edit view model
    /// </summary>
    internal class ContainerEditViewModel : EditViewModel
    {
        /// <summary>
        /// Backing fields for the name
        /// </summary>
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
        public Container Thing { get; set; }

        /// <summary>
        /// Gets or sets the parent of the thing
        /// </summary>
        public Package Parent { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="ContainerEditViewModel"/> class.
        /// </summary>
        /// <param name="item">The item.</param>
        /// <param name="container">The container.</param>
        public ContainerEditViewModel(Container item, Package container = null)
        {
            this.Thing = item;
            this.Parent = container;
            this.Thing.Parent = container;

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

            // add the new container to the package at the very end
            if (this.Parent != null)
            {
                this.Parent.Containers.Add(this.Thing);
            }

            ((Window)window).Close();
        }
    }
}