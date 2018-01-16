using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Runtime.CompilerServices;

namespace FilosofosComenzales
{
    class Sillas
    {
        private Semaforo semaforo;
        private int sillasLibres;//numero de sillas (empezando desde cero)
        public Sillas(int numeroSillas)
        {
            this.semaforo = new Semaforo();
            this.sillasLibres = numeroSillas; //numero de sillas que habra en la mesa
        }

        [MethodImpl(MethodImplOptions.Synchronized)]
        public void ocupar(int i)//ocupar silla
        {
            if (sillasLibres == 0)//sino hay sillas libres se espera
            {
                this.semaforo.wait();//esperar
            }
            System.Console.WriteLine("El Filosofo " + i + " se ha sentado a comer");
            sillasLibres--;
        }

        [MethodImpl(MethodImplOptions.Synchronized)]//hace que el metodo sea un metodo sincronizado y evita que mas metodos entren a el
        public void desocupar(int i)
        {
            sillasLibres++;
            this.semaforo.signal();
            System.Console.WriteLine("El Filosofo " + i + " ha terminado de comer");
        }
    }
}
