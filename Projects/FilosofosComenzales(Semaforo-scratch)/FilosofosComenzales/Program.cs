using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace FilosofosComenzales
{
    class Program
    {
        static void Main(string[] args)
        {
            Mesa mesa = new Mesa(5);

            Console.WriteLine("[+] Iniciando filosofos comenzales");
            Console.WriteLine("[+] Numero de comenzales: " + mesa.getNumeroComenzales());
            Console.WriteLine("[+] Comenzando ejecucion...\n");
            
            Thread.Sleep(2000);

            mesa.iniciar();
        }
    }
}
