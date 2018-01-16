using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.Threading.Tasks;

namespace ProcesosOffice
{
    public class ProcesosOfficeDictionary: Dictionary<String, String>
    {
        private ProcesosOfficeDictionary()
        {
            this.Add("WINWORD.EXE", "word");
            this.Add("MSACCESS.EXE", "axess");
            this.Add("DATABASECOMPARE.EXE", "Databeis Compeir");
            this.Add("ONENOTE.EXE", "uon nout");
            this.Add("EXCEL.EXE", "excel");
            this.Add("INFOPATH.EXE", "infopad");
            this.Add("OUTLOOK.EXE", "outluk");
            this.Add("POWERPNT.EXE", "powerpoint");
            this.Add("MSPUB.EXE", "publisher");
            this.Add("SPREADSHEETCOMPARE.EXE", "spridshit compair");
        }

        public static ProcesosOfficeDictionary getInstancia()
        {
            return new ProcesosOfficeDictionary();
        }

        private String getValorPorPos(int pos)
        {
            int index = 0;
            foreach (String s in this.Values)
            {
                if (pos == index)
                    return s;
                index++;
            }
            return null;
        }

        public String getValor(String clave)
        {
            int index = 0;
            foreach (String s in this.Keys)
            {
                if (s == clave)
                    return this.getValorPorPos(index);
                index++;
            }
            return null;
        }
    }
}
