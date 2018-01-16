using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CA1
{
    class Program
    {
        static void Main(string[] args)
        {
            Acceso a = new Acceso();

            Thread t1 = new Thread(a.incrementar); 
            Thread t2 = new Thread(a.incrementar); 
            Thread t3 = new Thread(a.incrementar);

            t1.Start();
            t2.Start();
            t3.Start();

            Thread.Sleep(10000);

            Console.WriteLine("total de personas: " + a.total);
            Console.Read();
        }
    }
}
