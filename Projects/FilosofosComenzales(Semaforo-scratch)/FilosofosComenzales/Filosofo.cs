using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Text;
using System.Threading.Tasks;

namespace FilosofosComenzales
{
    class Filosofo
    {
        private int id;//id del filosofo
        private Palillo palillo_izquierdo, palillo_derecho;//palillos
        private Sillas silla;//silla para los filosofos

        public Filosofo(int id, Palillo palillo_izquierdo, Palillo palillo_derecho, Sillas s)
        {
            this.id = id;
            this.palillo_izquierdo = palillo_izquierdo;
            this.palillo_derecho = palillo_derecho;
            this.silla = s;
        }
        public void comer()
        {
            //Random
            for(;;)
            {
                try
                {
                    this.silla.ocupar(id);
                    //comer
                    palillo_izquierdo.tomarPalillo(id);
                    palillo_derecho.tomarPalillo(id);
                    //comiendo
                    //Thread.Sleep(100); //100 mls comiendo
                    //dejar de comer
                    palillo_derecho.soltarPalillo(id);
                    palillo_izquierdo.soltarPalillo(id);
                    this.silla.desocupar(id);//irse
                }
                catch (Exception e) {
                    Console.WriteLine(e.Message);
                    Console.Read(); //esperar una tecla
                }
            }
        }
    }
}
