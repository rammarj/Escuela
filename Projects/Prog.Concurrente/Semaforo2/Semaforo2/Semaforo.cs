using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Semaforo2
{
    class Semaforo
    {
        private int contador;

        private Queue<Thread> enEspera;

        public Semaforo() //sin parametros porque solo permitira un hilo a la vez en la zona critica
        {
            this.contador = 1; //estado inicial de contador
            this.enEspera = new Queue<Thread>();
        }
        public void wait()
        {
            if(contador == 1) //siempre se cumple esta condicion la primera vez por lo tanto dejara pasar al primer hilo
            {
                contador = 0; //si no hay nadie ejecutando la zona critica igualar a cero
            }
            else
            { //poner los demas hilos en espera
                Thread hilo = Thread.CurrentThread;
                this.enEspera.Enqueue(hilo);
                try { Thread.Sleep(Timeout.Infinite); }catch (Exception ex){ }
            }
        }
        public void signal()
        {
            if (enEspera.Count == 0) 
            {
                contador = 1; //si ya se vacio la cola, no seguir desencolando
            }
            else
            {
                Thread hilo = this.enEspera.Dequeue();
                hilo.Interrupt(); //continuar ejecutando el siguiente thread que se habia suspendido
            }

        }

    }
}
