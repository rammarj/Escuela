#pragma once

namespace PPx1 {

	using namespace iTextSharp::text::pdf;
	using namespace iTextSharp::text;
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Reporte
	/// </summary>
	public ref class Reporte : public System::Windows::Forms::Form
	{
	public:
		Reporte(void)
		{
			InitializeComponent();
			inicializacionPersonalizada();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Reporte()
		{
			if (components)
			{
				delete components;
			}
		}
	public: AxFOXITREADERLib::AxFoxitCtl^  fxt_pdf;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Reporte::typeid));
			this->fxt_pdf = (gcnew AxFOXITREADERLib::AxFoxitCtl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fxt_pdf))->BeginInit();
			this->SuspendLayout();
			// 
			// fxt_pdf
			// 
			this->fxt_pdf->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->fxt_pdf->Enabled = true;
			this->fxt_pdf->Location = System::Drawing::Point(0, -1);
			this->fxt_pdf->Name = L"fxt_pdf";
			this->fxt_pdf->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"fxt_pdf.OcxState")));
			this->fxt_pdf->Size = System::Drawing::Size(655, 472);
			this->fxt_pdf->TabIndex = 1;
			// 
			// Reporte
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 470);
			this->Controls->Add(this->fxt_pdf);
			this->Name = L"Reporte";
			this->Text = L"Reporte";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fxt_pdf))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		void inicializacionPersonalizada(){
			try{
				this->fxt_pdf->OpenFile("e:\\reporte.pdf");/*No tiene este disco... es posible que falle si no lo creó[ref inicio>terminar_compraClick]*/
			}
			catch (Exception^ ex){
				MessageBox::Show("Error", ex->Message);/*segun la llamada a funcion no lanza exepciones
					pero no he verificado en verdad que hace el metodo a más bajo nivel*/
			}


		}

};
}
