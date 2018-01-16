using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Management;
using System.Threading.Tasks;
using System.Threading;
using System.Collections;
using System.Speech.Synthesis;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace ProcesosOffice
{            
    class Program
    {
        public static void Main()
        {

            VigilanteProcesos vigilante = new VigilanteProcesos();
            vigilante.iniciarVigilante();

            Console.ReadLine();

            vigilante.detenerVigilante();
        }        

    }
}
