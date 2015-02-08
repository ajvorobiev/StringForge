using System.Windows;
using RHSStringTableTools.Model;
using StringForge.ViewModel;

namespace StringForge.View
{
    /// <summary>
    /// Interaction logic for StringTableEditor.xaml
    /// </summary>
    public partial class StringTableEditor : Window
    {
        public StringTableEditor()
        {
            InitializeComponent();
        }

        private void TreeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (projectTreeView.SelectedItem != null)
            {
                // pass on key selection
                ((StringTableEditorViewModel)this.DataContext).SelectedNode = projectTreeView.SelectedItem;


                // assign context menu
                if (projectTreeView.SelectedItem.GetType() == typeof(Project))
                {
                    projectTreeView.ContextMenu = projectTreeView.Resources["ProjectContext"] as System.Windows.Controls.ContextMenu;
                }
                else if (projectTreeView.SelectedItem.GetType() == typeof(Package))
                {
                    projectTreeView.ContextMenu = projectTreeView.Resources["PackageContext"] as System.Windows.Controls.ContextMenu;
                }
                else if (projectTreeView.SelectedItem.GetType() == typeof(Container))
                {
                    projectTreeView.ContextMenu = projectTreeView.Resources["ContainerContext"] as System.Windows.Controls.ContextMenu;
                }
                else if (projectTreeView.SelectedItem.GetType() == typeof(Key))
                {
                    projectTreeView.ContextMenu = projectTreeView.Resources["KeyContext"] as System.Windows.Controls.ContextMenu;
                } 
            }
        }
    }
}
