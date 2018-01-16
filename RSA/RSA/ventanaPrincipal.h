#pragma once

namespace RSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ventanaPrincipal
	/// </summary>
	public ref class ventanaPrincipal : public System::Windows::Forms::Form
	{
	public:
		ventanaPrincipal(void)
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
		~ventanaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Button^  btnGenerate;
	private: System::Windows::Forms::TextBox^  txtCousinTwo;
	private: System::Windows::Forms::TextBox^  txtCousinOne;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtKeyPrivate;
	private: System::Windows::Forms::TextBox^  txtKeyPublic;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->txtCousinTwo = (gcnew System::Windows::Forms::TextBox());
			this->txtCousinOne = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtKeyPrivate = (gcnew System::Windows::Forms::TextBox());
			this->txtKeyPublic = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnGenerate);
			this->groupBox1->Controls->Add(this->txtCousinTwo);
			this->groupBox1->Controls->Add(this->txtCousinOne);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 296);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Operaciones";
			// 
			// btnGenerate
			// 
			this->btnGenerate->Location = System::Drawing::Point(10, 85);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(176, 23);
			this->btnGenerate->TabIndex = 2;
			this->btnGenerate->Text = L"Generar Llaves";
			this->btnGenerate->UseVisualStyleBackColor = true;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnGenerate_Click);
			// 
			// txtCousinTwo
			// 
			this->txtCousinTwo->Location = System::Drawing::Point(86, 49);
			this->txtCousinTwo->Name = L"txtCousinTwo";
			this->txtCousinTwo->Size = System::Drawing::Size(100, 20);
			this->txtCousinTwo->TabIndex = 1;
			// 
			// txtCousinOne
			// 
			this->txtCousinOne->Location = System::Drawing::Point(86, 16);
			this->txtCousinOne->Name = L"txtCousinOne";
			this->txtCousinOne->Size = System::Drawing::Size(100, 20);
			this->txtCousinOne->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"2do No. Primo:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1er No. Primo:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->txtKeyPrivate);
			this->groupBox2->Controls->Add(this->txtKeyPublic);
			this->groupBox2->Location = System::Drawing::Point(220, 13);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(538, 296);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Llaves";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 142);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Privada:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Pública:";
			// 
			// txtKeyPrivate
			// 
			this->txtKeyPrivate->Location = System::Drawing::Point(18, 174);
			this->txtKeyPrivate->Multiline = true;
			this->txtKeyPrivate->Name = L"txtKeyPrivate";
			this->txtKeyPrivate->ReadOnly = true;
			this->txtKeyPrivate->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtKeyPrivate->Size = System::Drawing::Size(502, 100);
			this->txtKeyPrivate->TabIndex = 1;
			// 
			// txtKeyPublic
			// 
			this->txtKeyPublic->Location = System::Drawing::Point(18, 39);
			this->txtKeyPublic->Multiline = true;
			this->txtKeyPublic->Name = L"txtKeyPublic";
			this->txtKeyPublic->ReadOnly = true;
			this->txtKeyPublic->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtKeyPublic->Size = System::Drawing::Size(502, 100);
			this->txtKeyPublic->TabIndex = 1;
			// 
			// ventanaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(770, 321);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"ventanaPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RSA";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnGenerate_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
