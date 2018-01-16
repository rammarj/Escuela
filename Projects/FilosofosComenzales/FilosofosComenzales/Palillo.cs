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
        public Palillo(int id)
        {
            this.id = id;
            this.ocupado = false;
        }

        [MethodImpl(MethodImplOptions.Synchronized)]
        public void tomarPalillo(int i)
        {
            if (ocupado)
            {
                Monitor.Wait(this);
            }
            ocupado = true;
            System.Console.WriteLine(" Filosofo " + i + " ha tomado el palillo " + this.id);
        }

        [MethodImpl(MethodImplOptions.Synchronized)]
        public void soltarPalillo(int i)
        {
            ocupado = false;
            System.Console.WriteLine(" El Filosofo " + i + " ha soltado el palillo " + this.id);
            Monitor.PulseAll(this);
        }
    }

}
