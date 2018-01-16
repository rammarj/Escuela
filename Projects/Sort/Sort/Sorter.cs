using System;
using System.Threading;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sort
{
   /**
    * Clase Sorter contiene todos los metodos para ordenar (solo funciona para numeros enteros) que extiende de la clase ArrayList para
    * facilitar agregar numeros y no hay limite de capacidad.
    * @author: Joaquin Ramirez Martinez
    */
    class Sorter: ArrayList
    {
        /**
         * Obtiene el valor del elemento en la posicion indicada
         */
        private int getValueAt(int index)
        {
            return (int)this.GetRange(index, 1).ToArray().ElementAt(0);
        }
        /**
         * Cambia el valor del elemento en la posicion indicada por index
         */
        private void setValueAt(int index, int value)
        {
            this.RemoveAt(index);
            this.Insert(index, value);
        }
        /**
         * Obtiene el elemento pivote para ordenar utilizando el metodo quickSort
         */
        private int pivot(int izq, int der)
        {
            int i;
            int pivote, valor_pivote;
            int aux;
            pivote = izq;
            valor_pivote = this.getValueAt(pivote);
            for (i = izq + 1; i <= der; i++)
            {
                if (getValueAt(i) < valor_pivote)
                {
                    pivote++;
                    aux = getValueAt(i);
                    setValueAt(i, this.getValueAt(pivote));
                    setValueAt(pivote, aux);

                }
            }
            aux = getValueAt(izq);
            this.setValueAt(izq, this.getValueAt(pivote));
            this.setValueAt(pivote, aux);
            return pivote;
        }
        /**
         * Metodo que ordena utilizando la tecnica quicksort
         */
        private void sortQuickSort(int izq, int der)
        {
            int pivote;
            if (izq < der)
            {
                pivote = this.pivot(izq, der);
                this.sortQuickSort(izq, pivote - 1);
                this.sortQuickSort(pivote + 1, der);
            }
        }
        /**
         * Metodo wraper de quickSort accesible para clases donde se instancie esta clase
         */
        public void sortQuickSort()
        {
            //Thread v = new Thread(new ThreadStart(sortQuickSort));
            //v.Start();
            this.sortQuickSort(0, this.Count - 1);
        }
        /**
         * Metodo de ordenamiento utilizando la tecnica burbuja
         */
        public void sortBurbuja()
        {
            int aux;
            for (int i = 0; i < this.Count; i++)//numero de movimientos
            {
                for (int j = 0; j < (this.Count - 1); j++)//ordenar el contenido de la lista
                {
                    if (this.getValueAt(j) > this.getValueAt((j + 1)))
                    {
                        aux = this.getValueAt(j);
                        this.setValueAt(j, this.getValueAt((j + 1)));
                        this.setValueAt((j + 1), aux);
                    }
                }
            }
        }
        /**
         * Metodo de ordenamiento utilizando la tecnica de seleccion directa
         */
        public void sortSeleccionDirecta()
        {
            int menor, aux;
            int pos_menor;
            for (int i = 0; i < this.Count; i++)
            {
                menor = this.getValueAt(i);
                pos_menor = i;
                //buscar el menor y su posicion
                for (int j = (i + 1); j < this.Count; j++)
                {
                    if (this.getValueAt(j) < menor)
                    {
                        menor = this.getValueAt(j);
                        pos_menor = j;
                    }
                }
                //hacer el intercambio
                aux = this.getValueAt(i);
                this.setValueAt(i, menor);
                this.setValueAt(pos_menor, aux);
            }
        }
        /**
         * Metodo de ordenamiento utilizando la tecnica de insercion
         */
        public void sortInsercion()
        {
            int i, a;
            int aux;
            for (i = 1; i < this.Count; i++) //empezar desde 1
            {
                aux = this.getValueAt(i); //guardar el valor a comparar en un auxiliar
                for (a = (i - 1); a >= 0 && this.getValueAt(a) > aux; a--)
                {
                    this.setValueAt(a + 1, this.getValueAt(a)); //recorrer los elementos
                }
                this.setValueAt(a + 1, aux); //poner al elemento en su pocicion real
            }

        }
    }
}
