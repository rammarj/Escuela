using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace FilosofosComenzales
{
    class Palillo
    {
        private int id;
        private Boolean ocupado;
        private Semaforo semaforo;
        public Palillo(int id)
        {
            this.id = id;
            this.ocupado = false;
            this.semaforo = new Semaforo();
        }

        [MethodImpl(MethodImplOptions.Synchronized)]
        public void tomarPalillo(int i)
        {
            if (ocupado)
            {
                this.semaforo.wait();
            }
            ocupado = true;
            System.Console.WriteLine(" Filosofo " + i + " ha tomado el palillo " + this.id);
        }

        [MethodImpl(MethodImplOptions.Synchronized)]
        public void soltarPalillo(int i)
        {
            ocupado = false;
            this.semaforo.signal();
            System.Console.WriteLine(" El Filosofo " + i + " ha soltado el palillo " + this.id);
        }
    }

}
