#pragma once
#include "Inicio.h"

namespace PPx1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txt_usuario;
	private: System::Windows::Forms::TextBox^  txt_password;
	private: System::Windows::Forms::Button^  btn_login;
	private: PPx1::Conexion^ conexion;
	private:PPx1::Inicio^ frm_inicio;

	private: System::Windows::Forms::Label^  lbl_errores;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_usuario = (gcnew System::Windows::Forms::TextBox());
			this->txt_password = (gcnew System::Windows::Forms::TextBox());
			this->btn_login = (gcnew System::Windows::Forms::Button());
			this->lbl_errores = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(0, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(260, 179);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(263, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Usuario:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(263, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Contraseña:";
			// 
			// txt_usuario
			// 
			this->txt_usuario->Location = System::Drawing::Point(266, 37);
			this->txt_usuario->Name = L"txt_usuario";
			this->txt_usuario->Size = System::Drawing::Size(159, 20);
			this->txt_usuario->TabIndex = 3;
			// 
			// txt_password
			// 
			this->txt_password->Location = System::Drawing::Point(266, 76);
			this->txt_password->Name = L"txt_password";
			this->txt_password->Size = System::Drawing::Size(159, 20);
			this->txt_password->TabIndex = 4;
			this->txt_password->UseSystemPasswordChar = true;
			// 
			// btn_login
			// 
			this->btn_login->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btn_login->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_login->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_login.Image")));
			this->btn_login->Location = System::Drawing::Point(266, 125);
			this->btn_login->Name = L"btn_login";
			this->btn_login->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->btn_login->Size = System::Drawing::Size(159, 29);
			this->btn_login->TabIndex = 5;
			this->btn_login->Text = L"Log In";
			this->btn_login->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->btn_login->UseVisualStyleBackColor = false;
			this->btn_login->Click += gcnew System::EventHandler(this, &Login::btn_login_Click);
			// 
			// lbl_errores
			// 
			this->lbl_errores->AutoSize = true;
			this->lbl_errores->Location = System::Drawing::Point(183, 151);
			this->lbl_errores->Name = L"lbl_errores";
			this->lbl_errores->Size = System::Drawing::Size(0, 13);
			this->lbl_errores->TabIndex = 6;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(266, 102);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(60, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"mostrar";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckStateChanged += gcnew System::EventHandler(this, &Login::checkBox1_CheckStateChanged);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(447, 177);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->lbl_errores);
			this->Controls->Add(this->btn_login);
			this->Controls->Add(this->txt_password);
			this->Controls->Add(this->txt_usuario);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Login";
			this->Text = L"Login";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*Click de boton login!*/
	private: System::Void btn_login_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->lbl_errores->Text = L"";
				 String^ usuario = this->txt_usuario->Text;
				 String^ pass = this->txt_password->Text;
				 MySqlConnection ^conn = this->conexion->getConexion();
				 conn->Open();
				 /*Comando SQL*/
				 MySqlCommand^ cmd =conn->CreateCommand();
				 cmd->CommandText = L"SELECT id FROM usuarios WHERE usuario=@usuario AND password=@password";
				 cmd->Prepare();/*Sentencias preparadas para evitar inyeccion SQL*/
				 MySqlDataReader^ res = nullptr;
				 try{/*buena practica de preparar tratamiento de errores cuando es propenso*/
					 /*Reemplazado de datos*/
					 cmd->Parameters->AddWithValue("@usuario", usuario);
					 cmd->Parameters->AddWithValue("@password", pass);
					 res = cmd->ExecuteReader();
					 if (res->HasRows){ /*El usuario existe*/
						 res->Read(); 
						 this->frm_inicio->setId(res->GetInt32(0));
						 this->frm_inicio->Show();/*mostrar el formulario de bienvenida*/
						 this->Hide();
					 }
					 else{/*mostrar error si no existe el usuario*/
						 this->lbl_errores->Text = L"Usuario y/o contraseña incorrecta.";
					 }
				 }
				 catch (Exception^ ex){/*captura de error*/
					 this->lbl_errores->Text = "Error de consulta!";
					 delete ex;
				 }
				 finally{
					 conn->Close(); /*siempre debe realizarse aunque no se haya ejecutado con exito la consulta*/
				 }		
				 delete conn;
	}
	/*Inicializacion sin utilizar el helper GUI*/
	private: System::Void inicializacionPersonalizada(){
		//
		this->txt_usuario->KeyUp += gcnew KeyEventHandler(this, &PPx1::Login::txtbox_KeyUp);
		this->txt_password->KeyUp += gcnew KeyEventHandler(this, &PPx1::Login::txtbox_KeyUp);
		//
		this->conexion = gcnew PPx1::Conexion();
		this->frm_inicio = gcnew PPx1::Inicio();
		this->frm_inicio->FormClosing += gcnew FormClosingEventHandler(this, &Login::frm_inicioClosing);
		this->lbl_errores->ForeColor = Color::Red;
		//
		ToolStripMenuItem^ tsi_cerrar_sess = this->frm_inicio->tsmi_cerrarSesión;
		tsi_cerrar_sess->Click += gcnew EventHandler(this, &Login::cerrar_sesion_tsi_Click);
		this->StartPosition = FormStartPosition::CenterScreen;
	}
	private: System::Void frm_inicioClosing(Object^  sender, FormClosingEventArgs^ e) {
		this->txt_usuario->Text = "";
		this->txt_password->Text = "";
		this->frm_inicio->wmp_media_player->Ctlcontrols->pause();
		this->frm_inicio->Hide();
		this->Show();
		e->Cancel = true;
	}
	private: System::Void checkBox1_CheckStateChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkBox1->Checked)
		{
			this->txt_password->UseSystemPasswordChar = false;
		}
		else{
			this->txt_password->UseSystemPasswordChar = true;
		}
	}
	private: System::Void txtbox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter){
			this->btn_login_Click(nullptr, EventArgs::Empty);
		}
	}
	private: System::Void cerrar_sesion_tsi_Click(System::Object^  sender, System::EventArgs^  e){
				frm_inicioClosing(this->frm_inicio, gcnew FormClosingEventArgs(CloseReason::FormOwnerClosing,false));
	}	
};
}
