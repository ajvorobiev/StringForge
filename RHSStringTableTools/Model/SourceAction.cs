// --------------------------------------------------------------------------------------------------------------------
// <copyright file="SourceAction.cs" company="RHS">
//   Copyright (c) 2015 Alex Vorobiev
// </copyright>
// <summary>
//   The  enum specifying the things you can do with source csv files
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace RHSStringTableTools.Model
{
    using System.ComponentModel;
    using System.ComponentModel.DataAnnotations;

    /// <summary>
    /// The <see cref="SourceAction" /> enumeration specifying the things you can do with source csv files
    /// </summary>
    public enum SourceAction
    {
        /// <summary>
        /// No action
        /// </summary>
        [Display(Name = "Nothing")]
        [Description("Nothing will be done to the source file.")]
        Nothing,

        /// <summary>
        /// Renames the files.
        /// </summary>
        [Display(Name = "Rename")]
        [Description("The source files will be renamed so the game no longer recognises them.")]
        Rename,

        /// <summary>
        /// Deletes the files.
        /// </summary>
        [Display(Name = "Delete")]
        [Description("The source files will be completely removed.")]
        Delete
    }
}