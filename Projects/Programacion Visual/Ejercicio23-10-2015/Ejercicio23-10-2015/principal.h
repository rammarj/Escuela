#pragma once

namespace Ejercicio23102015 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de principal
	/// </summary>
	public ref class principal : public System::Windows::Forms::Form
	{
	public:
		principal(void)
		{
			InitializeComponent();
			inicializacionPersonalizada();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~principal()
		{
			if (components)
			{
				delete components;
			}
			if (rdm)
			{
				delete rdm;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;
		Button^ btn_generar;
		Button^ btn_limpiar;
		TextBox^ caja1;
		TextBox^ caja2;
		TextBox^ caja3;
		Random^ rdm;

		void inicializacionPersonalizada(){
			this->btn_generar = gcnew Button();
			this->btn_limpiar = gcnew Button();
			this->caja1 = gcnew TextBox();
			this->caja2 = gcnew TextBox();
			this->caja3 = gcnew TextBox();
			this->rdm = gcnew Random();
			this->SuspendLayout();
			// caja1
			this->caja1->Location = Point(5, 5);
			this->caja1->Size = Drawing::Size(90,23);
			this->caja1->Text = "0";
			this->caja1->Enabled = false;
			//caja2
			this->caja2->Location = Point(105, 5);
			this->caja2->Size = Drawing::Size(90, 23);
			this->caja2->Text = "0";
			this->caja2->Enabled = false;
			//caja3
			this->caja3->Location = Point(205, 5);
			this->caja3->Size = Drawing::Size(90, 23);
			this->caja3->Text = "0";
			this->caja3->Enabled = false;
			//btn generar
			this->btn_generar->Location = Point(45,40);
			this->btn_generar->Size = Drawing::Size(75,23);
			this->btn_generar->Text = "generar";
			this->btn_generar->TabIndex = 0;
			this->btn_generar->Click += gcnew EventHandler(this, &principal::eventosClick);

			//btn limpiar
			this->btn_limpiar->Location = Point(200, 40);
			this->btn_limpiar->Size = Drawing::Size(75, 23);
			this->btn_limpiar->Text = "limpiar";
			this->btn_limpiar->TabIndex = 0;
			this->btn_limpiar->Enabled = false;
			this->btn_limpiar->Click += gcnew EventHandler(this, &principal::eventosClick);
			///
			this->Controls->Add(this->caja1);
			this->Controls->Add(this->caja2);
			this->Controls->Add(this->caja3);
			this->Controls->Add(this->btn_generar);
			this->Controls->Add(this->btn_limpiar);

			this->Size = Drawing::Size(320, 120);

			this->ResumeLayout();
			this->PerformLayout();
		}

		Void eventosClick(Object^ obj, EventArgs^ e){
			if (obj == btn_generar){
				int inicio = 100;
				int fin = 1000;
				this->caja1->Text = L"" + rdm->Next(inicio,fin);
				this->caja2->Text = L"" + rdm->Next(inicio, fin);
				this->caja3->Text = L"" + rdm->Next(inicio, fin);
				this->btn_limpiar->Enabled = true;
			}
			else if (obj == btn_limpiar){
				this->caja1->Text = "0";
				this->caja2->Text = "0";
				this->caja3->Text = "0";
				this->btn_limpiar->Enabled = false;
			}
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
			this->Text = L"Numeros random";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
