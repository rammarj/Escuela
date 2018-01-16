#include "Acceso.h"


Acceso::Acceso(Id^ a, Expr^ i, Tipo^ p) : Op(gcnew Palabra("[]", Etiqueta::INDEX), p)
{
	arreglo = a;
	indice = i;
}

Expr^ Acceso::gen(){
	return gcnew Acceso(arreglo, indice->reducir(), tipo);
}

void Acceso::salto(int t, int f){
	emitirsaltos(reducir()->toString(), t, f);
}

String^ Acceso::toString(){
	return arreglo->toString() + "[ " + indice->toString() + " ]";
}
