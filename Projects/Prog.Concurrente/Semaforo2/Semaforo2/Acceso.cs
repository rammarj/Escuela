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
        private uint contador;
        private Semaforo2 semaforo;
        public Acceso()
        {
            this.semaforo = new Semaforo2( 1 );
            this.contador = 0;
        }
        public void incrementar()
        {
            for (int i = 0; i < 1000; i++)
            {
                this.semaforo.wait();
                this.contador++;
                this.semaforo.signal();
                Console.WriteLine("Thread: " + Thread.CurrentThread.Name + ", contador: " + this.getContador());
            }            
        }
        public uint getContador()
        {
            return this.contador;
        }

    }
}
