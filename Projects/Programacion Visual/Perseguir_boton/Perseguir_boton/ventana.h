
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::ComponentModel;
using namespace System::Collections;

public ref class Ventana : public Form{

public:
	Ventana(){
		inicializacion();
	}

protected:
	~Ventana(){
		if (components)
		{
			delete components;
		}
		if (btn_clikeame)
		{
			delete btn_clikeame;			
		}
	}

private:
	System::ComponentModel::Container^ components;
	Button^ btn_clikeame;
	const int ventana_ancho = 600;
	const int ventana_alto = 600;
	bool juego_terminado;

	void inicializacion(){
		//inicializacion
		btn_clikeame = gcnew Button();
		juego_terminado = false;
		//config
		this->SuspendLayout();
		//variables
		//ventana
		this->Text = "Boton miedoso";
		this->StartPosition = FormStartPosition::CenterScreen;
		this->Name = "formulario_principal";
		//this->MaximizeBox = false;
		this->Size = Drawing::Size(ventana_ancho,ventana_alto);
		this->BackColor = Drawing::Color::LightGreen;
		this->DoubleBuffered = true;
		//btn config
		this->btn_clikeame->Text = "clickeame";
		this->btn_clikeame->AutoSize = true;
		this->btn_clikeame->BackColor = Drawing::Color::White;
		this->btn_clikeame->Click += gcnew EventHandler(this, &Ventana::eventoClick);
		int pos_x = this->Width/2-(this->btn_clikeame->Width/2), pos_y = this->Height/2-(this->btn_clikeame->Height/2);
		this->btn_clikeame->Location = Point(pos_x,pos_y);
		//ads de componentes
		this->Controls->Add(this->btn_clikeame);
		//adds de eventos de ventana
		//this->MouseMove += gcnew MouseEventHandler(this, &Ventana::jugando);
		this->btn_clikeame->MouseHover += gcnew System::EventHandler(this, &Ventana::jugando);
		this->ResumeLayout();
		this->PerformLayout();
	}

	Void eventoClick(Object^ fuente, EventArgs^ e){
		if (juego_terminado){
			this->Close();
		}
		juego_terminado = true;
		this->btn_clikeame->BackColor = Drawing::Color::Red;
		this->btn_clikeame->Text = L"You have clicked me!!";
	}
	
	Void jugando(System::Object ^fuente, EventArgs ^e)
	{
		if (!juego_terminado){
			Random^ rdm = gcnew Random(); //numeros aleatorios para el pos x, pos y ; nuevos	
			
			Point^ puntoMouseActual = this->MousePosition;
			Point^ locacionV = this->Location;
			int posMouseX = puntoMouseActual->X - locacionV->X;
			int posMouseY = puntoMouseActual->Y - locacionV->Y;
			//try{
			try{
				int rangox = rdm->Next(0, (this->Width - this->btn_clikeame->Width));
				int rangoy = rdm->Next(0, (this->Height - this->btn_clikeame->Width));
				this->btn_clikeame->Location = Point(rangox, rangoy);
			}
			catch (Exception^ e){}
			//}
			//catch (Exception^ e){}
			
			//delete rectangulo;
			delete rdm;
		}
	}

};

