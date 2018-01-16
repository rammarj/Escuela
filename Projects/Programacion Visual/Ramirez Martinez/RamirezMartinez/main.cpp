#include "Ventana.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RamirezMartinez::Ventana v;
	Application::Run(%v);
	return 0;
}
