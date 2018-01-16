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

namespace ProcessWatcher
{            
    class Program
    {
        private static Hashtable procesos;
        private SpeechSynthesizer tts;
        
        Program()
        {            
            tts = new SpeechSynthesizer();
            procesos = new Hashtable();
            procesos.Add("WINWORD.EXE", "word");
            procesos.Add("MSACCESS.EXE", "axess");
            procesos.Add("DATABASECOMPARE.EXE", "Databeis Compeir");
            procesos.Add("ONENOTE.EXE", "uon nout");
            procesos.Add("EXCEL.EXE", "excel");
            procesos.Add("INFOPATH.EXE", "infopad");
            procesos.Add("OUTLOOK.EXE", "outluk");
            procesos.Add("POWERPNT.EXE", "powerpoint");
            procesos.Add("MSPUB.EXE", "publisher");
            procesos.Add("SPREADSHEETCOMPARE.EXE", "spridshit compair");
        }

        public static void Main()
        {
            //para los eventos de inicio de procesos
            ManagementEventWatcher startWatch = new ManagementEventWatcher(
              new WqlEventQuery("SELECT * FROM Win32_ProcessStartTrace"));

            startWatch.EventArrived += new EventArrivedEventHandler(startWatch_EventArrived); //regitro manager del evento
            startWatch.Start();

            //para los eventos de detencion de procesos
            ManagementEventWatcher stopWatch = new ManagementEventWatcher(
              new WqlEventQuery("SELECT * FROM Win32_ProcessStopTrace"));

            //stopWatch.EventArrived += new EventArrivedEventHandler(stopWatch_EventArrived); //registrar manager del evento

            stopWatch.Start();
            
            Console.WriteLine("Presiona cualquier tecla para salir...");
            Console.Read();

            startWatch.Stop();
            stopWatch.Stop();
        }
        /**
         * Evento manejador de los programas que se detienen
        */
        static void stopWatch_EventArrived(object sender, EventArrivedEventArgs e)
        {          
            Console.WriteLine("Proceso terminado: {0}", e.NewEvent.Properties["ProcessName"].Value);
        }
        /**
         * Evento manejador de los programas que se inician
         */
        static void startWatch_EventArrived(object sender, EventArrivedEventArgs e)
        {
            Program p = new Program();
            String nombre = e.NewEvent.Properties["ProcessName"].Value.ToString(); //obtener nombre del procesos
            String pencontrado = p.getValor(nombre); //encontrar el nombre adecuado para este proceso
            
            if (pencontrado != null){                
                Thread.Sleep(1000); //delay para que reconozca que ya hay más ventanas del mismo proceso
                int nProcesos = Util.getNumProcesosHijos(nombre.Replace(".EXE","")); //obtener el numero de procesos 
                Console.WriteLine(nProcesos);
                if (nProcesos > 1 )
                    p.hablar("Usted ha abierto otra ventana del programa: Maicrosoft, " + pencontrado
                        + ". ¿Está seguro de lo que hace?");
                else
                    p.hablar("Usted ha iniciado el programa: Maicrosoft, "+pencontrado+".");
            }

            Console.WriteLine("Proceso iniciado: {0}", nombre);

        }

        public String getValor(String clave)
        {
            int index = 0;
            foreach (String s in procesos.Keys)
            {
                if (s == clave)
                    return getValorPorPos(index);
                index++;
            }
            return null;
        }

        public void hablar(String texto)
        {
            PromptBuilder b = new PromptBuilder();            
            b.AppendText(texto);
            tts.SpeakAsync(b);
        }

        public String getValorPorPos(int pos)
        {
            int index = 0;
            foreach (String s in procesos.Values)
            {
                if (pos == index)
                    return s;
                index++;
            }
            return null;
        }
    }
}
