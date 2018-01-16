using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Semaforo2
{
    class Acceso
    {
        private static int contador = 0;
        private static Semaphore s;

        public static void incrementar()
        {
            s.WaitOne();
            for (int i = 1; i <= 10000; i++)
            {
                contador++;
            }
            s.Release(1);
        }
        public static int getContador()
        {
            return contador;
        }

        static void Main(string[] args)
        {
            s = new Semaphore(0,1);
            for (int i = 1; i <= 7; i++)
            {
                Thread hilo = new Thread(incrementar);
                hilo.Start();
            }
            s.Release();
            Thread.Sleep(1000);
            Console.WriteLine("valor del contador en Acceso: " + getContador());
            Console.Read();
        }

    }
}
