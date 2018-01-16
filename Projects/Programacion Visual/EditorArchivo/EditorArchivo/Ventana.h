#pragma once

namespace EditorArchivo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de Ventana
	/// </summary>
	public ref class Ventana : public System::Windows::Forms::Form
	{
	public:
		Ventana(void)
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
		~Ventana()
		{
			if (components)
			{
				delete components;
			}
			if (dlg_abrir)
			{
				delete dlg_abrir;
			}
			if (dlg_guardar)
			{
				delete dlg_guardar;
			}
		}

	private: 
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;
		MenuStrip^ barra_menu;
		ToolStripMenuItem^ mnu_archivo;
		ToolStripMenuItem^ mnu_nuevo;
		ToolStripMenuItem^ mnu_abrir;
		ToolStripMenuItem^ mnu_guardar;
		ToolStripMenuItem^ mnu_guardar_como;
		ToolStripMenuItem^ mnu_salir;
		TextBox^ txt_contenido;
		OpenFileDialog^ dlg_abrir;
		SaveFileDialog^ dlg_guardar;
		String^ dir_archivo_actual;
		bool saved;

		void inicializacionPersonalizada(){
			barra_menu = gcnew MenuStrip();
			mnu_archivo = gcnew ToolStripMenuItem();
			mnu_nuevo = gcnew ToolStripMenuItem();
			mnu_abrir = gcnew ToolStripMenuItem();
			mnu_guardar = gcnew ToolStripMenuItem();
			mnu_guardar_como = gcnew ToolStripMenuItem();
			mnu_salir = gcnew ToolStripMenuItem();
			txt_contenido = gcnew TextBox();
			dlg_abrir = gcnew OpenFileDialog();
			dlg_guardar = gcnew SaveFileDialog();
			dir_archivo_actual = L"";
			saved = true;

			SuspendLayout();

			dlg_abrir->Filter = L"(*.txt)|*.txt";
			dlg_guardar->Filter = L"(*.txt)|*.txt";

			txt_contenido->Multiline = true;
			txt_contenido->ScrollBars = ScrollBars::Both;
			txt_contenido->KeyUp +=gcnew KeyEventHandler(this, &Ventana::keyEvent);
			windowResizeEvent(this, nullptr);

			mnu_nuevo->Text = L"&Nuevo";
			mnu_nuevo->ShortcutKeys = Keys::Control | Keys::N;
			mnu_nuevo->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

			mnu_abrir->Text = L"&Abrir";
			mnu_abrir->ShortcutKeys = Keys::Control | Keys::A;
			mnu_abrir->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

			mnu_guardar->Text = L"&Guardar";
			mnu_guardar->ShortcutKeys = Keys::Control | Keys::G;
			mnu_guardar->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

			mnu_guardar_como->Text = L"Guardar &como";
			mnu_guardar_como->ShortcutKeys = Keys::Control | Keys::Shift | Keys::G;
			mnu_guardar_como->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

			mnu_salir->Text = L"&Salir";
			mnu_salir->ShortcutKeys = Keys::Control | Keys::S;
			mnu_salir->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

			mnu_archivo->Text = L"&Archivo";
			mnu_archivo->DropDownItems->Add(mnu_nuevo);
			mnu_archivo->DropDownItems->Add(mnu_abrir);
			mnu_archivo->DropDownItems->Add(mnu_guardar);
			mnu_archivo->DropDownItems->Add(mnu_guardar_como);
			mnu_archivo->DropDownItems->Add(mnu_salir);

			barra_menu->Items->Add(mnu_archivo);

			this->MainMenuStrip = barra_menu;
			this->Controls->Add(barra_menu);
			this->Controls->Add(txt_contenido);
			this->Resize +=gcnew EventHandler(this, &Ventana::windowResizeEvent);

			this->Closing +=gcnew CancelEventHandler(this, &Ventana::closingWindowEvent);
			
			ResumeLayout();
			PerformLayout();
		}

		Void keyEvent(Object^ fuente, KeyEventArgs^ e){
			saved = false;
		}

		Void closingWindowEvent(Object^ fuente, CancelEventArgs^ e){
			if (!saved)
			{
				Windows::Forms::DialogResult resultado = MessageBox::Show(L"¿desea guardar los camnios realizados?", "Confirmacion", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
				if (resultado == Windows::Forms::DialogResult::Yes)
				{
					mnu_guardar_Click();
				}
				else if (resultado == Windows::Forms::DialogResult::Cancel)
				{
					e->Cancel = true;
				}
			}
		}

		void confirmacion(){
			if (!saved)
			{
				Windows::Forms::DialogResult resultado = MessageBox::Show(L"¿desea guardar los camnios realizados?", "Confirmacion", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (resultado == Windows::Forms::DialogResult::Yes)
				{
					mnu_guardar_Click();
				}
			}
		}

		Void itemsClickEvent(Object^ fuente, EventArgs^ e){
			if (fuente == mnu_nuevo)
			{
				confirmacion();
				this->dir_archivo_actual = "";
				this->txt_contenido->Text = "";
				this->saved = true;
			}
			else if (fuente == mnu_abrir)
			{
				mnu_abrir_Click();
			}
			else if (fuente == mnu_guardar)
			{
				mnu_guardar_Click();
			}
			else if (fuente == mnu_guardar_como){
				guardar_como_Click();
			}
			else if (fuente == mnu_salir)
			{
				Close();
			}
		}

		Void windowResizeEvent(Object^ fuente, EventArgs^ e){
			txt_contenido->Bounds = Rectangle::FromLTRB(10,24,Width-25,Height-45);
		}

		void mnu_abrir_Click(){ 
			confirmacion();
			Windows::Forms::DialogResult resultado = dlg_abrir->ShowDialog();
			if (resultado == Windows::Forms::DialogResult::OK)
			{
				this->txt_contenido->Text = L"";
				dir_archivo_actual = dlg_abrir->FileName;
				FileInfo^ file = gcnew FileInfo(dir_archivo_actual);
				StreamReader^ buffer = file->OpenText();
				String^ linea = buffer->ReadLine();
				while (linea != nullptr)
				{
					txt_contenido->AppendText(linea+L"\r\n");
					linea = buffer->ReadLine();
				}
				buffer->Close();
				delete file;
				saved = true;
			}
		}

		void guardar_como_Click(){
			Windows::Forms::DialogResult resultado = dlg_guardar->ShowDialog();
			if (resultado == Windows::Forms::DialogResult::OK)
			{
				dir_archivo_actual = dlg_guardar->FileName;
				StreamWriter^ w = File::CreateText(dir_archivo_actual);
				w->Flush();
				w->Close();
				guardar(dir_archivo_actual);
			}
		}

		void mnu_guardar_Click(){
			if (!saved)
			{
				if (dir_archivo_actual == L"")
				{
					guardar_como_Click();
				}
				else{
					guardar(dir_archivo_actual);
				}
			}
		}

		void guardar(String^ dir_archivo_actual){
			FileStream^ a = gcnew FileStream(dir_archivo_actual, FileMode::Truncate);
			StreamWriter^ f = gcnew StreamWriter(a);
			f->Write(txt_contenido->Text);
			saved = true;
			f->Flush();
			f->Close();
			a->Close();
			delete f;
			delete a;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(500,400);
			this->Text = L"Editor de archivos";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
