#pragma once

namespace web_browser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historial
	/// </summary>
	public ref class Historial : public System::Windows::Forms::Form
	{
	public:
		Historial(void)
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
		~Historial()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ListBox^  lbx_historial;
	protected:
	private: System::Windows::Forms::Button^  btn_borrar_historial;
	private: System::Windows::Forms::Button^  btn_cerrar;

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
			this->lbx_historial = (gcnew System::Windows::Forms::ListBox());
			this->btn_borrar_historial = (gcnew System::Windows::Forms::Button());
			this->btn_cerrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbx_historial
			// 
			this->lbx_historial->FormattingEnabled = true;
			this->lbx_historial->Location = System::Drawing::Point(0, 1);
			this->lbx_historial->Name = L"lbx_historial";
			this->lbx_historial->Size = System::Drawing::Size(449, 407);
			this->lbx_historial->TabIndex = 0;
			// 
			// btn_borrar_historial
			// 
			this->btn_borrar_historial->Location = System::Drawing::Point(13, 415);
			this->btn_borrar_historial->Name = L"btn_borrar_historial";
			this->btn_borrar_historial->Size = System::Drawing::Size(75, 23);
			this->btn_borrar_historial->TabIndex = 1;
			this->btn_borrar_historial->Text = L"borrar historial";
			this->btn_borrar_historial->UseVisualStyleBackColor = true;
			// 
			// btn_cerrar
			// 
			this->btn_cerrar->Location = System::Drawing::Point(363, 415);
			this->btn_cerrar->Name = L"btn_cerrar";
			this->btn_cerrar->Size = System::Drawing::Size(75, 23);
			this->btn_cerrar->TabIndex = 2;
			this->btn_cerrar->Text = L"cerrar";
			this->btn_cerrar->UseVisualStyleBackColor = true;
			// 
			// Historial
			// 
			this->AcceptButton = this->btn_borrar_historial;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_cerrar;
			this->ClientSize = System::Drawing::Size(450, 445);
			this->Controls->Add(this->btn_cerrar);
			this->Controls->Add(this->btn_borrar_historial);
			this->Controls->Add(this->lbx_historial);
			this->Name = L"Historial";
			this->Text = L"Historial";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
