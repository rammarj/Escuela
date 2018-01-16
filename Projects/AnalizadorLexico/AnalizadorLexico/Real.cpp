#include "Real.h"


Real::Real(float v) : Token(Etiqueta::REAL)
{
	valor = v;
}

String^ Real::toString(){
	return (""+valor);
}
