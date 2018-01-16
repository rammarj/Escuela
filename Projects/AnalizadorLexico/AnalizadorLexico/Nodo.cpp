#include "Nodo.h"


Nodo::Nodo()
{
	this->lineaex = AnalizadorLexico::linea;
}

int Nodo::nuevaEtiqueta(){
	return ++(this->etiquetas);
}

void Nodo::emitirEtiqueta(int i){
	Console::Write("L"+i+":");
}

void Nodo::emitir(String^ s){
	Console::Write("\t"+s);
}

void Nodo::error(String^ s){
	throw gcnew Exception("cerca de la linea "+lineaex+": "+s);
}

