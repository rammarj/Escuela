using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace ChildWnds
{
    class Program
    {
        [DllImport("user32.dll", EntryPoint = "FindWindowEx")]
        public static extern IntPtr FindWindowEx(IntPtr hwndParent, IntPtr hwndChildAfter, string lpszClass, string lpszWindow);

        static void Main(string[] args)
        {
            Process[] anotherApps = Process.GetProcessesByName("WINWORD");
            if (anotherApps.Length == 0) return;
            if (anotherApps[0] != null)
            {
                var allChildWindows = new WindowHandleInfo(anotherApps[0].MainWindowHandle).GetAllChildHandles();
                Console.WriteLine(allChildWindows.Count);
                
            }
            Console.Read();
        }
        
    }
}
