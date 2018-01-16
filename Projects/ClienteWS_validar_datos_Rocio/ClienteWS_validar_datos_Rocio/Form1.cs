using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;
using System.Web.Script.Serialization;
using ClienteWS_validar_datos_Rocio.WebServiceDatos;

namespace ClienteWS_validar_datos_Rocio
{
    public partial class Form1 : Form
    {
        private WSDDatosSOAPClient soap;
        private JavaScriptSerializer serializer;
        public Form1()
        {
            InitializeComponent();
            soap = new WSDDatosSOAPClient();            
            this.serializer = new JavaScriptSerializer();          
            rellenarDatagrid();
        }        
        private void rellenarDatagrid(){
            String datos_json = soap.consulta();
	        this.dtgv_datos.Columns.Clear();
	        this.dtgv_datos.Rows.Clear();
            ArrayList cols = new ArrayList();
            cols.Add("Id");
            cols.Add("Nombre");
            cols.Add("Estado");
            cols.Add("Monto");
	        IEnumerator ens = cols.GetEnumerator();
	        int cont = 0;
	        while (ens.MoveNext())
	        {
		        DataGridViewTextBoxColumn c = new DataGridViewTextBoxColumn();
		        if (cont == 0)
			        c.ReadOnly = true;
		        c.HeaderText = ens.Current.ToString();
		        c.CellTemplate = new DataGridViewTextBoxCell();
		        c.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
		        this.dtgv_datos.Columns.Add(c);
		        cont++;
	        }

            ArrayList arrayl = new ArrayList();
            ArrayList datos = (ArrayList)serializer.Deserialize(datos_json, arrayl.GetType());
            
            for(int i=0; i < datos.Count;i++){
                Dictionary<String, Object> dato = (Dictionary<String, Object>)datos[i];
                DataGridViewRow row = new DataGridViewRow();
                /*id*/
                DataGridViewCell id = new DataGridViewTextBoxCell();
                id.Value = dato["id"];
                row.Cells.Add(id);
                /*NOMBRE*/
                DataGridViewCell nombre = new DataGridViewTextBoxCell();
                nombre.Value = dato["nombre"];
                row.Cells.Add(nombre);
                /*NOMBRE*/
                DataGridViewCell estado = new DataGridViewTextBoxCell();
                estado.Value = dato["estado"];
                row.Cells.Add(estado);
                /*NOMBRE*/
                DataGridViewCell monto = new DataGridViewTextBoxCell();
                monto.Value = dato["monto"];
                row.Cells.Add(monto);

			    this.dtgv_datos.Rows.Add(row);
            }            	        
        }

        private void btn_actualizar_Click(object sender, EventArgs e)
        {
            DataGridViewRow a = dtgv_datos.SelectedRows[0];
            int Id = int.Parse(a.Cells[0].Value.ToString());
            String Nombre = a.Cells[1].Value.ToString();
            String Estado = a.Cells[2].Value.ToString();
            float Monto = float.Parse(a.Cells[3].Value.ToString());
            
            Datos dato = new Datos() { id = Id, nombre = Nombre, estado = Estado, monto = Monto };
            FormularioCliente form = new FormularioCliente();
            form.setActualizar(dato);
            form.ShowDialog();
            rellenarDatagrid();
        }

        private void btn_agregar_Click(object sender, EventArgs e)
        {
            FormularioCliente form = new FormularioCliente();
            form.ShowDialog();
            rellenarDatagrid();
        }
        private void btn_eliminar_Click(object sender, EventArgs e)
        {
            DataGridViewRow a = dtgv_datos.SelectedRows[0];
            int Id = int.Parse(a.Cells[0].Value.ToString());
            ArrayList arreglo = new ArrayList();
            arreglo.Add(new Datos() { id = Id });
            String mensage = soap.borrar(serializer.Serialize(arreglo));
            MessageBox.Show(mensage, "Informacion", MessageBoxButtons.OK, MessageBoxIcon.Information);
            rellenarDatagrid();
        }

        private void btn_pagar_Click(object sender, EventArgs e)
        {
            DataGridViewRow a = dtgv_datos.SelectedRows[0];
            int Id = int.Parse(a.Cells[0].Value.ToString());
            String Nombre = a.Cells[1].Value.ToString();
            String Estado = a.Cells[2].Value.ToString();
            float Monto = float.Parse(a.Cells[3].Value.ToString());

            Datos dato = new Datos() { id = Id, nombre = Nombre, estado = Estado, monto = Monto };
            FormularioPagar form = new FormularioPagar();
            form.setDato(dato);
            form.ShowDialog();
            //rellenarDatagrid();
            //MessageBox.Show(mensage, "Informacion", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

    }
}
