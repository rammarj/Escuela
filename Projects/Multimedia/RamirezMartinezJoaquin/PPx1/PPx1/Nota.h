#pragma once

namespace PPx1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Nota
	/// </summary>
	public ref class Nota : public System::Windows::Forms::Form
	{
	public:
		Nota(void)
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
		~Nota()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^  txt_nota;
	private: System::Windows::Forms::Button^  btn_aceptar;
	private: System::Windows::Forms::Button^  btn_cancelar;
	private: System::Windows::Forms::Label^  label1;

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
			this->txt_nota = (gcnew System::Windows::Forms::TextBox());
			this->btn_aceptar = (gcnew System::Windows::Forms::Button());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txt_nota
			// 
			this->txt_nota->Location = System::Drawing::Point(12, 30);
			this->txt_nota->Multiline = true;
			this->txt_nota->Name = L"txt_nota";
			this->txt_nota->Size = System::Drawing::Size(326, 67);
			this->txt_nota->TabIndex = 0;
			// 
			// btn_aceptar
			// 
			this->btn_aceptar->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn_aceptar->Location = System::Drawing::Point(12, 103);
			this->btn_aceptar->Name = L"btn_aceptar";
			this->btn_aceptar->Size = System::Drawing::Size(75, 23);
			this->btn_aceptar->TabIndex = 1;
			this->btn_aceptar->Text = L"aceptar";
			this->btn_aceptar->UseVisualStyleBackColor = true;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_cancelar->Location = System::Drawing::Point(263, 103);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(75, 23);
			this->btn_cancelar->TabIndex = 2;
			this->btn_cancelar->Text = L"cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L" Escribe una nota para esta venta";
			// 
			// Nota
			// 
			this->AcceptButton = this->btn_aceptar;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_cancelar;
			this->ClientSize = System::Drawing::Size(348, 131);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_cancelar);
			this->Controls->Add(this->btn_aceptar);
			this->Controls->Add(this->txt_nota);
			this->Name = L"Nota";
			this->Text = L"Nota";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
