#pragma once

namespace EditorImages {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace Drawing::Imaging;

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
			if (color_dialog)
			{
				delete color_dialog;
			}
			if (imagen)
			{
				delete imagen;
			}
			if (barra_herramientas)
			{
				delete barra_herramientas;
			}
			if (tlb_color)
			{
				delete tlb_color;
			}
			
		}

	private:
		System::ComponentModel::Container ^components;
		MenuStrip^ barra_menu;
		ToolStrip^ barra_herramientas;
		ToolStripButton^ tlb_color;
		ToolStripMenuItem^ mnu_archivo;
		ToolStripMenuItem^ mnu_abrir;
		ToolStripMenuItem^ mnu_guardar;
		ToolStripMenuItem^ mnu_guardar_como;
		ToolStripMenuItem^ mnu_salir;
		OpenFileDialog^ dlg_abrir;
		SaveFileDialog^ dlg_guardar;
		String^ dir_archivo_actual;
		PictureBox^ imagen;
		ColorDialog^ color_dialog;
		Color color_actual;
		bool saved;		

		void inicializacionPersonalizada(){
			barra_menu = gcnew MenuStrip();
			barra_herramientas = gcnew ToolStrip();
			tlb_color = gcnew ToolStripButton();
			mnu_archivo = gcnew ToolStripMenuItem();
			mnu_abrir = gcnew ToolStripMenuItem();
			mnu_guardar = gcnew ToolStripMenuItem();
			mnu_guardar_como = gcnew ToolStripMenuItem();
			mnu_salir = gcnew ToolStripMenuItem();
			dlg_abrir = gcnew OpenFileDialog();
			dlg_guardar = gcnew SaveFileDialog();
			color_dialog = gcnew ColorDialog();
			imagen = gcnew PictureBox();
			dir_archivo_actual = L"";
			saved = true;
			color_actual = Color::Black;
			SuspendLayout();
			windowResizeEvent(this, nullptr);

			dlg_abrir->Filter = "imagenes (*.png)|*.png| imagenes (*.jpg)|*.jpg|imagenes (*.bmp)|*.bmp| imagenes (*.gif)|*.gif|imagenes (*.tiff)|*.tiff";

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
			mnu_archivo->DropDownItems->Add(mnu_abrir);
			mnu_archivo->DropDownItems->Add(mnu_guardar);
			mnu_archivo->DropDownItems->Add(mnu_guardar_como);
			mnu_archivo->DropDownItems->Add(mnu_salir);

			barra_menu->Items->Add(mnu_archivo);
			
			//picture box
			imagen->Location = Point(12,48);
			windowResizeEvent(this, nullptr);
			imagen->MouseMove += gcnew MouseEventHandler(this, &Ventana::imagen_MouseMoveEvent);
			//imagen->Cursor = gcnew Windows::Forms::Cursor();
			tlb_color->Text = L"color";
			tlb_color->Click += gcnew EventHandler(this, &EditorImages::Ventana::itemsClickEvent);

			barra_herramientas->Dock = DockStyle::Top;
			barra_herramientas->RightToLeft = Windows::Forms::RightToLeft::Yes;
			barra_herramientas->Items->Add(tlb_color);

			this->MainMenuStrip = barra_menu;
			this->Controls->Add(barra_herramientas);
			this->Controls->Add(barra_menu);
			this->Controls->Add(imagen);
			this->Resize += gcnew EventHandler(this, &Ventana::windowResizeEvent);
			this->FormClosing+=gcnew FormClosingEventHandler(this, &Ventana::closingWindowEvent);
			ResumeLayout();
			PerformLayout();
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

		Void closingWindowEvent(Object^ fuente, FormClosingEventArgs^ e){
			if (!saved)
			{
				Windows::Forms::DialogResult resultado = MessageBox::Show(L"¿desea guardar los camnios realizados?", "Confirmacion", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
				if (resultado == Windows::Forms::DialogResult::Yes)
				{
					mnu_guardar_Click();
					imagen->Image = Image::FromFile(dir_archivo_actual);
					try{ File::Delete(dir_archivo_actual + "~"); }catch (Exception^ e){}
				}
				else if (resultado == Windows::Forms::DialogResult::Cancel)
				{
					e->Cancel = true;
				}
				else{
					imagen->Image = Image::FromFile(dir_archivo_actual);
					try{ File::Delete(dir_archivo_actual + "~"); }catch (Exception^ e){}
				}
			}
		}

		Void itemsClickEvent(Object^ fuente, EventArgs^ e){
			if (fuente == tlb_color)
			{
				tlb_color_Click();
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

		void tlb_color_Click(){
			Windows::Forms::DialogResult resultado = color_dialog->ShowDialog();
			if (resultado == Windows::Forms::DialogResult::OK)
			{
				this->color_actual = color_dialog->Color;
			}
		}

		Void windowResizeEvent(Object^ fuente, EventArgs^ e){
			imagen->Bounds = Rectangle::FromLTRB(10, 48, Width - 25, Height - 45);
		}

		Void imagen_MouseMoveEvent(Object^ fuente, MouseEventArgs^ e){
			if (e->Button == Windows::Forms::MouseButtons::Left && this->dir_archivo_actual != L"" 
				&& e->X <= this->imagen->Image->Width &&  e->Y <= this->imagen->Image->Height)
			{
				this->Text = e->X+", "+e->Y;
				try{				
					int t = 2;
					Pen^ pincel = gcnew Pen(color_actual,t);			    
					Graphics^ formGraphics = Graphics::FromImage(imagen->Image);
					Graphics^ formGraphics_picture_box = imagen->CreateGraphics();
					formGraphics->DrawEllipse(pincel, e->X-t, e->Y-t, t, t);	
					formGraphics_picture_box->DrawEllipse(pincel, e->X - t, e->Y - t, t, t);
					saved = false;
					delete pincel;
				}
				catch (Exception ^e){
					MessageBox::Show("error");
				}
			}
		}

		void mnu_abrir_Click(){
			confirmacion();
			Windows::Forms::DialogResult resultado = dlg_abrir->ShowDialog();
			if (resultado == Windows::Forms::DialogResult::OK)
			{
				saved = true;
				dir_archivo_actual = dlg_abrir->FileName;				
				try{
					try{ File::Delete(dir_archivo_actual + "~"); }
					catch (Exception^ e){}
					File::Copy(dir_archivo_actual, dir_archivo_actual+"~");
					imagen->Image = Image::FromFile(dir_archivo_actual+"~");
				}
				catch (Exception^ e){
					MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					delete e;
				}

			}
		}

		void guardar_como_Click(){
			Windows::Forms::DialogResult resultado = dlg_guardar->ShowDialog();
			if (resultado == Windows::Forms::DialogResult::OK)
			{
				try{ File::Delete(dir_archivo_actual + "~"); }catch (Exception^ e){}
				dir_archivo_actual = dlg_guardar->FileName;
				guardar();
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
					guardar();
				}
			}
		}

		void guardar(){
			try{
				Graphics^ graph = imagen->CreateGraphics();
				Image^ temp = (Image^)imagen->Image->Clone();
				temp->Save(dir_archivo_actual);
				saved = true;
			}
			catch (Exception^ e){
				MessageBox::Show(e->Message, "Error mientras se guardaba el archivo", MessageBoxButtons::OK, MessageBoxIcon::Error);
				delete e;
			}
		}

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(500, 400);
			this->Text = L"Editor de imagenes";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
