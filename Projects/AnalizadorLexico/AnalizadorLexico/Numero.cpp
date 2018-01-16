#include "Numero.h"

Numero::Numero(int v) : Token(Etiqueta::NUM)
{
	valor = v;
}

String^ Numero::toString(){
	return ("" + (char)valor);
}
