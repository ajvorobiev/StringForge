// --------------------------------------------------------------------------------------------------------------------
// <copyright file="PackageEditViewModel.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class specifying the package container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.ViewModel
{
    using System;
    using System.Windows;
    using ReactiveUI;
    using RHSStringTableTools.Model;

    /// <summary>
    /// The package edit view model.
    /// </summary>
    internal class PackageEditViewModel : EditViewModel
    {
        /// <summary>
        /// Backing field for the the name
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
        public Package Thing { get; set; }

        /// <summary>
        /// Gets or sets the parent of the thing
        /// </summary>
        public Project Parent { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="PackageEditViewModel"/> class.
        /// </summary>
        /// <param name="item">The item.</param>
        /// <param name="container">The container.</param>
        public PackageEditViewModel(Package item, Project container = null)
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
        /// <param name="window">
        /// The window.
        /// </param>
        private void OkCommandExecute(object window)
        {
            this.Thing.Name = this.Name;

            // add the new package to the project at the very end
            if (this.Parent != null)
            {
                this.Parent.Packages.Add(this.Thing);
            }

            ((Window)window).Close();
        }
    }
}