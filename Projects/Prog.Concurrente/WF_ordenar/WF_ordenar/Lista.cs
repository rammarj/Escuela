using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WF_ordenar
{
    class Lista: List<int>
    {
        /**
         * Obtiene el valor del elemento en la posicion indicada
         */
        public int getValueAt(int index)
        {
            return (int)this.GetRange(index, 1).ToArray().ElementAt(0);
        }
        /**
         * Cambia el valor del elemento en la posicion indicada por index
         */
        public void setValueAt(int index, int value)
        {
            this.RemoveAt(index);
            this.Insert(index, value);
        }


        public String toString()
        {
            String s = "";
            for (int i = 0; i< this.Count; i++)
            {
                s += "" + this.getValueAt(i) + ",";
            }
            return s;
        }

    }
}
