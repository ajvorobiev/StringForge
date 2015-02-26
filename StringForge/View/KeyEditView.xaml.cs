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
using ReactiveUI;
using StringForge.ViewModel;

namespace StringForge.View
{
    /// <summary>
    /// Interaction logic for KeyEditView.xaml
    /// </summary>
    public partial class KeyEditView : Window, IViewFor<KeyEditViewModel>
    {
        public KeyEditView()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        object IViewFor.ViewModel
        {
            get { return KeyForm.ViewModel; }
            set { KeyForm.ViewModel = (KeyEditViewModel)value; }
        }

        public KeyEditViewModel ViewModel
        {
            get { return KeyForm.ViewModel; }
            set { KeyForm.ViewModel = value; }
        }
    }
}
