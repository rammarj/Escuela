#pragma once
#include "Conexion.h"
namespace PPx1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AgregarProducto
	/// </summary>
	public ref class AgregarProducto : public System::Windows::Forms::Form
	{
	public:
		AgregarProducto(void)
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
		~AgregarProducto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::TextBox^  txt_cantidad;
			System::Windows::Forms::ComboBox^  cbx_producto;
			System::Windows::Forms::Button^  btn_aceptar;
			System::Windows::Forms::Button^  btn_cancelar;
	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_cantidad = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cbx_producto = (gcnew System::Windows::Forms::ComboBox());
			this->btn_aceptar = (gcnew System::Windows::Forms::Button());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Producto:";
			// 
			// txt_cantidad
			// 
			this->txt_cantidad->Location = System::Drawing::Point(80, 41);
			this->txt_cantidad->Name = L"txt_cantidad";
			this->txt_cantidad->Size = System::Drawing::Size(172, 20);
			this->txt_cantidad->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Cantidad:";
			// 
			// cbx_producto
			// 
			this->cbx_producto->FormattingEnabled = true;
			this->cbx_producto->Location = System::Drawing::Point(80, 15);
			this->cbx_producto->Name = L"cbx_producto";
			this->cbx_producto->Size = System::Drawing::Size(172, 21);
			this->cbx_producto->TabIndex = 4;
			// 
			// btn_aceptar
			// 
			this->btn_aceptar->Location = System::Drawing::Point(15, 77);
			this->btn_aceptar->Name = L"btn_aceptar";
			this->btn_aceptar->Size = System::Drawing::Size(75, 23);
			this->btn_aceptar->TabIndex = 5;
			this->btn_aceptar->Text = L"aceptar";
			this->btn_aceptar->UseVisualStyleBackColor = true;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->Location = System::Drawing::Point(177, 77);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(75, 23);
			this->btn_cancelar->TabIndex = 6;
			this->btn_cancelar->Text = L"cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = true;
			// 
			// AgregarProducto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(268, 122);
			this->Controls->Add(this->btn_cancelar);
			this->Controls->Add(this->btn_aceptar);
			this->Controls->Add(this->cbx_producto);
			this->Controls->Add(this->txt_cantidad);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AgregarProducto";
			this->Text = L"AgregarProducto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
		void inicializacionPersonalizada(){
			Conexion^ conexion = gcnew Conexion();
			MySqlConnection^ mysql_conn =  conexion->getConexion();
			mysql_conn->Open();
			MySqlCommand^ cmd = mysql_conn->CreateCommand();
			cmd->CommandText = L"SELECT nombre FROM productos";
			MySqlDataReader^ res = cmd->ExecuteReader();
			while (res->Read())
			{
				this->cbx_producto->Items->Add(res->GetString(0));
			}
			mysql_conn->Close();
		}


};
}
