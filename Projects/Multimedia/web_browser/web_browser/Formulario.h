#pragma once
#include "Historial.h"
namespace web_browser {

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

	protected:
	private: System::Windows::Forms::Button^  bt_regresar;
	private: System::Windows::Forms::Button^  btn_adelante;
	private: System::Windows::Forms::Button^  btn_recargar;
	private: System::Windows::Forms::TextBox^  txt_uri;

	private: System::Windows::Forms::Button^  btn_ir;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Formulario::typeid));
			this->wb_principal = (gcnew System::Windows::Forms::WebBrowser());
			this->bt_regresar = (gcnew System::Windows::Forms::Button());
			this->btn_adelante = (gcnew System::Windows::Forms::Button());
			this->btn_recargar = (gcnew System::Windows::Forms::Button());
			this->txt_uri = (gcnew System::Windows::Forms::TextBox());
			this->btn_ir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// wb_principal
			// 
			this->wb_principal->Location = System::Drawing::Point(1, 38);
			this->wb_principal->MinimumSize = System::Drawing::Size(20, 20);
			this->wb_principal->Name = L"wb_principal";
			this->wb_principal->Size = System::Drawing::Size(851, 405);
			this->wb_principal->TabIndex = 0;
			this->wb_principal->Navigated += gcnew System::Windows::Forms::WebBrowserNavigatedEventHandler(this, &Formulario::wb_principal_Navigated);
			// 
			// bt_regresar
			// 
			this->bt_regresar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bt_regresar.Image")));
			this->bt_regresar->Location = System::Drawing::Point(54, 8);
			this->bt_regresar->Name = L"bt_regresar";
			this->bt_regresar->Size = System::Drawing::Size(37, 24);
			this->bt_regresar->TabIndex = 1;
			this->bt_regresar->UseVisualStyleBackColor = true;
			this->bt_regresar->Click += gcnew System::EventHandler(this, &Formulario::bt_regresar_Click);
			// 
			// btn_adelante
			// 
			this->btn_adelante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_adelante.Image")));
			this->btn_adelante->Location = System::Drawing::Point(88, 8);
			this->btn_adelante->Name = L"btn_adelante";
			this->btn_adelante->Size = System::Drawing::Size(37, 24);
			this->btn_adelante->TabIndex = 2;
			this->btn_adelante->UseVisualStyleBackColor = true;
			this->btn_adelante->Click += gcnew System::EventHandler(this, &Formulario::btn_adelante_Click);
			// 
			// btn_recargar
			// 
			this->btn_recargar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_recargar.Image")));
			this->btn_recargar->Location = System::Drawing::Point(131, 8);
			this->btn_recargar->Name = L"btn_recargar";
			this->btn_recargar->Size = System::Drawing::Size(37, 24);
			this->btn_recargar->TabIndex = 3;
			this->btn_recargar->UseVisualStyleBackColor = true;
			this->btn_recargar->Click += gcnew System::EventHandler(this, &Formulario::btn_recargar_Click);
			// 
			// txt_uri
			// 
			this->txt_uri->Location = System::Drawing::Point(175, 8);
			this->txt_uri->Name = L"txt_uri";
			this->txt_uri->Size = System::Drawing::Size(535, 20);
			this->txt_uri->TabIndex = 4;
			this->txt_uri->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario::txt_uri_KeyUp);
			// 
			// btn_ir
			// 
			this->btn_ir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_ir.Image")));
			this->btn_ir->Location = System::Drawing::Point(716, 8);
			this->btn_ir->Name = L"btn_ir";
			this->btn_ir->Size = System::Drawing::Size(52, 24);
			this->btn_ir->TabIndex = 5;
			this->btn_ir->Text = L"ir";
			this->btn_ir->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_ir->UseVisualStyleBackColor = true;
			this->btn_ir->Click += gcnew System::EventHandler(this, &Formulario::btn_ir_Click);
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 447);
			this->Controls->Add(this->btn_ir);
			this->Controls->Add(this->txt_uri);
			this->Controls->Add(this->btn_recargar);
			this->Controls->Add(this->btn_adelante);
			this->Controls->Add(this->bt_regresar);
			this->Controls->Add(this->wb_principal);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bt_regresar_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->wb_principal->GoBack();
	}
private: System::Void btn_adelante_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_principal->GoForward();
}
private: System::Void btn_recargar_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_principal->Refresh();
}
private: System::Void btn_ir_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_principal->Navigate(this->txt_uri->Text);
}
private: System::Void txt_uri_KeyUp(System::Object^  sender, KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_ir_Click(nullptr, EventArgs::Empty);
			 }
}

private: System::Void wb_principal_Navigated(System::Object^  sender, System::Windows::Forms::WebBrowserNavigatedEventArgs^  e) {
			 this->txt_uri->Text = this->wb_principal->Url->ToString();
			 this->wb_principal->Focus();
			 this->Text = this->wb_principal->DocumentTitle;
}
};
}
