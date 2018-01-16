#pragma once

namespace My05052016 {

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
	private: AxWMPLib::AxWindowsMediaPlayer^  wmplayer;
	protected:

	private: System::Windows::Forms::Button^  btnPlay;
	private: System::Windows::Forms::Button^  btnStop;
	private: System::Windows::Forms::Button^  btnPause;
	private: System::Windows::Forms::Timer^  timer_control;
	private: System::ComponentModel::IContainer^  components;



	protected:

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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->wmplayer = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->timer_control = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wmplayer))->BeginInit();
			this->SuspendLayout();
			// 
			// wmplayer
			// 
			this->wmplayer->Enabled = true;
			this->wmplayer->Location = System::Drawing::Point(0, 0);
			this->wmplayer->Name = L"wmplayer";
			this->wmplayer->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"wmplayer.OcxState")));
			this->wmplayer->Size = System::Drawing::Size(528, 232);
			this->wmplayer->TabIndex = 0;
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(27, 250);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(75, 23);
			this->btnPlay->TabIndex = 1;
			this->btnPlay->Text = L"play";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MyForm::btnPlay_Click);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(160, 250);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 2;
			this->btnStop->Text = L"stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MyForm::btnStop_Click);
			// 
			// btnPause
			// 
			this->btnPause->Location = System::Drawing::Point(322, 250);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(75, 23);
			this->btnPause->TabIndex = 3;
			this->btnPause->Text = L"pause";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &MyForm::btnPause_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(525, 316);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->wmplayer);
			this->Name = L"MyForm";
			this->Text = L"Primer formulario";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wmplayer))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->wmplayer->Ctlcontrols->play();
				 this->timer_control->Enabled = true;
	}

private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wmplayer->Ctlcontrols->stop();
			 this->timer_control->Enabled = true;
}
private: System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wmplayer->Ctlcontrols->pause();
			 this->timer_control->Enabled = true;
}
};
}
