using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Management;
using System.Threading;

namespace ProcesosOffice
{
    public class VigilanteProcesos
    {
        private ProcesosOfficeDictionary procesosOficce;
        private ManagementEventWatcher startWatch;
        private ManagementEventWatcher stopWatch;

        public VigilanteProcesos(){
            this.procesosOficce = ProcesosOfficeDictionary.getInstancia(); //obtner instancia del diccionario donde estan los procesos de office
            this.startWatch = new ManagementEventWatcher(
              new WqlEventQuery("SELECT * FROM Win32_ProcessStartTrace")
              );

            this.startWatch.EventArrived += new EventArrivedEventHandler(this.startWatch_EventArrived); //regitro manager del evento            

            //para los eventos de detencion de procesos
            this.stopWatch = new ManagementEventWatcher(
                new WqlEventQuery("SELECT * FROM Win32_ProcessStopTrace"));
        }
        
        /**
         * manejador de evento de procesos iniciados
         */
        private void startWatch_EventArrived(object sender, EventArrivedEventArgs e)
        {
            String nombre = e.NewEvent.Properties["ProcessName"].Value.ToString(); //obtener nombre del procesos
            String pencontrado = procesosOficce.getValor(nombre); //encontrar el nombre adecuado para este proceso

            if (pencontrado != null)
            {
                Thread.Sleep(1000); //delay para que reconozca que ya hay más ventanas del mismo proceso
                int nProcesos = Util.getNumProcesosHijos(nombre.Replace(".EXE", "")); //obtener el numero de procesos 
                //Console.WriteLine(nProcesos);
                if (nProcesos > 1)
                    Util.hablar("Usted ha abierto otra ventana del programa: Maicrosoft " + pencontrado
                        + ". ¿Está seguro de lo que hace?");
                else
                    Util.hablar("Usted ha iniciado el programa: Maicrosoft " + pencontrado + ".");
            }

        }

        /**
         * Evento manejador de los programas que se detienen
        */
        private void stopWatch_EventArrived(object sender, EventArrivedEventArgs e)
        {
        }

        public void iniciarVigilante()
        {
            startWatch.Start();
            stopWatch.Start();
        }

        public void detenerVigilante()
        {
            startWatch.Stop();
            stopWatch.Stop();
        }


    }


}
