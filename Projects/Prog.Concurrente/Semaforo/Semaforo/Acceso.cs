using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Semaforo
{
    class Acceso
    {
        private int contador;
        public Acceso()
        {
            contador = 0;
        }
        public void incrementar()
        {
            for (int i = 1; i <= 1000000; i++)
            {
                contador++;
            }
        }
    }
}
