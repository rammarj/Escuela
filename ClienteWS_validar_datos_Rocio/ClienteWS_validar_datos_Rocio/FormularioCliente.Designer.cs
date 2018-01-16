namespace ClienteWS_validar_datos_Rocio
{
    partial class FormularioCliente
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_limpiar = new System.Windows.Forms.Button();
            this.btn_insertar = new System.Windows.Forms.Button();
            this.cbx_activ_inactiv = new System.Windows.Forms.ComboBox();
            this.txt_monto = new System.Windows.Forms.TextBox();
            this.txt_nombre = new System.Windows.Forms.TextBox();
            this.lbl_monto = new System.Windows.Forms.Label();
            this.lbl_estado = new System.Windows.Forms.Label();
            this.lbl_nombre = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_cancelar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btn_limpiar
            // 
            this.btn_limpiar.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.btn_limpiar.Location = new System.Drawing.Point(121, 189);
            this.btn_limpiar.Name = "btn_limpiar";
            this.btn_limpiar.Size = new System.Drawing.Size(75, 26);
            this.btn_limpiar.TabIndex = 12;
            this.btn_limpiar.Text = "Limpiar";
            this.btn_limpiar.UseVisualStyleBackColor = true;
            this.btn_limpiar.Click += new System.EventHandler(this.btn_limpiar_Click);
            // 
            // btn_insertar
            // 
            this.btn_insertar.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.btn_insertar.Location = new System.Drawing.Point(202, 189);
            this.btn_insertar.Name = "btn_insertar";
            this.btn_insertar.Size = new System.Drawing.Size(75, 26);
            this.btn_insertar.TabIndex = 13;
            this.btn_insertar.Text = "Insertar";
            this.btn_insertar.UseVisualStyleBackColor = true;
            this.btn_insertar.Click += new System.EventHandler(this.btn_insertar_Click);
            // 
            // cbx_activ_inactiv
            // 
            this.cbx_activ_inactiv.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.cbx_activ_inactiv.Items.AddRange(new object[] {
            "Activo",
            "Inactivo"});
            this.cbx_activ_inactiv.Location = new System.Drawing.Point(133, 109);
            this.cbx_activ_inactiv.Name = "cbx_activ_inactiv";
            this.cbx_activ_inactiv.Size = new System.Drawing.Size(144, 24);
            this.cbx_activ_inactiv.TabIndex = 11;
            // 
            // txt_monto
            // 
            this.txt_monto.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.txt_monto.Location = new System.Drawing.Point(133, 144);
            this.txt_monto.Name = "txt_monto";
            this.txt_monto.Size = new System.Drawing.Size(144, 23);
            this.txt_monto.TabIndex = 9;
            // 
            // txt_nombre
            // 
            this.txt_nombre.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.txt_nombre.Location = new System.Drawing.Point(133, 76);
            this.txt_nombre.Name = "txt_nombre";
            this.txt_nombre.Size = new System.Drawing.Size(144, 23);
            this.txt_nombre.TabIndex = 10;
            // 
            // lbl_monto
            // 
            this.lbl_monto.AutoSize = true;
            this.lbl_monto.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.lbl_monto.Location = new System.Drawing.Point(76, 144);
            this.lbl_monto.Name = "lbl_monto";
            this.lbl_monto.Size = new System.Drawing.Size(51, 17);
            this.lbl_monto.TabIndex = 6;
            this.lbl_monto.Text = "Monto:";
            // 
            // lbl_estado
            // 
            this.lbl_estado.AutoSize = true;
            this.lbl_estado.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.lbl_estado.Location = new System.Drawing.Point(71, 109);
            this.lbl_estado.Name = "lbl_estado";
            this.lbl_estado.Size = new System.Drawing.Size(56, 17);
            this.lbl_estado.TabIndex = 7;
            this.lbl_estado.Text = "Estado:";
            // 
            // lbl_nombre
            // 
            this.lbl_nombre.AutoSize = true;
            this.lbl_nombre.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.lbl_nombre.Location = new System.Drawing.Point(65, 76);
            this.lbl_nombre.Name = "lbl_nombre";
            this.lbl_nombre.Size = new System.Drawing.Size(62, 17);
            this.lbl_nombre.TabIndex = 8;
            this.lbl_nombre.Text = "Nombre:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.label1.Location = new System.Drawing.Point(12, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(197, 29);
            this.label1.TabIndex = 5;
            this.label1.Text = "Ingrese los datos";
            // 
            // btn_cancelar
            // 
            this.btn_cancelar.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.btn_cancelar.Location = new System.Drawing.Point(40, 189);
            this.btn_cancelar.Name = "btn_cancelar";
            this.btn_cancelar.Size = new System.Drawing.Size(75, 26);
            this.btn_cancelar.TabIndex = 12;
            this.btn_cancelar.Text = "Cancelar";
            this.btn_cancelar.UseVisualStyleBackColor = true;
            this.btn_cancelar.Click += new System.EventHandler(this.btn_cancelar_Click);
            // 
            // FormularioCliente
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(315, 245);
            this.Controls.Add(this.btn_cancelar);
            this.Controls.Add(this.btn_limpiar);
            this.Controls.Add(this.btn_insertar);
            this.Controls.Add(this.cbx_activ_inactiv);
            this.Controls.Add(this.txt_monto);
            this.Controls.Add(this.txt_nombre);
            this.Controls.Add(this.lbl_monto);
            this.Controls.Add(this.lbl_estado);
            this.Controls.Add(this.lbl_nombre);
            this.Controls.Add(this.label1);
            this.Name = "FormularioCliente";
            this.Text = "FormularioCliente";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_limpiar;
        private System.Windows.Forms.Button btn_insertar;
        private System.Windows.Forms.ComboBox cbx_activ_inactiv;
        private System.Windows.Forms.TextBox txt_monto;
        private System.Windows.Forms.TextBox txt_nombre;
        private System.Windows.Forms.Label lbl_monto;
        private System.Windows.Forms.Label lbl_estado;
        private System.Windows.Forms.Label lbl_nombre;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btn_cancelar;
    }
}