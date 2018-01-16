#include "ventana.h"

using namespace System;
using namespace System::Windows::Forms;

int init(array <String^>^ args){
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	//run de api
	Ventana ventana;
	Application::Run(%ventana);
	return 0;
}
