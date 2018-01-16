using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace FilosofosComenzales
{
    class Mesa
    {
        private int numeroFilosofos;
        private Thread[] hilosFilosofos;
        private Sillas sillas;
        public Mesa(int nFilosofos)
        {
            this.numeroFilosofos = nFilosofos;
            Palillo[] palillos = new Palillo[this.numeroFilosofos]; //el numero de palillos es el mismo que el de filosofos
            Filosofo[] filosofos = new Filosofo[this.numeroFilosofos];

            this.sillas = new Sillas(this.numeroFilosofos); //sillas que hay en la mesa (el numero de filosofos)

            for (int i = 0; i < palillos.Length; i++)//inicializacion de palillos
            {
                palillos[i] = new Palillo(i);
            }

            this.hilosFilosofos = new Thread[this.numeroFilosofos]; //hilos que van a correr (numero de filosofos)

            for (int i = 0; i < this.numeroFilosofos; i++) //inicializar filosofos
            {
                filosofos[i] = new Filosofo(i, palillos[i], palillos[ ((i+1)%5) ], this.sillas);
                this.hilosFilosofos[i] = new Thread(filosofos[i].comer);
            }
        }
        public void iniciar()
        {
            for (int i = 0; i < this.numeroFilosofos; i++)
            {
                this.hilosFilosofos[i].Start();
            }
        }
        public int getNumeroComenzales()
        {
            return this.numeroFilosofos;
        }
    }
}
