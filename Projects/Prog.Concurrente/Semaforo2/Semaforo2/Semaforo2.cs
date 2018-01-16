using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Semaforo2
{
    class Semaforo2
    {
        private uint contador, maxThreads;
        private Queue<Thread> enEspera;
        public Semaforo2(uint maxThreads)
        {
            this.contador = maxThreads;
            this.maxThreads = this.contador;
            this.enEspera = new Queue<Thread>();
        }
        public void wait()
        {
            if(this.contador == 0)
            {
                Thread hilo = Thread.CurrentThread;
                this.enEspera.Enqueue(hilo);
                try 
                { 
                    Thread.Sleep(Timeout.Infinite); 
                }
                catch (Exception ex) 
                {
                }
            }
            else
            {
                this.contador -= 1;
            }
        }
        public void signal()
        {
            if (this.contador < this.maxThreads)
            {
                if (this.enEspera.Count > 0)
                {
                    Thread hilo = this.enEspera.Dequeue();
                    hilo.Interrupt();
                }
                this.contador += 1;
            }
        }
    }
}
