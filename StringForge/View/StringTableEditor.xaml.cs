using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
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
            ((StringTableEditorViewModel) this.DataContext).SelectedNode = projectTreeView.SelectedItem;
        }
    }
}
