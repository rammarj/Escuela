#include "ventana.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int init(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Ventana ventana;
	Application::Run(%ventana);
	return 0;
}
