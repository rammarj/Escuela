namespace ClienteWS_validar_datos_Rocio
{
    partial class FormularioPagar
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
            this.label1 = new System.Windows.Forms.Label();
            this.lbl1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.lbl_id = new System.Windows.Forms.Label();
            this.lbl_nombre = new System.Windows.Forms.Label();
            this.lbl_estado = new System.Windows.Forms.Label();
            this.txt_monto = new System.Windows.Forms.TextBox();
            this.btn_pagar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.label1.Location = new System.Drawing.Point(12, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(170, 29);
            this.label1.TabIndex = 6;
            this.label1.Text = "Datos de pago";
            // 
            // lbl1
            // 
            this.lbl1.AutoSize = true;
            this.lbl1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.lbl1.Location = new System.Drawing.Point(72, 65);
            this.lbl1.Name = "lbl1";
            this.lbl1.Size = new System.Drawing.Size(25, 17);
            this.lbl1.TabIndex = 9;
            this.lbl1.Text = "ID:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.label2.Location = new System.Drawing.Point(35, 93);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 17);
            this.label2.TabIndex = 9;
            this.label2.Text = "Nombre:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.label3.Location = new System.Drawing.Point(41, 120);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(56, 17);
            this.label3.TabIndex = 9;
            this.label3.Text = "Estado:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.label4.Location = new System.Drawing.Point(46, 148);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(51, 17);
            this.label4.TabIndex = 9;
            this.label4.Text = "Monto:";
            // 
            // lbl_id
            // 
            this.lbl_id.AutoSize = true;
            this.lbl_id.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.lbl_id.Location = new System.Drawing.Point(103, 65);
            this.lbl_id.Name = "lbl_id";
            this.lbl_id.Size = new System.Drawing.Size(0, 17);
            this.lbl_id.TabIndex = 9;
            // 
            // lbl_nombre
            // 
            this.lbl_nombre.AutoSize = true;
            this.lbl_nombre.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.lbl_nombre.Location = new System.Drawing.Point(103, 93);
            this.lbl_nombre.Name = "lbl_nombre";
            this.lbl_nombre.Size = new System.Drawing.Size(0, 17);
            this.lbl_nombre.TabIndex = 9;
            // 
            // lbl_estado
            // 
            this.lbl_estado.AutoSize = true;
            this.lbl_estado.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            this.lbl_estado.Location = new System.Drawing.Point(103, 120);
            this.lbl_estado.Name = "lbl_estado";
            this.lbl_estado.Size = new System.Drawing.Size(0, 17);
            this.lbl_estado.TabIndex = 9;
            // 
            // txt_monto
            // 
            this.txt_monto.Location = new System.Drawing.Point(106, 148);
            this.txt_monto.Name = "txt_monto";
            this.txt_monto.Size = new System.Drawing.Size(88, 20);
            this.txt_monto.TabIndex = 10;
            // 
            // btn_pagar
            // 
            this.btn_pagar.Location = new System.Drawing.Point(119, 174);
            this.btn_pagar.Name = "btn_pagar";
            this.btn_pagar.Size = new System.Drawing.Size(75, 23);
            this.btn_pagar.TabIndex = 11;
            this.btn_pagar.Text = "Pagar";
            this.btn_pagar.UseVisualStyleBackColor = true;
            this.btn_pagar.Click += new System.EventHandler(this.btn_pagar_Click);
            // 
            // FormularioPagar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(225, 209);
            this.Controls.Add(this.btn_pagar);
            this.Controls.Add(this.txt_monto);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.lbl_estado);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.lbl_nombre);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.lbl_id);
            this.Controls.Add(this.lbl1);
            this.Controls.Add(this.label1);
            this.Name = "FormularioPagar";
            this.Text = "FormularioPagar";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lbl1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lbl_id;
        private System.Windows.Forms.Label lbl_nombre;
        private System.Windows.Forms.Label lbl_estado;
        private System.Windows.Forms.TextBox txt_monto;
        private System.Windows.Forms.Button btn_pagar;
    }
}