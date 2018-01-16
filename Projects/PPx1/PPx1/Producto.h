#pragma once

#include "Conexion.h"
#include "Util.h"

namespace PPx1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Producto
	/// </summary>
	public ref class Producto : public System::Windows::Forms::Form
	{
	public:
		Producto(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->crear = true;
			this->conn = (gcnew Conexion())->getConexion();			
		}

		void setProducto(int id){
			this->Text = L"Actualizar producto";
			this->btnAceptar->Text = L"Actualizar";
			this->conn->Open();
			MySqlCommand^ cmd = this->conn->CreateCommand();
			cmd->CommandText = L"SELECT * FROM producto WHERE id="+id;
			MySqlDataReader^reader = cmd->ExecuteReader();
			if (reader->Read())
			{
				this->id = reader->GetInt32(0);
				this->crear = false;
				String^ nombre = reader->GetString(1);
				String ^precio = reader->GetString(2);
				String ^descripcion = reader->GetString(3);

				this->txtNombre->Text = nombre;
				this->txtPrecio->Text = precio;
				this->txtDescripcion->Text = descripcion;
			}
			this->conn->Close();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Producto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtNombre;
	private: System::Windows::Forms::TextBox^  txtPrecio;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtDescripcion;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnAceptar;
	private: System::Windows::Forms::Button^  btnCancelar;
	protected:


	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool crear;
		int id;
		MySqlConnection^ conn;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre:";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(114, 18);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 20);
			this->txtNombre->TabIndex = 1;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(114, 44);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(100, 20);
			this->txtPrecio->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Precio:";
			// 
			// txtDescripcion
			// 
			this->txtDescripcion->Location = System::Drawing::Point(114, 70);
			this->txtDescripcion->Name = L"txtDescripcion";
			this->txtDescripcion->Size = System::Drawing::Size(100, 20);
			this->txtDescripcion->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(48, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Descripcion:";
			// 
			// btnAceptar
			// 
			this->btnAceptar->Location = System::Drawing::Point(142, 109);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(75, 23);
			this->btnAceptar->TabIndex = 6;
			this->btnAceptar->Text = L"Crear";
			this->btnAceptar->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &Producto::btnAceptar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(39, 109);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(75, 23);
			this->btnCancelar->TabIndex = 7;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &Producto::btnCancelar_Click);
			// 
			// Producto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(253, 143);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->txtDescripcion);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label1);
			this->Name = L"Producto";
			this->Text = L"Crear producto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnCancelar_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
private: System::Void btnAceptar_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 float precio = float::Parse(this->txtPrecio->Text);
				 this->conn->Open();
				 MySqlCommand ^cmd = this->conn->CreateCommand();
				 cmd->Prepare();
				 if (this->crear)
				 {
					 cmd->CommandText = L"INSERT INTO producto VALUES(NULL, @nombre,@precio,@descripcion);";
				 }
				 else{
					 cmd->CommandText = L"UPDATE producto SET nombre=@nombre, precio=@precio, descripcion=@descripcion WHERE id=" + this->id;
				 }
				 cmd->Parameters->AddWithValue("@nombre", this->txtNombre->Text);
				 cmd->Parameters->AddWithValue("@precio", precio);
				 cmd->Parameters->AddWithValue("@descripcion", this->txtDescripcion->Text);
				 cmd->ExecuteNonQuery();

				 this->conn->Close();
				 this->Close();
			 }
			 catch (Exception^ex){
				 Util::mostrarError(ex->Message);
			 }		 
}
};
}
