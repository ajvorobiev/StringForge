namespace StringForge.Helpers
{
    using System;
    using System.ComponentModel;
    using System.ComponentModel.DataAnnotations;
    using System.Windows;
    using System.Windows.Controls;

    public class EnumHelper : DependencyObject
    {
        public static Type GetEnum(DependencyObject obj)
        {
            return (Type)obj.GetValue(EnumProperty);
        }

        public static void SetEnum(DependencyObject obj, string value)
        {
            obj.SetValue(EnumProperty, value);
        }

        // Using a DependencyProperty as the backing store for Enum.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty EnumProperty =
            DependencyProperty.RegisterAttached("Enum", typeof(Type), typeof(EnumHelper), new PropertyMetadata(null, OnEnumChanged));

        private static void OnEnumChanged(DependencyObject sender, DependencyPropertyChangedEventArgs e)
        {
            var control = sender as ItemsControl;

            if (control != null)
            {
                if (e.NewValue != null)
                {
                    var _enum = Enum.GetValues(e.NewValue as Type);
                    control.ItemsSource = _enum;
                }
            }
        }

        public static bool GetMoreDetails(DependencyObject obj)
        {
            return (bool)obj.GetValue(MoreDetailsProperty);
        }

        public static void SetMoreDetails(DependencyObject obj, bool value)
        {
            obj.SetValue(MoreDetailsProperty, value);
        }

        // Using a DependencyProperty as the backing store for MoreDetails.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty MoreDetailsProperty =
            DependencyProperty.RegisterAttached("MoreDetails", typeof(bool), typeof(EnumHelper), new PropertyMetadata(false, OnMoreDetailsChanged));

        private static void OnMoreDetailsChanged(DependencyObject sender, DependencyPropertyChangedEventArgs e)
        {
            var control = sender as FrameworkElement;
            if (control != null)
            {
                var enumobject = control.DataContext;
                var fieldInfo = enumobject.GetType().GetField(enumobject.ToString());

                var array = fieldInfo.GetCustomAttributes(false);

                if (array.Length == 0)
                {
                    if (control is TextBlock)
                    {
                        ((TextBlock)control).Text = enumobject.ToString();
                    }
                    else if (control is ContentControl)
                    {
                        ((ContentControl)control).Content = enumobject;
                    }
                    return;
                }

                foreach (var o in array)
                {
                    if (o is DescriptionAttribute)
                    {
                        control.ToolTip = ((DescriptionAttribute)o).Description;
                    }
                    else if (o is DisplayAttribute)
                    {
                        if (control is TextBlock)
                        {
                            ((TextBlock)control).Text = ((DisplayAttribute)o).Name;
                        }
                        else if (control is ContentControl)
                        {
                            ((ContentControl)control).Content = ((DisplayAttribute)o).Name;
                        }
                    }
                }
            }
        }
    }
}