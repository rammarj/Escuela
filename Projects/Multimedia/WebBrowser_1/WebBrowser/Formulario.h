#pragma once
#include "FrmHistorial.h"

namespace WebBrowser_ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Formulario
	/// </summary>
	public ref class Formulario : public System::Windows::Forms::Form
	{
	public:
		Formulario(void)
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
		~Formulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::WebBrowser^  wb_principal;
	protected:

	private: System::Windows::Forms::Button^  btn_atras;
	private: System::Windows::Forms::Button^  btn_adelante;
	private: System::Windows::Forms::Button^  btn_refrescar;
	private: System::Windows::Forms::TextBox^  txt_uri;
	protected:




	private: System::Windows::Forms::Button^  btn_ir;
	private: System::Windows::Forms::LinkLabel^  lnk_verHistorial;
	private: System::ComponentModel::IContainer^  components;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Formulario::typeid));
			this->wb_principal = (gcnew System::Windows::Forms::WebBrowser());
			this->btn_atras = (gcnew System::Windows::Forms::Button());
			this->btn_adelante = (gcnew System::Windows::Forms::Button());
			this->btn_refrescar = (gcnew System::Windows::Forms::Button());
			this->txt_uri = (gcnew System::Windows::Forms::TextBox());
			this->btn_ir = (gcnew System::Windows::Forms::Button());
			this->lnk_verHistorial = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// wb_principal
			// 
			this->wb_principal->Location = System::Drawing::Point(0, 52);
			this->wb_principal->MinimumSize = System::Drawing::Size(20, 20);
			this->wb_principal->Name = L"wb_principal";
			this->wb_principal->Size = System::Drawing::Size(815, 407);
			this->wb_principal->TabIndex = 0;
			// 
			// btn_atras
			// 
			this->btn_atras->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_atras.Image")));
			this->btn_atras->Location = System::Drawing::Point(30, 16);
			this->btn_atras->Name = L"btn_atras";
			this->btn_atras->Size = System::Drawing::Size(31, 25);
			this->btn_atras->TabIndex = 1;
			this->btn_atras->UseVisualStyleBackColor = true;
			this->btn_atras->Click += gcnew System::EventHandler(this, &Formulario::btn_atras_Click);
			// 
			// btn_adelante
			// 
			this->btn_adelante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_adelante.Image")));
			this->btn_adelante->Location = System::Drawing::Point(67, 16);
			this->btn_adelante->Name = L"btn_adelante";
			this->btn_adelante->Size = System::Drawing::Size(31, 25);
			this->btn_adelante->TabIndex = 2;
			this->btn_adelante->UseVisualStyleBackColor = true;
			this->btn_adelante->Click += gcnew System::EventHandler(this, &Formulario::btn_adelante_Click);
			// 
			// btn_refrescar
			// 
			this->btn_refrescar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_refrescar.Image")));
			this->btn_refrescar->Location = System::Drawing::Point(104, 16);
			this->btn_refrescar->Name = L"btn_refrescar";
			this->btn_refrescar->Size = System::Drawing::Size(31, 25);
			this->btn_refrescar->TabIndex = 3;
			this->btn_refrescar->UseVisualStyleBackColor = true;
			this->btn_refrescar->Click += gcnew System::EventHandler(this, &Formulario::btn_refrescar_Click);
			// 
			// txt_uri
			// 
			this->txt_uri->Location = System::Drawing::Point(141, 19);
			this->txt_uri->Name = L"txt_uri";
			this->txt_uri->Size = System::Drawing::Size(479, 20);
			this->txt_uri->TabIndex = 4;
			this->txt_uri->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::txt_uri_KeyUp);
			// 
			// btn_ir
			// 
			this->btn_ir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_ir.Image")));
			this->btn_ir->Location = System::Drawing::Point(626, 16);
			this->btn_ir->Name = L"btn_ir";
			this->btn_ir->Size = System::Drawing::Size(75, 24);
			this->btn_ir->TabIndex = 5;
			this->btn_ir->Text = L"ir";
			this->btn_ir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_ir->UseVisualStyleBackColor = true;
			this->btn_ir->Click += gcnew System::EventHandler(this, &Formulario::btn_ir_Click);
			// 
			// lnk_verHistorial
			// 
			this->lnk_verHistorial->AutoSize = true;
			this->lnk_verHistorial->LinkColor = System::Drawing::Color::Maroon;
			this->lnk_verHistorial->Location = System::Drawing::Point(707, 22);
			this->lnk_verHistorial->Name = L"lnk_verHistorial";
			this->lnk_verHistorial->Size = System::Drawing::Size(60, 13);
			this->lnk_verHistorial->TabIndex = 6;
			this->lnk_verHistorial->TabStop = true;
			this->lnk_verHistorial->Text = L"ver historial";
			this->lnk_verHistorial->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Formulario::lnk_verHistorial_LinkClicked);
			this->lnk_verHistorial->Click += gcnew System::EventHandler(this, &Formulario::lnk_verHistorial_Click);
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 461);
			this->Controls->Add(this->lnk_verHistorial);
			this->Controls->Add(this->btn_ir);
			this->Controls->Add(this->txt_uri);
			this->Controls->Add(this->btn_refrescar);
			this->Controls->Add(this->btn_adelante);
			this->Controls->Add(this->btn_atras);
			this->Controls->Add(this->wb_principal);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void inicializacionP(){
			
		}

	private: System::Void lnk_verHistorial_Click(System::Object^  sender, System::EventArgs^  e) {

	}
private: System::Void btn_atras_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_principal->GoBack();
}
private: System::Void btn_adelante_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_principal->GoForward();
}
private: System::Void btn_refrescar_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_principal->Refresh();
}
private: System::Void btn_ir_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_principal->Navigate(this->txt_uri->Text);
}
private: System::Void lnk_verHistorial_LinkClicked(System::Object^  sender, LinkLabelLinkClickedEventArgs^  e) {
			 WebBrowser_::FrmHistorial^ h = gcnew FrmHistorial();
			 
			 Windows::Forms::DialogResult res = h->ShowDialog();
			 if (res == Windows::Forms::DialogResult::OK)
			 {
				 
			 }
}
private: System::Void txt_uri_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 this->btn_ir_Click(nullptr, EventArgs::Empty);
}
};
}
