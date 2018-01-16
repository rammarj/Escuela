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

            for (int i = 0; i < 10; i++) // iniciar 7 procesos
            {
                Thread hilo = new Thread(acceso.incrementar);
                hilo.Name = ""+i;
                hilo.Start();
            }
            acceso.Release(); //salir del semaforo
            Thread.Sleep(10000); //esperar a que los hilos terminen para poder escribir el total
            
            Console.Read();
        }
    }
}
