using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace RHSStringTableTools.Model
{
    public static class ObjectExt
    {
        public static T Clone<T>(this T obj) where T : new()
        {
            return ObjectExtCache<T>.Clone(obj);
        }
        static class ObjectExtCache<T> where T : new()
        {
            private static readonly Func<T, T> cloner;
            static ObjectExtCache()
            {
                ParameterExpression param = Expression.Parameter(typeof(T),"in");

                var bindings = from prop in typeof(T).GetProperties()
                               where prop.CanRead && prop.CanWrite
                               let column = Attribute.GetCustomAttribute(prop,typeof(ColumnAttribute)) as ColumnAttribute
                               where column == null
                               select (MemberBinding)Expression.Bind(prop,Expression.Property(param, prop));

                cloner = Expression.Lambda<Func<T, T>>(
                    Expression.MemberInit(
                        Expression.New(typeof(T)), bindings), param).Compile();
            }
            public static T Clone(T obj)
            {
                return cloner(obj);
            }
        }
    }
}
