#include "Tipo.h"


Tipo::Tipo(String^ s, int etiqueta, int ancho) :Palabra(s, etiqueta)
{
	anchura = ancho;
}

bool Tipo::numerico(Tipo^ p){
	if (p == Tipo::Char || p == Tipo::Int || p == Tipo::Float)
	{
		return true;
	}
	return false;
}

Tipo^ Tipo::maximo(Tipo^ a, Tipo ^b){
	if (!numerico(a) || !numerico(b))
		return nullptr;
	else if (a == Tipo::Float || b == Tipo::Float)
		return Tipo::Float;
	else if (a == Tipo::Int || b == Tipo::Int)
		return Tipo::Int;
	else
		return Tipo::Char;
}
