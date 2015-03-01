// --------------------------------------------------------------------------------------------------------------------
// <copyright file="TemplateViewModel.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class specifying the Container container
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.Linq;

namespace StringForge.ViewModel
{
    using Model.Templates;
    using ReactiveUI;
    using System;
    using System.Collections.ObjectModel;

    /// <summary>
    /// The view model for the template editor
    /// </summary>
    internal class TemplateViewModel : ReactiveObject
    {
        /// <summary>
        /// The backing field for the templates collection
        /// </summary>
        private ObservableCollection<KeyTemplate> templates;

        /// <summary>
        /// The backing field for the selected template
        /// </summary>
        private KeyTemplate selectedTemplate;

        /// <summary>
        /// Gets or sets the template collection
        /// </summary>
        public ObservableCollection<KeyTemplate> Templates
        {
            get { return this.templates; }
            set { this.RaiseAndSetIfChanged(ref this.templates, value); }
        }

        /// <summary>
        /// Gets or sets the selected template
        /// </summary>
        public KeyTemplate SelectedTemplate
        {
            get { return this.selectedTemplate; }
            set { this.RaiseAndSetIfChanged(ref this.selectedTemplate, value); }
        }

        /// <summary>
        /// Adds a template
        /// </summary>
        public ReactiveCommand<object> AddTemplateCommand { get; private set; }

        /// <summary>
        /// Removes a template
        /// </summary>
        public ReactiveCommand<object> RemoveTemplateCommand { get; private set; }

        /// <summary>
        /// Saves the templates
        /// </summary>
        public ReactiveCommand<object> SaveCommand { get; private set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="TemplateViewModel"/> class.
        /// </summary>
        public TemplateViewModel()
        {
            
            this.Templates = TemplateMaster.Instance.KeyTemplates;

            // initialize commands
            this.AddTemplateCommand = ReactiveCommand.Create();
            this.AddTemplateCommand.Subscribe(_ => this.AddTemplateExecute());

            var canRemove = this.WhenAny(vm => vm.SelectedTemplate, vm => vm != null);
            this.RemoveTemplateCommand = ReactiveCommand.Create(canRemove);
            this.RemoveTemplateCommand.Subscribe(_ => this.RemoveTemplateExecute());

            this.SaveCommand = ReactiveCommand.Create();
            this.SaveCommand.Subscribe(_ => this.SaveExecute());
        }

        /// <summary>
        /// Saves the templates
        /// </summary>
        private void SaveExecute()
        {
            TemplateMaster.Instance.KeyTemplates = this.Templates;
            TemplateMaster.Instance.Save();
        }

        /// <summary>
        /// Removes the template
        /// </summary>
        /// <returns></returns>
        private void RemoveTemplateExecute()
        {
            this.Templates.Remove(this.selectedTemplate);
            this.SelectedTemplate = this.Templates.FirstOrDefault();
        }

        /// <summary>
        /// Adds a template
        /// </summary>
        private void AddTemplateExecute()
        {
            var newTemplate = new KeyTemplate() { Name = "Untitled Template", Template = "STR_" };

            this.Templates.Add(newTemplate);
            this.SelectedTemplate = newTemplate;
        }
    }
}