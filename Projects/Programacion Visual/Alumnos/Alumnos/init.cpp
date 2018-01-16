#include "form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int init(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Alumnos::form f;
	Application::Run(%f);
	return 0;
}
