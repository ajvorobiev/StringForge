using System.Security.AccessControl;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
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

            ((StringTableEditorViewModel) this.DataContext).Tree = this.projectTreeView;
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

        private void projectTreeView_PreviewMouseRightButtonDown(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            TreeViewItem treeViewItem = VisualUpwardSearch(e.OriginalSource as DependencyObject);

            if (treeViewItem != null)
            {
                treeViewItem.Focus();
                e.Handled = true;
            }
        }

        static TreeViewItem VisualUpwardSearch(DependencyObject source)
        {
            while (source != null && !(source is TreeViewItem))
                source = VisualTreeHelper.GetParent(source);

            return source as TreeViewItem;
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            var viewModel = (StringTableEditorViewModel)DataContext;

            if (viewModel.Projects != null && viewModel.Projects.Count > 0)
            {
                var dlg = MessageBox.Show("Do you want to save the stringtables before exiting?", "Save",
                        MessageBoxButton.YesNoCancel, MessageBoxImage.Question);
                
                if (dlg == MessageBoxResult.Yes)
                {

                    if (viewModel.SaveCommand.CanExecute(null))
                        viewModel.SaveCommand.Execute(null);
                }
                else if (dlg == MessageBoxResult.Cancel)
                {
                    e.Cancel = true;
                }
            }
        }
    }
}
