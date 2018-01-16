using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Diffie
{
    using System.Net.Sockets;  
    using System.Collections;
    using System.Text;
    using System.Threading;
    using System.Security.Cryptography;
    using System.Security;
    using System.Security.Util;
    
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            listener = new TcpListener(5000);
            listener.Start();
            new Thread(iniciarServicio).Start();
        }
        //delegate void refrescar(TextBox a);        
        private TcpListener listener;
        private void iniciarServicio()
        {
            Socket socket;
            byte[] buffeer;
            String mensaje;
            while (true)
            {
                //PETICION 1
                socket = listener.AcceptSocket();
                buffeer = new byte[socket.ReceiveBufferSize];
                socket.Receive(buffeer);
                mensaje = convertirAstring(buffeer);
                //OBTENER P Y G
                String[] split = mensaje.Split(new char[1] { ',' });
                int p = int.Parse(split[0]);
                int g = int.Parse(split[1]);
                int a = generarPrimoMenor(p);
                int R1 = (int)Math.Pow(g, a) % p; 
                socket.Send(convertirAbytes(""+R1));
                socket.Close();
                //PETICION 2
                socket = listener.AcceptSocket();
                buffeer = new byte[socket.ReceiveBufferSize];
                socket.Receive(buffeer);
                mensaje = convertirAstring(buffeer);
                //OBTENER R2
                int R2 = int.Parse(mensaje);
                int K1 = (int) Math.Pow(R2, a) % p;
                socket.Send(convertirAbytes("hecho"));
                socket.Close();
                MessageBox.Show("Clave generada en servidor:" + K1);
            }

                        

        }
        int generarRandomPrimo() {
            Random rand = new Random();
            int random = rand.Next(int.MaxValue);
            while (!esPrimo(random))
                random = rand.Next(int.MaxValue);
            return random;
        }

        bool esPrimo( int n)
        {
            if (n == 1 || n == 2 || n == 3)
                return true;
            else
            {
                for (int i = 2; i < Math.Sqrt(n); i++)
                {
                    if (n % i == 0)
                        return false;
                }
            }
            return true;
        }
        private Label label1;
        

        private String convertirAstring(byte[] bytes)
        {
            StringBuilder builder = new StringBuilder();
            foreach (byte b in bytes)
            {
                builder.Append((char)b);
            }
            return builder.ToString();
        }

        private byte[] convertirAbytes(String s)
        {
            byte[] bs = new byte[s.Length];
            for (int i = 0; i < bs.Length; i++)
            {
                bs[i] = (byte)s[i];
            }
            return bs;
        }
        int generarPrimoMenor(int n)
        {
            int primo = generarRandomPrimo();
            while (primo >= n)
                primo = generarRandomPrimo();
            return primo;
        }
    }
}
