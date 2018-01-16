#include "formulario.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ argv){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	calculadora2::formulario form;
	//tre
	Application::Run(%form);

}