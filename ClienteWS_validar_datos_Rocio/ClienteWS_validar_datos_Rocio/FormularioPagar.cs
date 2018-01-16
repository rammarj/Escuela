using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClienteWS_validar_datos_Rocio
{
    public partial class FormularioPagar : Form
    {
        private float monto;
        public FormularioPagar()
        {
            InitializeComponent();
        }
        public void setDato(Datos d)
        {
            this.lbl_id.Text = ""+d.id;
            this.lbl_nombre.Text = d.nombre;
            this.lbl_estado.Text = d.estado;
            this.monto = d.monto;
        }
        private void btn_pagar_Click(object sender, EventArgs e)
        {
            float monto = float.Parse(this.txt_monto.Text);
            if (monto > this.monto)
            {
                MessageBox.Show("Saldo insuficiente!");
            }
            else
            {
                MessageBox.Show("Pago realizado con éxito!");
            }
            Close();
        }
    }
}
