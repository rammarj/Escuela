
#pragma once
	namespace Soccer {
	using namespace MySql::Data::MySqlClient;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de administrar
	/// </summary>
	public ref class administrar : public System::Windows::Forms::Form
	{
	public:
		administrar(void)
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
		~administrar()
		{
			if (components)
			{
				delete components;
				delete result;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label6;
	private: static System::Windows::Forms::Label^  lbl_registrados;

	private: System::Windows::Forms::TextBox^  txt_nombre;
	private: System::Windows::Forms::TextBox^  txt_division;


	private: System::Windows::Forms::DateTimePicker^  dtp_inicio;

	private: System::Windows::Forms::Button^  actualizar;
	private: MySql::Data::MySqlClient::MySqlDataReader^ result;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			lbl_registrados = (gcnew System::Windows::Forms::Label());
			this->txt_nombre = (gcnew System::Windows::Forms::TextBox());
			this->txt_division = (gcnew System::Windows::Forms::TextBox());
			this->dtp_inicio = (gcnew System::Windows::Forms::DateTimePicker());
			this->actualizar = (gcnew System::Windows::Forms::Button());
			

			String^ conectar = L"datasource=localhost;port=3306;username=root;password=i0sec";
			MySqlConnection^ conn = (gcnew MySqlConnection(conectar));
			MySqlCommand^ cmd = (gcnew MySqlCommand("select equipo.NOMBRE,equipo.INICIO,equipo.DIVISION from soccer.equipo", conn));				
			try{;
				conn->Open();
				this->result = cmd->ExecuteReader();
				this->result->Read();
			}
			catch (Exception^ ex){
				delete conectar;
				conn->Close();
				delete conn;
				delete cmd;
				delete result;
				MessageBox::Show(ex->ToString());
				delete ex;
				Application::Exit();
			}
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"nombre:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"fecha de comienzo:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"division:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(166, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"numero de jugadores registrados: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(136, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"estatus: ";
			// 
			// txt_nombre
			// 
			this->txt_nombre->Location = System::Drawing::Point(112, 37);
			this->txt_nombre->Name = L"txt_nombre";
			this->txt_nombre->Size = System::Drawing::Size(209, 20);
			this->txt_nombre->TabIndex = 7;
			this->txt_nombre->Text = this->result->GetString(0);
			// 
			// txt_division
			// 
			this->txt_division->Location = System::Drawing::Point(68, 139);
			this->txt_division->Name = L"txt_division";
			this->txt_division->Size = System::Drawing::Size(253, 20);
			this->txt_division->TabIndex = 9;
			this->txt_division->Text = this->result->GetString(2);
			// 
			// dtp_inicio
			// 
			this->dtp_inicio->Location = System::Drawing::Point(123, 103);
			this->dtp_inicio->Name = L"dtp_inicio";
			this->dtp_inicio->Size = System::Drawing::Size(198, 20);
			this->dtp_inicio->TabIndex = 10;
			this->dtp_inicio->Value = this->result->GetDateTime(1);
			// 
			// actualizar
			// 
			this->actualizar->Location = System::Drawing::Point(139, 178);
			this->actualizar->Name = L"actualizar";
			this->actualizar->Size = System::Drawing::Size(103, 23);
			this->actualizar->TabIndex = 11;
			this->actualizar->Text = L"actualizar";
			this->actualizar->UseVisualStyleBackColor = true;
			this->actualizar->Click += (gcnew System::EventHandler(this, &administrar::actualizar_Click));
			//
			// 
			// lbl_registrados
			// 
			lbl_registrados->AutoSize = true;
			lbl_registrados->Location = System::Drawing::Point(219, 73);
			lbl_registrados->Name = L"lbl_registrados";
			lbl_registrados->Size = System::Drawing::Size(13, 13);
			lbl_registrados->TabIndex = 6;
			
			conn->Close();
			delete conectar;
			delete conn;
			this->result->Close();
			delete cmd;
			delete result;
			update();
			// 
			// administrar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(358, 222);
			this->Controls->Add(this->actualizar);
			this->Controls->Add(this->dtp_inicio);
			this->Controls->Add(this->txt_division);
			this->Controls->Add(this->txt_nombre);
			this->Controls->Add(lbl_registrados);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"administrar";
			this->Text = L"administrar";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void actualizar_Click(System::Object^  sender, System::EventArgs^  e) {
					 
					 String^ conectar = L"datasource=localhost;port=3306;username=root;password=i0sec";
					 MySqlConnection^ conn = (gcnew MySqlConnection(conectar));
					 
					conn->Open();
					 MySqlCommand^ cmd = (gcnew MySqlCommand(L"update soccer.equipo set equipo.NOMBRE=@nombre " +
						 ", equipo.INICIO=@inicio, equipo.DIVISION=@division WHERE equipo.ID=1", conn));
					 cmd->Prepare();
					 try{
						 cmd->Parameters->AddWithValue("@nombre", this->txt_nombre->Text);
						 cmd->Parameters->AddWithValue("@inicio", this->dtp_inicio->Value);
						 cmd->Parameters->AddWithValue("@division", this->txt_division->Text);
						 cmd->ExecuteNonQuery();
						 MessageBox::Show(L"Echo!!", L"succes");
					 }
					 catch (Exception^ ex){ 
						 MessageBox::Show(ex->ToString(),"Error de query!");
					 }
					 delete conectar;
					 delete conn;
					 delete cmd;
					 conn->Close();
					 //delete result;

		}

				 public: static void update(){
					 String^ conectar = L"datasource=localhost;port=3306;username=root;password=i0sec";
					 MySqlConnection^ conn = (gcnew MySqlConnection(conectar));
					 MySqlDataReader^ read;
					 MySqlCommand^ cmd = (gcnew MySqlCommand(L"select count(*) from soccer.jugador;", conn));
					 try{
						 conn->Open();
						 read = cmd->ExecuteReader();
						 read->Read();
						 lbl_registrados->Text = "" + read->GetInt32(0);
					 }
					 catch (Exception^ ex){
						 MessageBox::Show(ex->ToString(), "Error de query!");
					 }
					 delete conectar;
					 delete conn;
					 delete cmd;
					 conn->Close();
					 read->Close();

				 }
};
}
