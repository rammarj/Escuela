
#pragma once
#include "administrar.h"
namespace Soccer {
	using namespace MySql::Data::MySqlClient;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de jugador
	/// </summary>
	public ref class jugador : public System::Windows::Forms::Form
	{
	public:
		jugador(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~jugador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txt_nombre;
	private: System::Windows::Forms::TextBox^  txt_apellidos;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txt_numero;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txt_correo;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txt_telefono;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txt_direccion;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  aceptar;
	private: System::Windows::Forms::Button^  cancelar;































	private: System::ComponentModel::IContainer^  components;
			 //private: MySql::Data::MySqlClient::MySqlDataReader^ result;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_nombre = (gcnew System::Windows::Forms::TextBox());
			this->txt_apellidos = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_numero = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_correo = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txt_telefono = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_direccion = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->aceptar = (gcnew System::Windows::Forms::Button());
			this->cancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(200, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Crear jugador";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"nombre:";
			// 
			// txt_nombre
			// 
			this->txt_nombre->Location = System::Drawing::Point(80, 42);
			this->txt_nombre->Name = L"txt_nombre";
			this->txt_nombre->Size = System::Drawing::Size(147, 20);
			this->txt_nombre->TabIndex = 2;
			// 
			// txt_apellidos
			// 
			this->txt_apellidos->Location = System::Drawing::Point(302, 42);
			this->txt_apellidos->Name = L"txt_apellidos";
			this->txt_apellidos->Size = System::Drawing::Size(147, 20);
			this->txt_apellidos->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(245, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"apellidos:";
			// 
			// txt_numero
			// 
			this->txt_numero->Location = System::Drawing::Point(80, 68);
			this->txt_numero->Name = L"txt_numero";
			this->txt_numero->Size = System::Drawing::Size(147, 20);
			this->txt_numero->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"numero:";
			// 
			// txt_correo
			// 
			this->txt_correo->Location = System::Drawing::Point(302, 68);
			this->txt_correo->Name = L"txt_correo";
			this->txt_correo->Size = System::Drawing::Size(147, 20);
			this->txt_correo->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(256, 71);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"correo:";
			// 
			// txt_telefono
			// 
			this->txt_telefono->Location = System::Drawing::Point(80, 94);
			this->txt_telefono->Name = L"txt_telefono";
			this->txt_telefono->Size = System::Drawing::Size(147, 20);
			this->txt_telefono->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(29, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"telefono";
			// 
			// txt_direccion
			// 
			this->txt_direccion->Location = System::Drawing::Point(302, 94);
			this->txt_direccion->Name = L"txt_direccion";
			this->txt_direccion->Size = System::Drawing::Size(147, 20);
			this->txt_direccion->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(245, 97);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"direccion:";
			// 
			// aceptar
			// 
			this->aceptar->Location = System::Drawing::Point(152, 132);
			this->aceptar->Name = L"aceptar";
			this->aceptar->Size = System::Drawing::Size(75, 23);
			this->aceptar->TabIndex = 13;
			this->aceptar->Text = L"aceptar";
			this->aceptar->UseVisualStyleBackColor = true;
			this->aceptar->Click += gcnew System::EventHandler(this, &jugador::aceptar_Click);
			// 
			// cancelar
			// 
			this->cancelar->Location = System::Drawing::Point(267, 132);
			this->cancelar->Name = L"cancelar";
			this->cancelar->Size = System::Drawing::Size(75, 23);
			this->cancelar->TabIndex = 14;
			this->cancelar->Text = L"cancelar";
			this->cancelar->UseVisualStyleBackColor = true;
			this->cancelar->Click += gcnew System::EventHandler(this, &jugador::cancelar_Click);
			// 
			// jugador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(470, 176);
			this->Controls->Add(this->cancelar);
			this->Controls->Add(this->aceptar);
			this->Controls->Add(this->txt_direccion);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txt_telefono);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txt_correo);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txt_numero);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txt_apellidos);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txt_nombre);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"jugador";
			this->Text = L"jugador";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelar_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
private: System::Void aceptar_Click(System::Object^  sender, System::EventArgs^  e) {

			 String^ conectar = L"datasource=localhost;port=3306;username=root;password=i0sec";
			 MySqlConnection^ conn = (gcnew MySqlConnection(conectar));

			 conn->Open();
			 MySqlCommand^ cmd = (gcnew MySqlCommand("insert into"
				 +" soccer.jugador(NOMBRE,APELLIDOS,NUMERO,CORREO,TELEFONO,DIRECCION)"+
				 " values(@nombre, @apellidos, @numero, @correo, @telefono, @direccion)", conn));
			 cmd->Prepare();
			 try{
				 cmd->Parameters->AddWithValue("@nombre", this->txt_nombre->Text);
				 cmd->Parameters->AddWithValue("@apellidos", this->txt_apellidos->Text);
				 cmd->Parameters->AddWithValue("@numero", this->txt_numero->Text);
				 cmd->Parameters->AddWithValue("@correo", this->txt_correo->Text);
				 cmd->Parameters->AddWithValue("@telefono", this->txt_telefono->Text);
				 cmd->Parameters->AddWithValue("@direccion", this->txt_direccion->Text);
				 cmd->ExecuteNonQuery();
				 Soccer::administrar::update();
				 MessageBox::Show("Echo!!","Succes");
			 }
			 catch (Exception^ ex){
				 MessageBox::Show(ex->ToString(), "Error de query!");
			 }
			 delete conectar;
			 delete conn;
			 delete cmd;
			 conn->Close();
}
private: System::Void bindingSource1_CurrentChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
