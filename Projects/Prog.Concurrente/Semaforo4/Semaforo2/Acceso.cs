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
        private int contador;
        private Semaphore s;
        public Acceso()
        {
            s = new Semaphore(0, 1); //0 procesos COMO INICIO y 1 proceso a la vez
            contador = 0;
        }
        public void incrementar()
        {
            for (int i = 1; i <= 1000000; i++)
            {
                s.WaitOne();
                contador++;
                s.Release();
                Console.WriteLine(Thread.CurrentThread.Name + " : " + contador);
            }
        }
        public int getContador()
        {
            return contador;
        }

        public void Release() //wrapper para el metodo Release del semaforo
        {
            s.Release();
        }

    }
}
