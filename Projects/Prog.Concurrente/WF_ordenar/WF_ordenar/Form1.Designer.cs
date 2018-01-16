

namespace WF_ordenar
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
            this.txt_burbuja = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txt_insercion = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_quicksort = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txt_seleccion = new System.Windows.Forms.TextBox();
            this.btn_iniciar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txt_burbuja
            // 
            this.txt_burbuja.Location = new System.Drawing.Point(71, 12);
            this.txt_burbuja.Multiline = true;
            this.txt_burbuja.Name = "txt_burbuja";
            this.txt_burbuja.Size = new System.Drawing.Size(979, 98);
            this.txt_burbuja.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(42, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "burbuja";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 235);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "insercion";
            // 
            // txt_insercion
            // 
            this.txt_insercion.Location = new System.Drawing.Point(72, 232);
            this.txt_insercion.Multiline = true;
            this.txt_insercion.Name = "txt_insercion";
            this.txt_insercion.Size = new System.Drawing.Size(979, 99);
            this.txt_insercion.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(24, 119);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "quik sort";
            // 
            // txt_quicksort
            // 
            this.txt_quicksort.Location = new System.Drawing.Point(72, 116);
            this.txt_quicksort.Multiline = true;
            this.txt_quicksort.Name = "txt_quicksort";
            this.txt_quicksort.Size = new System.Drawing.Size(979, 110);
            this.txt_quicksort.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(23, 340);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "seleccion";
            // 
            // txt_seleccion
            // 
            this.txt_seleccion.Location = new System.Drawing.Point(71, 337);
            this.txt_seleccion.Multiline = true;
            this.txt_seleccion.Name = "txt_seleccion";
            this.txt_seleccion.Size = new System.Drawing.Size(979, 72);
            this.txt_seleccion.TabIndex = 6;
            // 
            // btn_iniciar
            // 
            this.btn_iniciar.Location = new System.Drawing.Point(26, 415);
            this.btn_iniciar.Name = "btn_iniciar";
            this.btn_iniciar.Size = new System.Drawing.Size(75, 23);
            this.btn_iniciar.TabIndex = 8;
            this.btn_iniciar.Text = "iniciar";
            this.btn_iniciar.UseVisualStyleBackColor = true;
            this.btn_iniciar.Click += new System.EventHandler(this.btn_iniciar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1063, 441);
            this.Controls.Add(this.btn_iniciar);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txt_seleccion);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txt_quicksort);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txt_insercion);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txt_burbuja);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txt_burbuja;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txt_insercion;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt_quicksort;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txt_seleccion;
        private System.Windows.Forms.Button btn_iniciar;
    }
}

