#include "Ventana.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int init(array<String^>^ args){
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	EditorImages::Ventana v;
	Application::Run(%v);
	return 0;
}