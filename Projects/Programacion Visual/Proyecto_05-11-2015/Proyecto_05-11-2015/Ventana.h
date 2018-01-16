
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;


ref class Ventana :
public Form
{
public:
	Ventana();
	~Ventana();
private:
	//componentes
	ListView^ lstv_izquierdo;
	ListView^ lstv_derecho;
	MenuStrip^ barra_menu;
	ToolStripMenuItem^ mnu_archivo;
	ToolStripMenuItem^ mnui_abrir_izquierdo;
	ToolStripMenuItem^ mnui_abrir_derecho;
	ToolStripMenuItem^ mnui_salir;
	Windows::Forms::ContextMenu^ mnuc_izquierdo;
	Windows::Forms::ContextMenu^ mnuc_derecho;
	MenuItem^ mnuic_abrir_izquierdo;
	MenuItem^ mnuic_abrir_derecho;
	MenuItem^ mnuic_limpiar_izquierdo;
	MenuItem^ mnuic_limpiar_derecho;
	ImageList^ imgl_iconos;
	FolderBrowserDialog^ fldrb_abrir_directorio;
	String^ str_directorio_izquierdo;
	String^ str_directorio_derecha;

	//funciones necesarias
	void poblarListView(ListView^, String^);

	//controladores de eventos
	//clicks
	void abrir_izquierdo_Click(Object^, EventArgs^);
	void abrir_derecho_Click(Object^, EventArgs^);
	void mnuic_limpiar_izquierdo_Click(Object^, EventArgs^);
	void mnuic_limpiar_derecho_Click(Object^, EventArgs^);
	Void itemsClickEvent(Object^, EventArgs^);
	//dragdrop
	void lstv_izquierdo_dragDropEvent(Object^, DragEventArgs^);
	void lstv_derecho_dragDropEvent(Object^, DragEventArgs^);
	Void dragEnterEvent(Object^, DragEventArgs^);
	Void itemDragEvent(Object^, ItemDragEventArgs^);
	Void dragDropEvent(Object^, DragEventArgs^);
	//
	Void windowResizeEvent(Object^, EventArgs^);
};

