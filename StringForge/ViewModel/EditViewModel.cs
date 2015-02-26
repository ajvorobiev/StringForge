// --------------------------------------------------------------------------------------------------------------------
// <copyright file="EditViewModel.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  base class
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.ViewModel
{
    using ReactiveUI;

    /// <summary>
    /// The <see cref="EditViewModel" /> base class
    /// </summary>
    public abstract class EditViewModel : ReactiveObject
    {
        /// <summary>
        /// Gets or sets the ok command.
        /// </summary>
        public ReactiveCommand<object> OkCommand { get; protected set; }

        /// <summary>
        /// Gets or sets the cancel command.
        /// </summary>
        public ReactiveCommand<object> CancelCommand { get; protected set; }
    }
}