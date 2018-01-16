#include "principal.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ argv){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Ejercicio23102015::principal form;
	//tre
	Application::Run(%form);

}