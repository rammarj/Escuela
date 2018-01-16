
#include "ventanaPrincipal.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//TestForma es el nombre del proyecto
	RSA::ventanaPrincipal form;
	Application::Run(%form);
}