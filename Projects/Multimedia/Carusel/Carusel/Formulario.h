#pragma once

namespace Carusel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		DirectoryInfo^ imgdir;
		array<FileSystemInfo^>^ infos;
		//Threading::Thread^ thread;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{

			////
			imgdir = gcnew DirectoryInfo("img");
			infos = imgdir->GetFileSystemInfos();
			//thread = gcnew Threading::Thread(gcnew Threading::ParameterizedThreadStart)
			////
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(657, 403);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 

			this->timer1->Tick += gcnew System::EventHandler(this, &Formulario::timer1_Tick);
			this->timer1->Interval = 2000,
			this->timer1->Start();
			// 
			// Formulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 404);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Formulario";
			this->Text = L"Formulario";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				Random r;
				int i = r.Next(0, infos->Length);
				pictureBox1->Image = Image::FromFile(infos[i]->FullName);
	}

	private: Random rand;
	private: int i;
	};
}
