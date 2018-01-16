using System.Threading;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Semaforo2
{
    class Program
    {
        static void Main(string[] args)
        {
            Acceso acceso = new Acceso();
            Thread[] hilos = new Thread[5];
            for (int i = 0; i < hilos.Length; i++)
            {
                hilos[i] = new Thread(acceso.incrementar);
                hilos[i].Name = "" + (i+1);
            }

            for (int i = 0; i < hilos.Length; i++)
            {
                hilos[i].Start();
            }            
            //Thread.CurrentThread.Join();
            //Thread.Sleep(2000); //esperar a que los hilos terminen para poder escribir el total
            //Console.WriteLine("valor del contador en Acceso: " + acceso.getContador());
            Console.Read();
        }
    }
}
