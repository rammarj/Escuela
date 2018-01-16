#include "Formulario.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(){
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	web_browser::Formulario form;
	Application::Run(%form);
	return 0;
}
