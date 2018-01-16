#pragma once

#include "Conexion.h" 
#include "Util.h"
#include "Producto.h"

namespace PPx1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Inicio
	/// </summary>
	public ref class Inicio : public System::Windows::Forms::Form
	{
	
	public:
		Inicio(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->conn = (gcnew Conexion())->getConexion();
			this->refrescarTabla();
		}

	protected:

		MySqlConnection^ conn;
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  datagridProductos;
	protected:
	private: System::Windows::Forms::Button^  btnAgregar;
	private: System::Windows::Forms::Button^  btnActualizar;
	private: System::Windows::Forms::Button^  btnEliminar;
	private: System::Windows::Forms::Label^  lblTitulo;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;
		void refrescarTabla(){
			this->datagridProductos->Rows->Clear(); //limpiar tabla
			this->conn->Open();
			MySqlCommand ^c = this->conn->CreateCommand();
			c->CommandText = L"SELECT * FROM producto;";
			ArrayList^ cols = gcnew ArrayList();
			cols->Add(L"Id");
			cols->Add(L"Nombre");
			cols->Add(L"Precio");
			cols->Add(L"Descripcion");
			Util::rellenarDatagrid(this->datagridProductos, cols, c->ExecuteReader());
			this->conn->Close();
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->datagridProductos = (gcnew System::Windows::Forms::DataGridView());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datagridProductos))->BeginInit();
			this->SuspendLayout();
			// 
			// datagridProductos
			// 
			this->datagridProductos->AllowUserToAddRows = false;
			this->datagridProductos->AllowUserToDeleteRows = false;
			this->datagridProductos->AllowUserToResizeRows = false;
			this->datagridProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->datagridProductos->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->datagridProductos->Location = System::Drawing::Point(3, 35);
			this->datagridProductos->MultiSelect = false;
			this->datagridProductos->Name = L"datagridProductos";
			this->datagridProductos->ReadOnly = true;
			this->datagridProductos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->datagridProductos->Size = System::Drawing::Size(360, 250);
			this->datagridProductos->TabIndex = 0;
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(371, 35);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(75, 23);
			this->btnAgregar->TabIndex = 1;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &Inicio::btnAgregar_Click);
			// 
			// btnActualizar
			// 
			this->btnActualizar->Location = System::Drawing::Point(371, 63);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(75, 23);
			this->btnActualizar->TabIndex = 2;
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->UseVisualStyleBackColor = true;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Inicio::btnActualizar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(371, 91);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 3;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &Inicio::btnEliminar_Click);
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Location = System::Drawing::Point(13, 13);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(105, 13);
			this->lblTitulo->TabIndex = 4;
			this->lblTitulo->Text = L"Productos existentes";
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(458, 285);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->datagridProductos);
			this->Name = L"Inicio";
			this->Text = L"Productos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datagridProductos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAgregar_Click(System::Object^  sender, System::EventArgs^  e) {
				Producto^ p = gcnew Producto();
				p->ShowDialog();
				refrescarTabla();
	}
private: System::Void btnActualizar_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection ^rows = this->datagridProductos->SelectedRows;
			 if (rows->Count>0)
			 {
				 String^ celda = rows[0]->Cells[0]->Value->ToString();				 
				 int id = int::Parse(celda);
				 Producto^ p = gcnew Producto();
				 p->setProducto(id);
				 p->ShowDialog();
				 refrescarTabla();
			 }
			 else
			 {
				 Util::mostrarError(L"No hay ninguna fila seleccionada!");
			 }
}
private: System::Void btnEliminar_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection ^rows = this->datagridProductos->SelectedRows;
			 if (rows->Count>0)
			 {
				String^ celda = rows[0]->Cells[0]->Value->ToString();
				int id = int::Parse(celda);
				Windows::Forms::DialogResult res = MessageBox::Show(L"Está seguro de eliminar el registro con el identificador " + id + "?", "Confirmación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (res == Windows::Forms::DialogResult::Yes)
				{
					this->conn->Open();
					MySqlCommand^ cmd = this->conn->CreateCommand();
					cmd->CommandText = L"DELETE FROM producto WHERE id="+id;
					cmd->ExecuteNonQuery();
					this->conn->Close();
					refrescarTabla();
				}
			 }
			 else
			 {
				 Util::mostrarError(L"No hay ninguna fila seleccionada!");
			 }
}
};
}
