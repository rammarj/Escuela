namespace ClienteWS_validar_datos_Rocio
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_pagar = new System.Windows.Forms.Button();
            this.btn_eliminar = new System.Windows.Forms.Button();
            this.btn_actualizar = new System.Windows.Forms.Button();
            this.dtgv_datos = new System.Windows.Forms.DataGridView();
            this.btn_agregar = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dtgv_datos)).BeginInit();
            this.SuspendLayout();
            // 
            // btn_pagar
            // 
            this.btn_pagar.Location = new System.Drawing.Point(331, 90);
            this.btn_pagar.Name = "btn_pagar";
            this.btn_pagar.Size = new System.Drawing.Size(75, 23);
            this.btn_pagar.TabIndex = 3;
            this.btn_pagar.Text = "Pagar";
            this.btn_pagar.UseVisualStyleBackColor = true;
            this.btn_pagar.Click += new System.EventHandler(this.btn_pagar_Click);
            // 
            // btn_eliminar
            // 
            this.btn_eliminar.Location = new System.Drawing.Point(331, 61);
            this.btn_eliminar.Name = "btn_eliminar";
            this.btn_eliminar.Size = new System.Drawing.Size(75, 23);
            this.btn_eliminar.TabIndex = 4;
            this.btn_eliminar.Text = "Eliminar";
            this.btn_eliminar.UseVisualStyleBackColor = true;
            this.btn_eliminar.Click += new System.EventHandler(this.btn_eliminar_Click);
            // 
            // btn_actualizar
            // 
            this.btn_actualizar.Location = new System.Drawing.Point(332, 32);
            this.btn_actualizar.Name = "btn_actualizar";
            this.btn_actualizar.Size = new System.Drawing.Size(75, 23);
            this.btn_actualizar.TabIndex = 5;
            this.btn_actualizar.Text = "Actualizar";
            this.btn_actualizar.UseVisualStyleBackColor = true;
            this.btn_actualizar.Click += new System.EventHandler(this.btn_actualizar_Click);
            // 
            // dtgv_datos
            // 
            this.dtgv_datos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dtgv_datos.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.dtgv_datos.Location = new System.Drawing.Point(2, 3);
            this.dtgv_datos.MultiSelect = false;
            this.dtgv_datos.Name = "dtgv_datos";
            this.dtgv_datos.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dtgv_datos.Size = new System.Drawing.Size(324, 242);
            this.dtgv_datos.TabIndex = 2;
            // 
            // btn_agregar
            // 
            this.btn_agregar.Location = new System.Drawing.Point(331, 3);
            this.btn_agregar.Name = "btn_agregar";
            this.btn_agregar.Size = new System.Drawing.Size(75, 23);
            this.btn_agregar.TabIndex = 5;
            this.btn_agregar.Text = "Agregar";
            this.btn_agregar.UseVisualStyleBackColor = true;
            this.btn_agregar.Click += new System.EventHandler(this.btn_agregar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(415, 258);
            this.Controls.Add(this.btn_pagar);
            this.Controls.Add(this.btn_eliminar);
            this.Controls.Add(this.btn_agregar);
            this.Controls.Add(this.btn_actualizar);
            this.Controls.Add(this.dtgv_datos);
            this.Name = "Form1";
            this.Text = "BD Datos";
            ((System.ComponentModel.ISupportInitialize)(this.dtgv_datos)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btn_pagar;
        private System.Windows.Forms.Button btn_eliminar;
        private System.Windows.Forms.Button btn_actualizar;
        private System.Windows.Forms.DataGridView dtgv_datos;
        private System.Windows.Forms.Button btn_agregar;

    }
}

