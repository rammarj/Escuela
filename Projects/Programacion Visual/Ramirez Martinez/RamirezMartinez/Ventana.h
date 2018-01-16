#pragma once

namespace RamirezMartinez {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Ventana
	/// </summary>
	public ref class Ventana : public System::Windows::Forms::Form
	{
	public:
		Ventana(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			inicializacionPersonalizada();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Ventana()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

		//componentes
		RadioButton^ rd_sum;
		RadioButton^ rd_rest;
		RadioButton^ rd_mult;
		RadioButton^ rd_div;
		CheckBox^ ch_invertir;
		TextBox^ txt_op1;
		TextBox^ txt_op2;
		Label^ lbl_res;
		GroupBox^ grpx_operaciones;

		void inicializacionPersonalizada(){
			this->rd_sum = gcnew RadioButton();
			this->rd_rest = gcnew RadioButton();
			this->rd_mult = gcnew RadioButton();
			this->rd_div = gcnew RadioButton();
			this->ch_invertir = gcnew CheckBox();
			this->txt_op1 = gcnew TextBox();
			this->txt_op2 = gcnew TextBox();
			this->lbl_res = gcnew Label();
			this->grpx_operaciones = gcnew GroupBox();

			//config de radios
			//suma
			this->rd_sum->Text = L"suma";
			this->rd_sum->CheckedChanged += gcnew EventHandler(this, &Ventana::cambioRadio);
			this->rd_sum->AutoSize = true;
			this->rd_sum->Location = Point(10,20);
			//resta
			this->rd_rest->Text = L"resta";
			this->rd_rest->CheckedChanged += gcnew EventHandler(this, &Ventana::cambioRadio);
			this->rd_rest->AutoSize = true;
			this->rd_rest->Location = Point(10, 50);
			//multi
			this->rd_mult->Text = L"multiplicacion";
			this->rd_mult->CheckedChanged += gcnew EventHandler(this, &Ventana::cambioRadio);
			this->rd_mult->AutoSize = true;
			this->rd_mult->Location = Point(10, 80);
			//div
			this->rd_div ->Text = L"division";
			this->rd_div->CheckedChanged += gcnew EventHandler(this, &Ventana::cambioRadio);
			this->rd_div->AutoSize = true;
			this->rd_div->Location = Point(10, 110);
			//group
			this->grpx_operaciones->Text = L"Operaciones";
			this->grpx_operaciones->Controls->Add(this->rd_sum);
			this->grpx_operaciones->Controls->Add(this->rd_rest);
			this->grpx_operaciones->Controls->Add(this->rd_mult);
			this->grpx_operaciones->Controls->Add(this->rd_div);
			this->grpx_operaciones->Location = Point(12,12);
			this->grpx_operaciones->AutoSize = true;

			//cajas de texto
			this->txt_op1->Location = Point(250, 20);
			this->txt_op1->Size = Drawing::Size(60,25);
			this->txt_op1->AutoSize = true;
			this->txt_op2->Location = Point(250, 50);
			this->txt_op2->Size = Drawing::Size(60, 25);
			this->txt_op2->AutoSize = true;
			this->lbl_res->Location = Point(250, 80);
			this->lbl_res->AutoSize = true;

			//checkbox
			this->ch_invertir->Text = L"invertir";
			this->ch_invertir->Location = Point(12, 170);
			this->ch_invertir->AutoSize = true;
			this->ch_invertir->CheckedChanged += gcnew EventHandler(this, &Ventana::cambioCheckbox);

			this->Controls->Add(this->grpx_operaciones);
			this->Controls->Add(this->txt_op1);
			this->Controls->Add(this->txt_op2);
			this->Controls->Add(this->lbl_res);
			this->Controls->Add(this->ch_invertir);

			this->StartPosition = FormStartPosition::CenterScreen;
			this->Size = Drawing::Size(400,250);
		}


		Void cambioRadio(Object^ fuente, EventArgs^ e){
			double op1 = 0;
			double op2 = 0;
			double res = 0;
			try{
				op1 = Double::Parse(this->txt_op1->Text);
				op2 = Double::Parse(this->txt_op2->Text);
				if (fuente == this->rd_sum && this->rd_sum->Checked)
				{
					res = op1 + op2;
				}
				else
				if (fuente == this->rd_rest && this->rd_rest->Checked)
				{
					if (this->ch_invertir->Checked)
					{
						res = op2 - op1;
					}
					else
					{
						res = op1 - op2;
					}
				}
				else
				if (fuente == this->rd_mult && this->rd_mult->Checked)
				{
					res = op1 * op2;
				}
				else
				if (fuente == this->rd_div && this->rd_div->Checked)
				{
					if (this->ch_invertir->Checked)
					{
						res = op2 / op1;
					}
					else
					{
						res = op1 / op2;
					}
				}
				this->lbl_res->Text = L"" + res;
			}
			catch (Exception^ e){
				MessageBox::Show(L"Error: "+e->Message, L"Error de ejecucion", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		Void cambioCheckbox(Object^ fuente, EventArgs^ e){
			double op1 = 0;
			double op2 = 0;
			double res = 0;
			try{
				op1 = Double::Parse(this->txt_op1->Text);
				op2 = Double::Parse(this->txt_op2->Text);
				if (this->ch_invertir->Checked)
				{
					if (this->rd_rest->Checked)
					{
						res = op2 - op1;
						this->lbl_res->Text = L"" + res;
					}
					if (this->rd_div->Checked)
					{
						res = op2 / op1;
						this->lbl_res->Text = L"" + res;
					}
				}
				else{
					if (this->rd_rest->Checked)
					{
						res = op1 - op2;
						this->lbl_res->Text = L"" + res;
					}
					if (this->rd_div->Checked)
					{
						res = op1 / op2;
						this->lbl_res->Text = L"" + res;
					}
				}
				
			}
			catch (Exception^ e){ }
			
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"Ventana";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
