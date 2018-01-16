using System;
using System.Threading;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Sort;

namespace Sort
{
    class Program
    {

        static void Main(string[] args)
        {
            
            Console.Title = "Metodos de ordenamiento";
            Sorter sorter = new Sorter();
            Random rand = new Random();
            //agregar enteros aleatorios dentro de la lista
            Console.WriteLine("\nAgregando numeros aleatorios.. ");
            for (int i = 0; i < 100; i++)
            {
                sorter.Add(rand.Next(-1000, 1000));
            }
            Console.WriteLine("\nAntes de ordenar: \n");
            foreach (int i in sorter)
            {
                Console.Out.Write("\t" + i);
            }
            sorter.sortQuickSort();
            Console.WriteLine("\n\nDespues de ordenar: \n");
            foreach (int i in sorter)
            {
                Console.Out.Write("\t" + i);
            }
            Console.In.Read();
        }
    }
}
