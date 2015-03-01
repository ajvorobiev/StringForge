// --------------------------------------------------------------------------------------------------------------------
// <copyright file="KeyTemplate.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The key id template
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.Model.Templates
{
    using ReactiveUI;

    /// <summary>
    /// The key id template
    /// </summary>
    public class KeyTemplate : ReactiveObject
    {
        /// <summary>
        /// Backing field for the template name
        /// </summary>
        private string name;
        private string template;

        /// <summary>
        /// Gets or sets the template name
        /// </summary>
        public string Name
        {
            get { return this.name; }
            set { this.RaiseAndSetIfChanged(ref this.name, value); }
        }

        /// <summary>
        /// Gets or sets the template
        /// </summary>
        public string Template
        {
            get { return this.template; }
            set { this.RaiseAndSetIfChanged(ref this.template, value); }
        }
    }
}