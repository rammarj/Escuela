using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;

namespace ClienteDiffie
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnIniciar_Click(object sender, EventArgs e)
        {
            String ip = txtIP.Text.ToString();
            int puerto = int.Parse(txtPuerto.Text.ToString());
            int p = generarRandomPrimo();
            int g = 5;
            int b = generarPrimoMenor(p);
            String msg = enviarPeticion(ip, puerto, p+","+g);
            int R1 = int.Parse(msg);
            int R2 = (int) Math.Pow(g, b) % p;
            int K2 = (int) Math.Pow(R1, b) % p;
            //MANDAR R2
            enviarPeticion(ip, puerto, ""+R2);
            MessageBox.Show("Clave generado cliente: " + K2);
        }

        int generarPrimoMenor(int n)
        {
            int primo = generarRandomPrimo();
            while (primo >= n)
                primo = generarRandomPrimo();
            return primo;
        }

        private String enviarPeticion(String ip, int puerto, String m)
        {
            TcpClient cliente = new TcpClient();
            cliente.Connect(ip, puerto);
            NetworkStream stream = cliente.GetStream();
            byte[] msg = new byte[m.Length];
            for (int i = 0; i < msg.Length; i++)
            {
                msg[i] = (byte) m[i];
            }
            stream.Write(msg, 0, msg.Length);
            StringBuilder builder = new StringBuilder();
            int read = 0;
            while (!stream.DataAvailable)
            {
                while ((read = stream.ReadByte()) != -1)
                {
                    builder.Append((char)read);
                }
                break;
            }
            cliente.Close();
            return builder.ToString();
        }
        int generarRandomPrimo()
        {
            Random rand = new Random();
            int random = rand.Next(int.MaxValue);
            while (!esPrimo(random))
                random = rand.Next(int.MaxValue);
            return random;
        }

        bool esPrimo(int n)
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
    }
}
