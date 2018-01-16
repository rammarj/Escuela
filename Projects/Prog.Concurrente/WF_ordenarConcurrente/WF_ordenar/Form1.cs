using System;
using System.Threading;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WF_ordenar
{
    public partial class Form1 : Form
    {

        private Lista lista;
        delegate void delegadoCambiarTexto(TextBox txtBox, String texto);


        public Form1()
        {
            InitializeComponent();
            lista = new Lista();
            initLista();
            this.txt_burbuja.Text = lista.ToString();
            this.txt_insercion.Text = lista.ToString();
            this.txt_quicksort.Text = lista.ToString();
            this.txt_seleccion.Text = lista.ToString();
        }

        private void initLista()
        {
            //lista.Clear();
            Random rand = new Random();
            for (int i = 0; i < 100; i++)
            {
                lista.Add(rand.Next(0, 1000));
            }
        }
        /**
         * Obtiene el elemento pivote para ordenar utilizando el metodo quickSort
         */
        private int pivot(int izq, int der, Lista lista)
        {
            int i;
            int pivote, valor_pivote;
            int aux;
            pivote = izq;
            valor_pivote = lista.getValueAt(pivote);
            for (i = izq + 1; i <= der; i++)
            {
                if (lista.getValueAt(i) < valor_pivote)
                {
                    pivote++;
                    aux = lista.getValueAt(i);
                    lista.setValueAt(i, lista.getValueAt(pivote));
                    lista.setValueAt(pivote, aux);

                }
            }
            aux = lista.getValueAt(izq);
            lista.setValueAt(izq, lista.getValueAt(pivote));
            lista.setValueAt(pivote, aux);
            return pivote;
        }
        /**
         * Metodo que ordena utilizando la tecnica quicksort
         */
        private void sortQuickSort(int izq, int der, Lista lista)
        {
            int pivote;
            if (izq < der)
            {
                pivote = pivot(izq, der, lista);
                sortQuickSort(izq, pivote - 1, lista);
                sortQuickSort(pivote + 1, der, lista);

                callback_CambiarTexto(this.txt_quicksort, lista.ToString());
            }
        }
        /**
         * Metodo wraper de quickSort accesible para clases donde se instancie esta clase
         */
        public void sortQuickSort()
        {
            //Thread v = new Thread(new ThreadStart(sortQuickSort));
            //v.Start();
            Lista lista = new Lista(this.lista);
            sortQuickSort(0, lista.Count - 1 , lista);
        }
        /**
         * Metodo de ordenamiento utilizando la tecnica burbuja
         */
        public void sortBurbuja()
        {
            Lista lista = new Lista(this.lista);
            int aux;
            for (int i = 0; i < lista.Count; i++)//numero de movimientos
            {
                for (int j = 0; j < (lista.Count - 1); j++)//ordenar el contenido de la lista
                {
                    if (lista.getValueAt(j) > lista.getValueAt((j + 1)))
                    {
                        aux = lista.getValueAt(j);
                        lista.setValueAt(j, lista.getValueAt((j + 1)));
                        lista.setValueAt((j + 1), aux);

                        callback_CambiarTexto(this.txt_burbuja, lista.ToString());
                    }
                }
            }
        }
        /**
         * Metodo de ordenamiento utilizando la tecnica de seleccion directa
         */
        public void sortSeleccionDirecta()
        {
            Lista lista = new Lista(this.lista);
            int menor, aux;
            int pos_menor;
            for (int i = 0; i < lista.Count; i++)
            {
                menor = lista.getValueAt(i);
                pos_menor = i;
                //buscar el menor y su posicion
                for (int j = (i + 1); j < lista.Count; j++)
                {
                    if (lista.getValueAt(j) < menor)
                    {
                        menor = lista.getValueAt(j);
                        pos_menor = j;

                        callback_CambiarTexto(this.txt_seleccion, lista.ToString());
                    }
                    
                    callback_CambiarTexto(this.txt_seleccion, lista.ToString());
                }
                //hacer el intercambio
                aux = lista.getValueAt(i);
                lista.setValueAt(i, menor);
                lista.setValueAt(pos_menor, aux);

                callback_CambiarTexto(this.txt_seleccion, lista.ToString());
            }
        }
        /**
         * Metodo de ordenamiento utilizando la tecnica de insercion
         */
        public void sortInsercion()
        {
            Lista lista = new Lista(this.lista);
            int i, a;
            int aux;
            for (i = 1; i < lista.Count; i++) //empezar desde 1
            {
                aux = lista.getValueAt(i); //guardar el valor a comparar en un auxiliar
                for (a = (i - 1); a >= 0 && lista.getValueAt(a) > aux; a--)
                {
                    lista.setValueAt(a + 1, lista.getValueAt(a)); //recorrer los elementos
                    
                    callback_CambiarTexto(this.txt_insercion, lista.ToString());
                }
                lista.setValueAt(a + 1, aux); //poner al elemento en su pocicion real

                callback_CambiarTexto(this.txt_insercion, lista.ToString());
            }

        }

        private void btn_iniciar_Click(object sender, EventArgs e)
        {
            Thread hilo_burbuja = new Thread(sortBurbuja);
            hilo_burbuja.Start();

            Thread hilo_qsort = new Thread(() => sortQuickSort(0, this.lista.Count-1, new Lista(this.lista)));
            hilo_qsort.Start();

            Thread hilo_insercion = new Thread(sortInsercion);
            hilo_insercion.Start();

            Thread hilo_seleccion = new Thread(sortSeleccionDirecta);
            hilo_seleccion.Start();

            this.btn_iniciar.Enabled = false;

        }

        void callback_CambiarTexto(TextBox txtBox, String texto){
            if (txtBox.InvokeRequired)
            {
                delegadoCambiarTexto delegado = new delegadoCambiarTexto(callback_CambiarTexto);
                this.Invoke(delegado, new Object[2]{txtBox, texto});
            }
            else
            {
                txtBox.Text = texto;
                txtBox.Update();
            }
        }

    }
}
