#include "Arreglo.h"

Arreglo::Arreglo(int tm, Tipo ^p) :Tipo("[]", Etiqueta::INDEX, tm*p->anchura)
{
	this->tamanio = tm;
	this->de = p;
}

String^ Arreglo::toString(){
	return ("[" + tamanio + "] " + de->toString());
}