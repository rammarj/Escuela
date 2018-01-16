namespace Lectura
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
            this.txtTexto = new System.Windows.Forms.TextBox();
            this.btnLeer = new System.Windows.Forms.Button();
            this.btnPausar = new System.Windows.Forms.Button();
            this.Continuar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtTexto
            // 
            this.txtTexto.Location = new System.Drawing.Point(12, 36);
            this.txtTexto.Multiline = true;
            this.txtTexto.Name = "txtTexto";
            this.txtTexto.Size = new System.Drawing.Size(517, 246);
            this.txtTexto.TabIndex = 0;
            // 
            // btnLeer
            // 
            this.btnLeer.Location = new System.Drawing.Point(12, 7);
            this.btnLeer.Name = "btnLeer";
            this.btnLeer.Size = new System.Drawing.Size(75, 23);
            this.btnLeer.TabIndex = 1;
            this.btnLeer.Text = "Leer";
            this.btnLeer.UseVisualStyleBackColor = true;
            this.btnLeer.Click += new System.EventHandler(this.btnLeer_Click);
            // 
            // btnPausar
            // 
            this.btnPausar.Location = new System.Drawing.Point(93, 7);
            this.btnPausar.Name = "btnPausar";
            this.btnPausar.Size = new System.Drawing.Size(75, 23);
            this.btnPausar.TabIndex = 2;
            this.btnPausar.Text = "Pausar";
            this.btnPausar.UseVisualStyleBackColor = true;
            this.btnPausar.Click += new System.EventHandler(this.btnPausar_Click);
            // 
            // Continuar
            // 
            this.Continuar.Location = new System.Drawing.Point(175, 7);
            this.Continuar.Name = "Continuar";
            this.Continuar.Size = new System.Drawing.Size(75, 23);
            this.Continuar.TabIndex = 3;
            this.Continuar.Text = "Continuar";
            this.Continuar.UseVisualStyleBackColor = true;
            this.Continuar.Click += new System.EventHandler(this.Continuar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(532, 284);
            this.Controls.Add(this.Continuar);
            this.Controls.Add(this.btnPausar);
            this.Controls.Add(this.btnLeer);
            this.Controls.Add(this.txtTexto);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtTexto;
        private System.Windows.Forms.Button btnLeer;
        private System.Windows.Forms.Button btnPausar;
        private System.Windows.Forms.Button Continuar;
    }
}

