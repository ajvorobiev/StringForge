// --------------------------------------------------------------------------------------------------------------------
// <copyright file="App.xaml.cs" company="RHS">
//   Red Hammer Studios
// </copyright>
// <summary>
//   Interaction logic for MainWindow.xaml
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace StringForge
{
    using System.Windows;
    using NLog;

    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        /// <summary>
        /// The current class logger
        /// </summary>
        private static Logger logger = LogManager.GetCurrentClassLogger();
    }
}