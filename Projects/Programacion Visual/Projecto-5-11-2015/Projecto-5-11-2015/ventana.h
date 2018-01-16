using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::IO;

public ref class Ventana : public Form{

private:
	MenuStrip^ menu;
	ToolStripMenuItem^ archivo;
	ToolStripMenuItem^ mnu_archivo1;
	ToolStripMenuItem^ mnu_archivo2;
	ToolStripMenuItem^ mnu_salir;
	FolderBrowserDialog^ flb_abrir_folder;
	TreeView^ trv_izquierdo;
	TreeView^ trv_derecho;
	::ContextMenu^ mnu_contextual_izquierdo;
	::ContextMenu^ mnu_contextual_derecho;
	MenuItem^ mnu_abrir_archivo_izquierdo;
	MenuItem^ mnu_abrir_archivo_derecho;
	MenuItem^ mnu_limpiar_izquierdo;
	MenuItem^ mnu_limpiar_derecho;
	String^ directorio_izquierdo;
	String^ directorio_derecho;
	ImageList^ imgs;

	void poblarTreeView(TreeView^ treeView1, String^ dir)
	{
		DirectoryInfo^ info = gcnew DirectoryInfo(dir);
		array<DirectoryInfo^>^ dirs;
		array<FileInfo^>^ files;
		if (info->Exists)
		{
			dirs = info->GetDirectories();
			files = info->GetFiles();
			for each(DirectoryInfo^ dir in dirs){
				treeView1->Nodes->Add(dir->Name, dir->Name, 0);
				
			}
			for each(FileInfo^ file in files){
				int index = this->imgs->Images->IndexOfKey(file->Extension->Replace(".","")+".png");
				if (index == -1){
					index = 1;
				}
				treeView1->Nodes->Add(file->Name, file->Name, index, index);
			}
		}
		delete info;
	}

	Void menuItemClick(Object^ source, EventArgs^ e){
		::DialogResult resultado;
		String^ path;
		if (source == this->mnu_archivo1 || source == this->mnu_abrir_archivo_izquierdo){
			resultado = this->flb_abrir_folder->ShowDialog();
			if (resultado == ::DialogResult::OK){
				path = this->flb_abrir_folder->SelectedPath;
				this->directorio_izquierdo = path;
				this->trv_izquierdo->Nodes->Clear();
				poblarTreeView(this->trv_izquierdo, path);

			}
		}
		else if (source == this->mnu_archivo2 || source == this->mnu_abrir_archivo_derecho)
		{
			resultado = this->flb_abrir_folder->ShowDialog();
			if (resultado == ::DialogResult::OK){
				path = this->flb_abrir_folder->SelectedPath;
				this->directorio_derecho = path;
				this->trv_derecho->Nodes->Clear();
				poblarTreeView(this->trv_derecho, path);
			}
		}
		if (source == this->mnu_salir)
		{
			this->Close();
		}
	}

	Void trv_izquierdo_dragEnter(Object^ fuente, DragEventArgs^ args){
		args->Effect = ::DragDropEffects::Move;
	}
	
	Void trv_izquierdo_dropEvent(Object^ fuente, DragEventArgs^ e){
		try{
			Point targetPoint = this->trv_izquierdo->PointToClient(Point(e->X, e->Y));
			TreeNode^ targetNode = this->trv_izquierdo->GetNodeAt(targetPoint);
			TreeNode^ draggedNode = dynamic_cast<TreeNode^>(e->Data->GetData(TreeNode::typeid));
			if (!draggedNode->Equals(targetNode) && !ContainsNode(this->trv_izquierdo->Nodes, targetNode))
			{
				if (e->Effect == DragDropEffects::Move)
				{
					draggedNode->Remove();
					trv_izquierdo->Nodes->Add(draggedNode);
					File::Move(this->directorio_derecho + "\\" + draggedNode->Text, this->directorio_izquierdo + "\\" + draggedNode->Text);
				}
			}
		}
		catch (Exception^ ex){
			//MessageBox::Show(ex->ToString());
		}

	}

	Void trv_izquierdo_DragOver(Object^ fuente, DragEventArgs^ e){
		Point targetPoint = this->trv_izquierdo->PointToClient(Point(e->X, e->Y));
		//seleccionar el nodo en la posicion del mouse
		this->trv_izquierdo->SelectedNode = this->trv_izquierdo->GetNodeAt(targetPoint);
	}

	Void trv_derecho_DragOver(Object^ fuente, DragEventArgs^ e){
		Point targetPoint = this->trv_derecho->PointToClient(Point(e->X, e->Y));
		//seleccionar el nodo en la posicion del mouse
		this->trv_derecho->SelectedNode = this->trv_derecho->GetNodeAt(targetPoint);
	}

	Void trv_derecho_dragEnter(Object^ fuente, DragEventArgs^ args){
		args->Effect = ::DragDropEffects::Move;
	}

	Void trv_derecho_dropEvent(Object^ fuente, DragEventArgs^ e){
		try{
			Point targetPoint = this->trv_derecho->PointToClient(Point(e->X, e->Y));
			TreeNode^ targetNode = this->trv_derecho->GetNodeAt(targetPoint);
			TreeNode^ draggedNode = dynamic_cast<TreeNode^>(e->Data->GetData(TreeNode::typeid));
			if (!draggedNode->Equals(targetNode) && !ContainsNode(this->trv_derecho->Nodes, targetNode))
			{
				if (e->Effect == DragDropEffects::Move)
				{
					draggedNode->Remove();
					trv_derecho->Nodes->Add(draggedNode);
					File::Move(this->directorio_izquierdo + "\\" + draggedNode->Text, this->directorio_derecho + "\\" + draggedNode->Text);
				}
			}
		}
		catch (Exception^ ex){
			//MessageBox::Show(ex->ToString());		
		}
		
	}

	Void itemDragEvent(Object^ fuente, ItemDragEventArgs^ e){
		if (e->Button == ::MouseButtons::Left)
		{
			DoDragDrop(e->Item, DragDropEffects::Move);
		}
	}
	
	Void trv_izquierdo_mouseEvent(Object^ obj, MouseEventArgs^ e){
		if (obj == this->trv_izquierdo && e->Button == ::MouseButtons::Right)
		{
			this->trv_izquierdo->ContextMenu->Show(this->trv_izquierdo, Point(e->X, e->Y));
		}
		else if (obj == this->trv_derecho && e->Button == ::MouseButtons::Right)
		{
			this->trv_derecho->ContextMenu->Show(this->trv_derecho, Point(e->X, e->Y));
		}
	}

	Void limpiarItemEvent(Object^ fuente, EventArgs^e){
		if (fuente == this->mnu_limpiar_izquierdo)
		{
			this->trv_izquierdo->Nodes->Clear();
		}
		else if (fuente == this->mnu_limpiar_derecho)
		{
			this->trv_derecho->Nodes->Clear();
		}
	}

	Void tabEvent(Object^ fuente, EventArgs^e){
		
	}

	bool ContainsNode(TreeNodeCollection^ node1, TreeNode^ node2)
	{
		for each (TreeNode^ nodo in node1)
		{
			if (node2 == nodo){
				return true;
			}
		}
		return false;
	}
public:
	Ventana(){
		this->menu = gcnew MenuStrip();
		this->archivo = gcnew ToolStripMenuItem();
		this->mnu_archivo1 = gcnew ToolStripMenuItem();
		this->mnu_archivo2 = gcnew ToolStripMenuItem();
		this->mnu_salir = gcnew ToolStripMenuItem();
		this->flb_abrir_folder = gcnew FolderBrowserDialog();
		this->trv_izquierdo = gcnew TreeView();
		this->trv_derecho = gcnew TreeView();
		this->mnu_contextual_izquierdo = gcnew ::ContextMenu();
		this->mnu_contextual_derecho = gcnew ::ContextMenu();
		this->directorio_derecho = L"";
		this->directorio_izquierdo = L"";
		this->imgs = gcnew ImageList();

		//imagelist
		this->imgs->Images->Add(L"folder.png", Image::FromFile(L"folder.png"));
		this->imgs->Images->Add(L"non.png", Image::FromFile(L"non.png"));
		DirectoryInfo^ dir_iconos = gcnew DirectoryInfo("iconos");
		array<FileInfo^>^ iconos = dir_iconos->GetFiles();
		for each(FileInfo^ icono in iconos){
			this->imgs->Images->Add(icono->Name, Image::FromFile("iconos\\" + icono->Name));
		}
		delete dir_iconos;
		
		this->mnu_abrir_archivo_izquierdo = gcnew MenuItem();
		this->mnu_abrir_archivo_derecho = gcnew MenuItem();
		this->mnu_limpiar_izquierdo = gcnew MenuItem();
		this->mnu_limpiar_derecho = gcnew MenuItem();

		this->SuspendLayout();
		//menu contextual abrir archivo izquierdo
		this->mnu_abrir_archivo_izquierdo->Text = L"cargar archivo";
		this->mnu_abrir_archivo_izquierdo->Click += gcnew System::EventHandler(this, &Ventana::menuItemClick);

		//menu contextual abrir archivo derecho
		this->mnu_abrir_archivo_derecho->Text = L"cargar archivo";
		this->mnu_abrir_archivo_derecho->Click +=gcnew System::EventHandler(this, &Ventana::menuItemClick);

		//menu contextual abrir archivo izquierdo
		this->mnu_limpiar_izquierdo->Text = L"limpiar";
		this->mnu_limpiar_izquierdo->Click += gcnew System::EventHandler(this, &Ventana::limpiarItemEvent);

		//menu contextual abrir archivo derecho
		this->mnu_limpiar_derecho->Text = L"limpiar";
		this->mnu_limpiar_derecho->Click += gcnew System::EventHandler(this, &Ventana::limpiarItemEvent);

		//menu contextual izquierdo
		this->mnu_contextual_izquierdo->MenuItems->Add(this->mnu_abrir_archivo_izquierdo);
		this->mnu_contextual_izquierdo->MenuItems->Add(this->mnu_limpiar_izquierdo);

		//menu contextual derecho
		this->mnu_contextual_derecho->MenuItems->Add(this->mnu_abrir_archivo_derecho);
		this->mnu_contextual_derecho->MenuItems->Add(this->mnu_limpiar_derecho);

		//tree view izquierdo
		this->trv_izquierdo->Size = ::Size(250,320);
		this->trv_izquierdo->Location = Point(12, 24);
		this->trv_izquierdo->AllowDrop = true;
		this->trv_izquierdo->ImageList = this->imgs;
		this->trv_izquierdo->ContextMenu = this->mnu_contextual_izquierdo;
		this->trv_izquierdo->DragEnter +=gcnew DragEventHandler(this, &Ventana::trv_izquierdo_dragEnter);
		this->trv_izquierdo->DragDrop += gcnew DragEventHandler(this, &Ventana::trv_izquierdo_dropEvent);		
		this->trv_izquierdo->ItemDrag += gcnew ItemDragEventHandler(this, &Ventana::itemDragEvent);
		this->trv_izquierdo->DragOver +=gcnew DragEventHandler(this, &Ventana::trv_izquierdo_DragOver);
		this->trv_izquierdo->MouseClick +=gcnew MouseEventHandler(this, &Ventana::trv_izquierdo_mouseEvent);

		//tree view derecho
		this->trv_derecho->Size = ::Size(250, 320);
		this->trv_derecho->Location = Point(274, 24);
		this->trv_derecho->AllowDrop = true;
		this->trv_derecho->ImageList = this->imgs;
		this->trv_derecho->ContextMenu = this->mnu_contextual_derecho;
		this->trv_derecho->DragEnter += gcnew DragEventHandler(this, &Ventana::trv_derecho_dragEnter);
		this->trv_derecho->DragDrop += gcnew DragEventHandler(this, &Ventana::trv_derecho_dropEvent);
		this->trv_derecho->ItemDrag += gcnew ItemDragEventHandler(this, &Ventana::itemDragEvent);
		this->trv_derecho->DragOver += gcnew DragEventHandler(this, &Ventana::trv_derecho_DragOver);
		this->trv_derecho->MouseClick += gcnew MouseEventHandler(this, &Ventana::trv_izquierdo_mouseEvent);

		//folder dialog
		this->flb_abrir_folder->Description = L"Selecciona una carpeta para mostrar en el TreeView";
		this->flb_abrir_folder->ShowNewFolderButton = false;

		//menu item abrir carpeta derecha
		this->mnu_archivo1->Text = L"abrir archivo &izquierdo";
		this->mnu_archivo1->Click +=gcnew System::EventHandler(this, &Ventana::menuItemClick);
		this->mnu_archivo1->ShortcutKeys = ::Keys::Control | ::Keys::I;
		
		
		//menu item abrir carpeta izquierda
		this->mnu_archivo2->Text = L"abrir archivo &derecho";
		this->mnu_archivo2->Click += gcnew System::EventHandler(this, &Ventana::menuItemClick);
		this->mnu_archivo2->ShortcutKeys = ::Keys::Control | ::Keys::D;
		//menu item salir
		this->mnu_salir->Text = L"&salir";
		this->mnu_salir->Click += gcnew System::EventHandler(this, &Ventana::menuItemClick);
		this->mnu_salir->ShortcutKeys = ::Keys::Control | ::Keys::S;
		// menu archivo
		this->archivo->Text = L"&Archivo";
		this->archivo->ShortcutKeys = ::Keys::Alt | ::Keys::A;		
		this->archivo->AutoSize = true;
		this->archivo->DropDownItems->Add(this->mnu_archivo1);
		this->archivo->DropDownItems->Add(this->mnu_archivo2);
		this->archivo->DropDownItems->Add(this->mnu_salir);

		//menu
		this->menu->Items->Add(archivo);

		//ventana
		this->Size = Drawing::Size(536,356);
		this->Text = L"Aplicacion";
		this->MainMenuStrip = this->menu;
		this->TabIndexChanged += gcnew EventHandler(this, &Ventana::tabEvent);
		this->ResumeLayout();
		this->PerformLayout();
		this->Controls->Add(this->menu);
		this->Controls->Add(this->trv_izquierdo);
		this->Controls->Add(this->trv_derecho);
	}
	
	~Ventana(){
		if (this->menu)
		{
			delete this->menu;
		}
		if (this->mnu_archivo1){
			delete this->mnu_archivo1;
		}
		if (this->mnu_archivo2){
			delete this->mnu_archivo2;
		}
		if (this->mnu_salir){
			delete this->mnu_salir;
		}
		if (this->archivo){
			delete this->archivo;
		}
		if (this->flb_abrir_folder)
		{
			delete this->flb_abrir_folder;
		}
		if (this->trv_izquierdo)
		{
			delete this->trv_izquierdo;
		}
		if (this->trv_derecho)
		{
			delete this->trv_derecho;
		}
		if (this->mnu_contextual_izquierdo)
		{
			delete this->mnu_contextual_izquierdo;
		}
		if (this->mnu_contextual_derecho)
		{
			delete this->mnu_contextual_derecho;
		}
		if (this->mnu_abrir_archivo_izquierdo)
		{
			delete this->mnu_abrir_archivo_izquierdo;
		}
		if (this->mnu_abrir_archivo_derecho)
		{
			delete this->mnu_abrir_archivo_derecho;
		}
		if (this->mnu_limpiar_izquierdo)
		{
			delete this->mnu_limpiar_izquierdo;
		}
		if (this->mnu_limpiar_derecho)
		{
			delete this->mnu_limpiar_derecho;
		}
		if (this->imgs)
		{
			delete this->imgs;
		}
	}

};

