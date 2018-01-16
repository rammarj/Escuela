#include "principal.h"

using namespace System;
using namespace System::Windows::Forms;
//[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//TestForma es el nombre del proyecto
	Soccer::principal form;
	Application::Run(%form);
	return 0;
}