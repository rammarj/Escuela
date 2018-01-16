using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace ChWndProceses
{
    class Program
    {
        private delegate bool EnumWindowsProc(IntPtr hWnd, int lParam);

        [DllImport("user32.dll", SetLastError = true)]
        private static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint lpdwProcessId);

        [DllImport("USER32.DLL")]
        private static extern bool EnumWindows(EnumWindowsProc enumFunc, int lParam);

        [DllImport("USER32.DLL")]
        private static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);

        [DllImport("USER32.DLL")]
        private static extern int GetWindowTextLength(IntPtr hWnd);

        [DllImport("USER32.DLL")]
        private static extern bool IsWindowVisible(IntPtr hWnd);

        [DllImport("USER32.DLL")]
        private static extern IntPtr GetShellWindow();

        public static IDictionary<IntPtr, string> GetOpenWindowsFromPID(int processID)
        {
            IntPtr hShellWindow = GetShellWindow();
            Dictionary<IntPtr, string> dictWindows = new Dictionary<IntPtr, string>();

            EnumWindows(delegate(IntPtr hWnd, int lParam)
            {
                if (hWnd == hShellWindow) return true;
                if (!IsWindowVisible(hWnd)) return true;

                int length = GetWindowTextLength(hWnd);
                if (length == 0) return true;

                uint windowPid;
                GetWindowThreadProcessId(hWnd, out windowPid);
                if (windowPid != processID) return true;

                StringBuilder stringBuilder = new StringBuilder(length);
                GetWindowText(hWnd, stringBuilder, length + 1);
                dictWindows.Add(hWnd, stringBuilder.ToString());
                return true;
            }, 0);

            return dictWindows;
        }
        static void Main(string[] args)
        {
            Process[] processes = Process.GetProcessesByName("WINWORD");
            foreach (Process process in processes)
            {
                IDictionary<IntPtr, string> windows = GetOpenWindowsFromPID(process.Id);
                foreach (KeyValuePair<IntPtr, string> kvp in windows)
                {
                    // Do whatever you want here
                    Console.WriteLine(kvp.Value);
                }
            }
            Console.Read();
        }
    }
}
