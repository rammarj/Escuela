#include "Ventana.h"

Ventana::Ventana(){
	//inicializacion
	this->lstv_izquierdo = gcnew ListView();
	this->lstv_derecho = gcnew ListView();
	this->barra_menu = gcnew MenuStrip();
	this->imgl_iconos = gcnew ImageList();
	this->mnu_archivo = gcnew ToolStripMenuItem();
	this->mnui_abrir_izquierdo = gcnew ToolStripMenuItem();
	this->mnui_abrir_derecho = gcnew ToolStripMenuItem();
	this->mnui_salir = gcnew ToolStripMenuItem();
	this->mnuc_izquierdo = gcnew Windows::Forms::ContextMenu();
	this->mnuc_derecho = gcnew Windows::Forms::ContextMenu();
	this->mnuic_abrir_izquierdo = gcnew MenuItem();
	this->mnuic_abrir_derecho = gcnew MenuItem();
	this->mnuic_limpiar_izquierdo = gcnew MenuItem();
	this->mnuic_limpiar_derecho = gcnew MenuItem();
	this->fldrb_abrir_directorio = gcnew FolderBrowserDialog();
	this->str_directorio_izquierdo = L"";
	this->str_directorio_derecha = L"";

	//configuracion global
	this->SuspendLayout();
	//configuracion del mnui_abrir_izquierdo
	this->mnui_abrir_izquierdo->Text = L"abrir archivo &izquierdo";
	this->mnui_abrir_izquierdo->ShortcutKeys = Keys::Control | Keys::I;
	this->mnui_abrir_izquierdo->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

	//configuracion del mnui_abrir_derecho
	this->mnui_abrir_derecho->Text = L"abrir archivo &derecho";
	this->mnui_abrir_derecho->ShortcutKeys = Keys::Control | Keys::D;
	this->mnui_abrir_derecho->Click +=gcnew EventHandler(this, &Ventana::itemsClickEvent);

	//configuracion del mnui_salir
	this->mnui_salir->Text = L"&salir";
	this->mnui_salir->ShortcutKeys = Keys::Control | Keys::S;
	this->mnui_salir->Click +=gcnew EventHandler(this, &Ventana::itemsClickEvent);
	
	//configuracion mnuic_abrir_izquierdo
	this->mnuic_abrir_izquierdo->Text = L"abrir archivo";
	this->mnuic_abrir_izquierdo->Shortcut = Shortcut::CtrlI;
	this->mnuic_abrir_izquierdo->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

	//configuracion mnuic_abrir_derecho
	this->mnuic_abrir_derecho->Text = L"abrir archivo";
	this->mnuic_abrir_derecho->Shortcut = Shortcut::CtrlD;
	this->mnuic_abrir_derecho->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

	//configuracion mnuic_limpiar_izquierdo
	this->mnuic_limpiar_izquierdo->Text = L"limpiar";
	this->mnuic_limpiar_izquierdo->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

	//configuracion mnuic_limpiar_derecho
	this->mnuic_limpiar_derecho->Text = L"limpiar";
	this->mnuic_limpiar_derecho->Click += gcnew EventHandler(this, &Ventana::itemsClickEvent);

	//configuracion mnu_archivo
	this->mnu_archivo->Text = L"&Archivo";
	
	//configuracion barra_menu
	this->barra_menu->Items->Add(this->mnu_archivo);
	this->barra_menu->TabStop = true;
	this->barra_menu->TabIndex = 1;

	//configuracion mnu_archivo
	this->mnu_archivo->DropDownItems->Add(this->mnui_abrir_izquierdo);
	this->mnu_archivo->DropDownItems->Add(this->mnui_abrir_derecho);
	this->mnu_archivo->DropDownItems->Add(this->mnui_salir);

	//configuracion mnuc_izquierdo
	this->mnuc_izquierdo->MenuItems->Add(this->mnuic_abrir_izquierdo);
	this->mnuc_izquierdo->MenuItems->Add(this->mnuic_limpiar_izquierdo);

	//configuracion mnuc_derecho
	this->mnuc_derecho->MenuItems->Add(this->mnuic_abrir_derecho);
	this->mnuc_derecho->MenuItems->Add(this->mnuic_limpiar_derecho);

	//configuracion imgl_iconos
	this->imgl_iconos->Images->Add(L"folder", Image::FromFile(L"folder.png"));
	this->imgl_iconos->Images->Add(L"non", Image::FromFile(L"non.png"));
	DirectoryInfo^ imgs_dir = gcnew DirectoryInfo(L"iconos");
	array<FileInfo^>^ imgs = imgs_dir->GetFiles();
	for each (FileInfo^ img in imgs)
	{
		this->imgl_iconos->Images->Add(img->Name->Replace(img->Extension,L""), Image::FromFile(L"iconos\\"+img->Name));
	}
	delete imgs_dir;
	this->imgl_iconos->ImageSize = Drawing::Size(32,32);

	//configuracion lstv_izquierdo
	this->lstv_izquierdo->ContextMenu = this->mnuc_izquierdo;
	this->lstv_izquierdo->LargeImageList = this->imgl_iconos;
	this->lstv_izquierdo->SmallImageList = this->imgl_iconos;
	this->lstv_izquierdo->TabIndex = 2;
	this->lstv_izquierdo->AllowDrop = true;
	this->lstv_izquierdo->DragEnter += gcnew DragEventHandler(this, &Ventana::dragEnterEvent);
	this->lstv_izquierdo->ItemDrag += gcnew ItemDragEventHandler(this, &Ventana::itemDragEvent);
	this->lstv_izquierdo->DragDrop += gcnew DragEventHandler(this, &Ventana::dragDropEvent);

	//configuracion lstv_derecho
	this->lstv_derecho->ContextMenu = this->mnuc_derecho;
	this->lstv_derecho->LargeImageList = this->imgl_iconos;
	this->lstv_derecho->SmallImageList = this->imgl_iconos;
	this->lstv_derecho->TabIndex = 3;
	this->lstv_derecho->AllowDrop = true;
	this->lstv_derecho->DragEnter += gcnew DragEventHandler(this, &Ventana::dragEnterEvent);
	this->lstv_derecho->ItemDrag += gcnew ItemDragEventHandler(this, &Ventana::itemDragEvent);
	this->lstv_derecho->DragDrop += gcnew DragEventHandler(this, &Ventana::dragDropEvent);

	//configuracion ventana
	this->Text = L"Manejo de archivos";
	this->Resize += gcnew EventHandler(this, &Ventana::windowResizeEvent);
	this->Size = Drawing::Size(600, 500);
	this->MainMenuStrip = this->barra_menu;
	this->Controls->Add(this->barra_menu);
	this->Controls->Add(this->lstv_izquierdo);
	this->Controls->Add(this->lstv_derecho);
	this->windowResizeEvent(this, nullptr);
	
	//resumiendo el acomode de los componentes
	this->ResumeLayout();
	this->PerformLayout();
}

Ventana::~Ventana(){
	if (this->lstv_izquierdo)
	{
		delete this->lstv_izquierdo;
	}
	if (this->lstv_derecho)
	{
		delete this->lstv_derecho;
	}
	if (this->barra_menu)
	{
		delete this->barra_menu;
	}
	if (this->mnu_archivo)
	{
		delete this->mnu_archivo;
	}
	if (this->mnui_abrir_izquierdo)
	{
		delete this->mnui_abrir_izquierdo;
	}
	if (this->mnui_abrir_derecho)
	{
		delete this->mnui_abrir_derecho;
	}
	if (this->mnuic_abrir_izquierdo)
	{
		delete this->mnuic_abrir_izquierdo;
	}
	if (this->mnuic_abrir_derecho)
	{
		delete this->mnuic_abrir_derecho;
	}
	if (this->mnuic_limpiar_izquierdo)
	{
		delete this->mnuic_limpiar_izquierdo;
	}
	if (this->mnuic_limpiar_derecho)
	{
		delete this->mnuic_limpiar_derecho;
	}
	if (this->mnuc_izquierdo)
	{
		delete this->mnuc_izquierdo;
	}
	if (this->mnuc_derecho)
	{
		delete this->mnuc_derecho;
	}
	if (this->mnui_salir)
	{
		delete this->mnui_salir;
	}
	if (this->fldrb_abrir_directorio)
	{
		delete this->fldrb_abrir_directorio;
	}
	if (this->imgl_iconos)
	{
		delete this->imgl_iconos;
	}
	if (this->str_directorio_izquierdo)
	{
		delete this->str_directorio_izquierdo;
	}
	if (this->str_directorio_derecha)
	{
		delete this->str_directorio_derecha;
	}
}

Void Ventana::itemsClickEvent(Object^ source, EventArgs^ e){
	if (source == this->mnui_abrir_izquierdo || source == this->mnuic_abrir_izquierdo)
	{
		abrir_izquierdo_Click(source, e);
	}
	else if (source == this->mnui_abrir_derecho || source == this->mnuic_abrir_derecho)
	{
		abrir_derecho_Click(source, e);
	}
	else if (source == this->mnui_salir)
	{
		this->~Ventana();
		this->Close();
	}
	else if (source == this->mnuic_limpiar_izquierdo)
	{
		mnuic_limpiar_izquierdo_Click(source, e);
	}
	else if (source == this->mnuic_limpiar_derecho)
	{
		mnuic_limpiar_derecho_Click(source, e);
	}
}

void Ventana::abrir_izquierdo_Click(Object^ source, EventArgs^ e){
	this->fldrb_abrir_directorio->Description = L"Abrir directorio para mostrar en el lado izquierdo";
	Windows::Forms::DialogResult dlgr_resultado = this->fldrb_abrir_directorio->ShowDialog();
	if (dlgr_resultado == Windows::Forms::DialogResult::OK)
	{
		if (this->fldrb_abrir_directorio->SelectedPath != this->str_directorio_derecha)
		{
			this->str_directorio_izquierdo = this->fldrb_abrir_directorio->SelectedPath;
			poblarListView(this->lstv_izquierdo, this->str_directorio_izquierdo);
		}
		else
		{
			Windows::Forms::DialogResult dlgr_result = MessageBox::Show(L"El directorio elegido debe ser diferente al directorio de la derecha",
				L"Atencion", Windows::Forms::MessageBoxButtons::RetryCancel, Windows::Forms::MessageBoxIcon::Warning);
			if (dlgr_result == Windows::Forms::DialogResult::Retry)
			{
				abrir_izquierdo_Click(source, e);
			}
		}
	}
}

void Ventana::abrir_derecho_Click(Object^ source, EventArgs^ e){
	this->fldrb_abrir_directorio->Description = L"Abrir directorio para mostrar en el lado derecho";
	Windows::Forms::DialogResult dlgr_resultado = this->fldrb_abrir_directorio->ShowDialog();
	if (dlgr_resultado == Windows::Forms::DialogResult::OK)
	{
		if (this->fldrb_abrir_directorio->SelectedPath != this->str_directorio_izquierdo)
		{
			this->str_directorio_derecha = this->fldrb_abrir_directorio->SelectedPath;
			poblarListView(this->lstv_derecho, this->str_directorio_derecha);
		}
		else
		{
			Windows::Forms::DialogResult dlgr_result = MessageBox::Show(L"El directorio elegido debe ser diferente al directorio de la izquierda",
				L"Atencion", Windows::Forms::MessageBoxButtons::RetryCancel, Windows::Forms::MessageBoxIcon::Warning);
			if (dlgr_result == Windows::Forms::DialogResult::Retry)
			{
				abrir_derecho_Click(source, e);
			}
		}
	}
}

void Ventana::mnuic_limpiar_izquierdo_Click(Object^ source, EventArgs^ e){
	this->str_directorio_izquierdo = L"";
	this->lstv_izquierdo->Items->Clear();
}

void Ventana::mnuic_limpiar_derecho_Click(Object^ source, EventArgs^ e){
	this->str_directorio_derecha = L"";
	this->lstv_derecho->Items->Clear();
}

void Ventana::lstv_izquierdo_dragDropEvent(Object^ source, DragEventArgs^ e){
	if (e->Effect == DragDropEffects::Move)
	{
		if (this->str_directorio_izquierdo != "")
		{
			IEnumerator^ selected_items = this->lstv_derecho->SelectedItems->GetEnumerator();
			while (selected_items->MoveNext())
			{
				ListViewItem^ item = (ListViewItem^)selected_items->Current;
				item->Remove();
				this->lstv_izquierdo->Items->Add(item);
				Directory::Move(this->str_directorio_derecha+L"\\"+item->Text, this->str_directorio_izquierdo+L"\\"+item->Text);
			}
		}
		else{
			MessageBox::Show(L"Debe elegir un directorio en el lado izquierdo", L"Advertencia",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
}

void Ventana::lstv_derecho_dragDropEvent(Object^ source, DragEventArgs^ e){
	if (e->Effect == DragDropEffects::Move)
	{
		if (this->str_directorio_derecha != "")
		{
			IEnumerator^ selected_items = this->lstv_izquierdo->SelectedItems->GetEnumerator();
			while (selected_items->MoveNext())
			{
				ListViewItem^ item = (ListViewItem^)selected_items->Current;
				item->Remove();
				this->lstv_derecho->Items->Add(item);
				Directory::Move(this->str_directorio_izquierdo + L"\\" + item->Text, this->str_directorio_derecha + L"\\" + item->Text);
			}
		}
		else{
			MessageBox::Show(L"Debe elegir un directorio en el lado derecho", L"Advertencia",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
}

Void Ventana::dragEnterEvent(Object^ source, DragEventArgs^ e){
	e->Effect = DragDropEffects::Move;
}

Void Ventana::dragDropEvent(Object^ source, DragEventArgs^ e){
	e->Effect = DragDropEffects::Move;
	if (source == this->lstv_izquierdo)
	{
		lstv_izquierdo_dragDropEvent(source, e);
	}
	else if (source == this->lstv_derecho)
	{
		lstv_derecho_dragDropEvent(source, e);
	}
}

Void Ventana::itemDragEvent(Object^ source, ItemDragEventArgs^ e){
	ListView^ lst_current = (ListView^)source;
	lst_current->DoDragDrop(source, DragDropEffects::Move);
}

Void Ventana::windowResizeEvent(Object^ source, EventArgs^ e){
	this->lstv_izquierdo->Bounds = Drawing::Rectangle::FromLTRB(12, 36, this->Width/2-12, this->Height-48);
	this->lstv_derecho->Bounds = Drawing::Rectangle::FromLTRB(this->Width/2, 36, this->Width - 28, this->Height - 48);
}

void Ventana::poblarListView(ListView^ list, String^ directory){
	list->Items->Clear();
	DirectoryInfo^ current_directory = gcnew DirectoryInfo(directory);
	array<DirectoryInfo^>^ directories = current_directory->GetDirectories();
	for each (DirectoryInfo^ directory in directories)
	{
		list->Items->Add(directory->Name, directory->Name, 0);
	}
	array<FileInfo^>^ files = current_directory->GetFiles();
	for each (FileInfo^ file in files)
	{
		int img_index = this->imgl_iconos->Images->IndexOfKey(file->Extension->Replace(L".", L""));
		if (img_index == -1)
		{
			img_index = 1;
		}
		list->Items->Add(file->Name, file->Name, img_index);
	}
	delete current_directory;
}
