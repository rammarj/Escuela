#include "Analizador.h"

int main(){
	AnalizadorLexico^ lex = gcnew AnalizadorLexico();
	Analizador^ analizar = gcnew Analizador(lex);
	try{
		analizar->programa();
	}
	catch (Exception^ ex){
		Console::WriteLine();
		Console::WriteLine("Excepcion inesperada: "+ex->Message);
		Console::WriteLine(ex->StackTrace);
	}
	Console::WriteLine();
	return 0;
}
