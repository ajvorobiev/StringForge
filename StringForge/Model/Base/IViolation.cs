// --------------------------------------------------------------------------------------------------------------------
// <copyright file="IViolation.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="IViolation" /> class provides the interface for a violation
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge.Model
{
    using RHSStringTableTools.Model;
    using System.Collections.ObjectModel;

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