#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PPx1::Login login;
	Application::Run(%login);
	return 0;
}
