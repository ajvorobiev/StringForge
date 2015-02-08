// --------------------------------------------------------------------------------------------------------------------
// <copyright file="SourceAction.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   The <see cref="SourceAction" /> enum specifying the things you can do with source csv files
// </summary>
// --------------------------------------------------------------------------------------------------------------------

using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace RHSStringTableTools.Model
{
    /// <summary>
    /// The <see cref="SourceAction" /> enum specifying the things you can do with source csv files
    /// </summary>
    public enum SourceAction
    {
        [Display(Name = "Nothing")]
        [Description("Nothing will be done to the source file.")]
        Nothing,
        [Display(Name = "Rename")]
        [Description("The source files will be renamed so the game no longer recognises them.")]
        Rename,
        [Display(Name = "Delete")]
        [Description("The source files will be completely removed.")]
        Delete
    }
}