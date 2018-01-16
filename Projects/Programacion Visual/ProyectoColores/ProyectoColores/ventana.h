
using namespace System;
using namespace System::Drawing;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::ComponentModel;

public ref class Ventana : public Form
{
public:
	Ventana();
	~Ventana();

private:
	RadioButton^ radio_claro; 
	RadioButton^ radio_obscuro;
	CheckBox^ chbox_colores_pastel;
	CheckBox^ chbox_transparencia;
	GroupBox^ grupo_radios;
	GroupBox^ grupo_checks;
	GroupBox^ grupo_principal; 
	Random^ rdm_colores;
	Void radioEvent(Object^,EventArgs^);
	Void checkBoxEvent(Object^, EventArgs^);
	void aplicarForeground(Control^, Color^);
	void aplicarBackground(Control^, Color^);
	Void resizeEvent(Object^, EventArgs^);
};

Ventana::Ventana()
{
	//inicializacion
	this->grupo_radios = gcnew GroupBox();
	this->grupo_checks = gcnew GroupBox();
	this->grupo_principal = gcnew GroupBox();
	this->radio_claro = gcnew RadioButton();
	this->radio_obscuro = gcnew RadioButton();
	this->chbox_colores_pastel = gcnew CheckBox();
	this->chbox_transparencia = gcnew CheckBox();
	this->rdm_colores = gcnew Random();
	if (!grupo_checks||!grupo_principal||!grupo_radios||!radio_claro||!radio_obscuro||
		!chbox_colores_pastel||!chbox_transparencia||!rdm_colores)
	{
		MessageBox::Show(L"No hay suficiente memoria para correr el programa");
		DestroyHandle();
	}

	//config
	this->SuspendLayout();

	//ventana
	this->StartPosition = FormStartPosition::CenterScreen;
	this->Text = L"Colores";
	this->Size = Drawing::Size(600, 600);
	//this->MaximizeBox = false;
	this->Resize +=gcnew System::EventHandler(this, &Ventana::resizeEvent);

	//redio claro config
	this->radio_claro->Text = L"claro";
	this->radio_claro->Location = Point(30,30);
	this->radio_claro->CheckedChanged +=gcnew System::EventHandler(this, &Ventana::radioEvent);

	//radio oscuro config
	this->radio_obscuro->Text = L"oscuro";
	this->radio_obscuro->Location = Point(30,60);
	this->radio_obscuro->CheckedChanged += gcnew System::EventHandler(this, &Ventana::radioEvent);

	//ads de radios al grupo de controles
	this->grupo_radios->Location = Point(7, 20);
	this->grupo_radios->Text = L"RadioButtons";
	this->grupo_radios->Controls->Add(radio_claro);
	this->grupo_radios->Controls->Add(radio_obscuro);

	/////////////////////////////////////////////////
	this->grupo_checks->Location = Point(7,130);
	this->grupo_checks->Text = L"CheckBoxes";

	//checkbox colores pastel
	this->chbox_colores_pastel->Text = L"colores pastel";
	this->chbox_colores_pastel->Location = Point(30,30);
	this->chbox_colores_pastel->CheckedChanged +=gcnew System::EventHandler(this, &Ventana::checkBoxEvent);

	//checkbox transparencia
	this->chbox_transparencia->Text = L"transparencia";
	this->chbox_transparencia->Location = Point(30,60);
	this->chbox_transparencia->CheckedChanged += gcnew System::EventHandler(this, &Ventana::checkBoxEvent);

	//ads de checkboxes al grupo de controles
	this->grupo_checks->Controls->Add(this->chbox_colores_pastel);
	this->grupo_checks->Controls->Add(this->chbox_transparencia);

	//ads al grupo principal
	//this->grupo_principal->Size = Drawing::Size(this->Width, this->Height);
	this->grupo_principal->AutoSize = true;

	this->grupo_principal->Controls->Add(grupo_radios);
	this->grupo_principal->Controls->Add(grupo_checks);

	//ads al contenedor principal
	this->Controls->Add(grupo_principal);

	this->ResumeLayout();
	this->PerformLayout();
	this->resizeEvent(this, nullptr);
}
/*
	Evento manejador de los radioButtons (CheckedChanged)
*/
Void Ventana::radioEvent(Object^ fuente, EventArgs^ e){
	if ((fuente == this->radio_claro && this->radio_claro->Checked)){
		this->BackColor = Color::Empty;
		aplicarBackground(this->grupo_principal, Color::Empty);
		if (!this->chbox_colores_pastel->Checked){
			aplicarForeground(this->grupo_principal, Color::Empty);
		}
	}
	else if (fuente == this->radio_obscuro && this->radio_obscuro->Checked){
			this->BackColor = Color::Black;
			aplicarBackground(this->grupo_principal, Color::Black);
		if (!this->chbox_colores_pastel->Checked){
			aplicarForeground(this->grupo_principal, Color::White);
		}
	}
}

/*
Evento manejador de los CheckBoxes (CheckedChanged)
*/
Void Ventana::checkBoxEvent(Object^ fuente, EventArgs^ e){	
	if (fuente == this->chbox_colores_pastel)
	{
		if (this->chbox_colores_pastel->Checked)
		{
			//aplicarBackground(grupo_principal, Color::Empty);
			aplicarForeground(grupo_principal, nullptr);
		}
		else{
			if (this->radio_claro->Checked)
			{
				radioEvent(this->radio_claro, nullptr);
			}
			else if (this->radio_obscuro->Checked)
			{
				radioEvent(this->radio_obscuro, nullptr);
			}
			
		}
		
	}
	else if (fuente == this->chbox_transparencia)
	{
		if (this->chbox_transparencia->Checked){
			this->Opacity = 0.5;
		}
		else
		{	
			this->Opacity = 1;
		}
	}
}

/**
	funcion para el Foreground.
	Si el parametro Foreground es nulo, la funcion genera un color aleatorio.
*/
void Ventana::aplicarForeground(Control^ control, Color^ foreground){
	
	if (control->Controls)
	{		
		IEnumerator^ controles = control->Controls->GetEnumerator();
		while (controles->MoveNext())
		{
			Control^ controlDentro = (Control ^)(controles->Current);
			if (!foreground)
			{
				controlDentro->ForeColor = Color::FromArgb(rdm_colores->Next(0, 255), rdm_colores->Next(0, 255),
					rdm_colores->Next(0, 255));
			}
			else
			{
				controlDentro->ForeColor = Color(foreground);
			}
			aplicarForeground(controlDentro, foreground); //recursivo en busca de mas controles dentro de controles
		}
	}
	if (!foreground)
	{
		control->ForeColor = Color::FromArgb(rdm_colores->Next(0, 255), rdm_colores->Next(0, 255),
			rdm_colores->Next(0, 255));
	}
	else
	{
		control->ForeColor = Color(foreground);
	}
}

/*
Evento manejador del resizeWindow
*/
Void Ventana::resizeEvent(Object^ fuente, EventArgs^ e)
{
	this->grupo_principal->Location = Point(this->Width/2 - this->grupo_principal->Width/2 - 6,
		this->Height / 2 - this->grupo_principal->Height / 2 - 22);
}
/*
	aplica el background al control y a todos sus subcontroles
*/
void Ventana::aplicarBackground(Control^ control, Color^ background){
	control->BackColor = Color(background);
	if (control->Controls)
	{
		IEnumerator^ controles = control->Controls->GetEnumerator();
		while (controles->MoveNext())
		{
			Control^ controlDentro = (Control ^)(controles->Current);
			controlDentro->BackColor = Color(background);
			aplicarBackground(controlDentro, background); //recursivo en busca de mas controles dentro de controles
		}
	}
	
}

Ventana::~Ventana()
{
	if (radio_claro){
		delete radio_claro;
	}
	if (radio_obscuro)
	{
		delete radio_obscuro;
	}
	if (grupo_radios){
		delete grupo_radios;
	}
	if (grupo_checks){
		delete grupo_checks;
	}
	if (chbox_transparencia){
		delete chbox_transparencia;
	}
	if (chbox_colores_pastel)
	{
		delete chbox_colores_pastel;
	}
	if (rdm_colores)
	{
		delete rdm_colores;
	}
}