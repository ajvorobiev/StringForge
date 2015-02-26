// --------------------------------------------------------------------------------------------------------------------
// <copyright file="IViolation.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  class provides the interface for a violation
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.Model
{
    using System.Collections.ObjectModel;
    using RHSStringTableTools.Model;

    /// <summary>
    /// Provides an interface for a violation
    /// </summary>
    internal interface IViolation
    {
        /// <summary>
        /// Gets the level.
        /// </summary>
        ViolationLevel Level { get; }

        /// <summary>
        /// Gets the message.
        /// </summary>
        string Message { get; }

        /// <summary>
        /// Gets or sets the keys.
        /// </summary>
        ObservableCollection<Key> Keys { get; set; }
    }
}