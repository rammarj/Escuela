namespace ClienteDiffie
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
            this.btnIniciar = new System.Windows.Forms.Button();
            this.txtIP = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtPuerto = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnIniciar
            // 
            this.btnIniciar.Location = new System.Drawing.Point(226, 25);
            this.btnIniciar.Name = "btnIniciar";
            this.btnIniciar.Size = new System.Drawing.Size(139, 23);
            this.btnIniciar.TabIndex = 0;
            this.btnIniciar.Text = "Iniciar intercambio";
            this.btnIniciar.UseVisualStyleBackColor = true;
            this.btnIniciar.Click += new System.EventHandler(this.btnIniciar_Click);
            // 
            // txtIP
            // 
            this.txtIP.Location = new System.Drawing.Point(12, 28);
            this.txtIP.Name = "txtIP";
            this.txtIP.Size = new System.Drawing.Size(135, 20);
            this.txtIP.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(20, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "IP:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(161, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Puerto:";
            // 
            // txtPuerto
            // 
            this.txtPuerto.Location = new System.Drawing.Point(161, 28);
            this.txtPuerto.Name = "txtPuerto";
            this.txtPuerto.Size = new System.Drawing.Size(43, 20);
            this.txtPuerto.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(150, 31);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(10, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = ":";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(377, 66);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtPuerto);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtIP);
            this.Controls.Add(this.btnIniciar);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnIniciar;
        private System.Windows.Forms.TextBox txtIP;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtPuerto;
        private System.Windows.Forms.Label label3;
    }
}

