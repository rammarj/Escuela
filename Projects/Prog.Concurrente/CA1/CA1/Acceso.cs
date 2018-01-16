using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CA1
{
    class Acceso
    {
        public int total;

        public Acceso()
        {
            total = 0;
        }
        public void incrementar()
        {
            for (int i = 1; i <= 1000000; i++)
            {
                total++;
            }
        }
    }
}
