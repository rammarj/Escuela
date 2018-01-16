#include "Formulario.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Carusel::Formulario m;
	Application::Run(%m);
}