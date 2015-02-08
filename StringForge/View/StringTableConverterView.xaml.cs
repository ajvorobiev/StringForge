using System.Windows;

namespace StringForge.View
{
    /// <summary>
    /// Interaction logic for StringTableConverterView.xaml
    /// </summary>
    public partial class StringTableConverterView : Window
    {
        public StringTableConverterView()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
