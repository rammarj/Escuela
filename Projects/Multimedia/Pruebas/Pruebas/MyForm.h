#pragma once

namespace Pruebas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			this->label1->Text = DateTime::Now.ToString();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Timers::Timer^  timer1;


	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Timers::Timer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timer1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(100, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->SynchronizingObject = this;
			this->timer1->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &MyForm::timer1_Elapsed);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 261);
			this->Controls->Add(this->label1);
			this->Name = L"Pruebas";
			this->Text = L"Pruebas";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Elapsed(System::Object^  sender, System::Timers::ElapsedEventArgs^  e) {
		this->label1->Text = e->SignalTime.ToString();
	}
	};
}
