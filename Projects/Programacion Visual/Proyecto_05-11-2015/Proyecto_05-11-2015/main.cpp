#include "Ventana.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int init(array<String^>^ args){
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Ventana ventana;
	Application::Run(%ventana);
	return 0;
}
