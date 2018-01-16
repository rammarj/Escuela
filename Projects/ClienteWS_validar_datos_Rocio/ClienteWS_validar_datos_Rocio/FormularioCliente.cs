using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ClienteWS_validar_datos_Rocio.WebServiceDatos;
using System.Web.Script.Serialization;
using System.Collections;

namespace ClienteWS_validar_datos_Rocio
{
    public partial class FormularioCliente : Form
    {
        private bool crear;
        private int Id;
        private WSDDatosSOAPClient webService;
        private JavaScriptSerializer serializer;
        public FormularioCliente()
        {
            InitializeComponent();
            this.webService = new WSDDatosSOAPClient();
            this.serializer = new JavaScriptSerializer();
            this.Id = 0;
            this.crear = true;
        }
        private void btn_insertar_Click(object sender, EventArgs e)
        {
            try
            {
                String Nombre = this.txt_nombre.Text;
                String Estado = this.cbx_activ_inactiv.Text;
                float Monto = float.Parse(this.txt_monto.Text);
                ArrayList arreglo = new ArrayList();
                arreglo.Add(new Datos() { id=Id, nombre = Nombre, estado = Estado, monto = Monto });
                String serial = serializer.Serialize(arreglo);               
                if (crear)
                {
                    String mensaje = webService.insertar(serial);
                    MessageBox.Show(mensaje,"Mensaje",MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    String mensaje = webService.actualizar(serial);
                    MessageBox.Show(mensaje, "Mensaje", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                this.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public void setActualizar(Datos d)
        {
            this.Id = d.id;
            this.txt_monto.Text = ""+d.monto;
            this.txt_nombre.Text = d.nombre;
            this.cbx_activ_inactiv.Text = d.estado;
            this.btn_insertar.Text = "Actualizar";
            this.crear = false;
        }

        private void btn_limpiar_Click(object sender, EventArgs e)
        {
            this.txt_monto.Text = "";
            this.txt_monto.Text = "";            
        }

        private void btn_cancelar_Click(object sender, EventArgs e)
        {
            this.Close();
        }

    }

}
