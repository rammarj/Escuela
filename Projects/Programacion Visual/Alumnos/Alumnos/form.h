#pragma once

namespace Alumnos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de form
	/// </summary>
	public ref class form : public System::Windows::Forms::Form
	{
	public:
		form(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			inicializacionManual();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~form()
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

		MySqlConnectionStringBuilder^ mysqlstrb_conexion;
		MySqlConnection^ mysql_conexion;
		MySqlDataReader^ mysql_reader;
		MySqlCommand^ mysql_comando;
		DataGridView^ dtg_datos;
		DataGridViewTextBoxColumn^ columna_id;
		DataGridViewTextBoxColumn^ columna_nombre;
		DataGridViewTextBoxColumn^ columna_ap_paterno;
		DataGridViewTextBoxColumn^ columna_ap_materno;
		DataGridViewTextBoxColumn^ columna_fecha_nac;
		DataGridViewTextBoxColumn^ columna_editar;

		void inicializacionManual(){
			mysqlstrb_conexion = gcnew MySqlConnectionStringBuilder();
			mysql_conexion = gcnew MySqlConnection();
			dtg_datos = gcnew DataGridView();
			columna_id = gcnew DataGridViewTextBoxColumn();
			columna_nombre = gcnew DataGridViewTextBoxColumn();
			columna_ap_paterno = gcnew DataGridViewTextBoxColumn();
			columna_ap_materno = gcnew DataGridViewTextBoxColumn();
			columna_fecha_nac = gcnew DataGridViewTextBoxColumn();

			//preparando datos de conexion
			mysqlstrb_conexion->Server = "127.0.0.1";
			mysqlstrb_conexion->Port = 3309;
			mysqlstrb_conexion->UserID = "root";
			mysqlstrb_conexion->Password = "superpass";
			mysqlstrb_conexion->Database = "universidad";
			//indicar el string de conexion y esperando abrir
			mysql_conexion->ConnectionString = mysqlstrb_conexion->ToString();			
			
			//columnas
			columna_id->HeaderText = "Id";
			columna_nombre->HeaderText = "Nombre";
			columna_ap_paterno->HeaderText = "Apellido Paterno";
			columna_ap_materno->HeaderText = "Apellido Materno";
			columna_fecha_nac->HeaderText = "Fecha Nacimiento";

			//dtg_datos->Columns->Clear();
			columna_id->CellTemplate = gcnew DataGridViewTextBoxCell();
			columna_nombre->CellTemplate = gcnew DataGridViewTextBoxCell();
			columna_ap_paterno->CellTemplate = gcnew DataGridViewTextBoxCell();
			columna_ap_materno->CellTemplate = gcnew DataGridViewTextBoxCell();
			columna_fecha_nac->CellTemplate = gcnew DataGridViewTextBoxCell();	

			columna_id->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
			columna_nombre->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
			columna_ap_paterno->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
			columna_ap_materno->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
			columna_fecha_nac->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;

			dtg_datos->Text = L"Datos de alumnos";
			dtg_datos->Columns->Add(columna_id);
			dtg_datos->Columns->Add(columna_nombre);
			dtg_datos->Columns->Add(columna_ap_paterno);
			dtg_datos->Columns->Add(columna_ap_materno);
			dtg_datos->Columns->Add(columna_fecha_nac);

			llenadoDeDatos();

			this->Controls->Add(dtg_datos);
			this->Resize += gcnew EventHandler(this, &Alumnos::form::resizeWindowEvent);
			resizeWindowEvent(this, nullptr);
		}

		void llenadoDeDatos(){
			//dtg_datos->Rows->Clear();
			mysql_conexion->Open();
			mysql_comando = mysql_conexion->CreateCommand();
			mysql_comando->CommandText = "SELECT * FROM alumnos;";
			mysql_reader = mysql_comando->ExecuteReader();			
			while (mysql_reader->Read())
			{
				DataGridViewRow^ row = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ id = gcnew DataGridViewTextBoxCell();
				DataGridViewTextBoxCell^ nombre = gcnew DataGridViewTextBoxCell();
				DataGridViewTextBoxCell^ ap_paterno = gcnew DataGridViewTextBoxCell();
				DataGridViewTextBoxCell^ ap_materno = gcnew DataGridViewTextBoxCell();
				DataGridViewTextBoxCell^ fecha_nac = gcnew DataGridViewTextBoxCell();

				id->Value = mysql_reader->GetString(0);
				nombre->Value = mysql_reader->GetString(1);
				ap_paterno->Value = mysql_reader->GetString(2);
				ap_materno->Value = mysql_reader->GetString(3);
				fecha_nac->Value = mysql_reader->GetString(4);

				row->Cells->Add(id);
				row->Cells->Add(nombre);
				row->Cells->Add(ap_paterno);
				row->Cells->Add(ap_materno);
				row->Cells->Add(fecha_nac);

				dtg_datos->Rows->Add(row);
			}
			mysql_reader->Close();
			mysql_conexion->Close();
		}

		Void controlerClick(Object^ fuente, EventArgs^ e){
			
		}

		Void resizeWindowEvent(Object^ fuente, EventArgs^ e){
			this->dtg_datos->Bounds = Rectangle::FromLTRB(10, 24, Width - 25, Height - 45);
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(550,400);
			this->Text = L"Datos";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
