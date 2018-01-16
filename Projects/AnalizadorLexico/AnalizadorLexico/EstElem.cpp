#include "EstElem.h"


EstElem::EstElem(Acceso^ x, Expr^ y)
{
	arreglo = x->arreglo;
	indice = x->indice;
	expr = y;
	if (comprobar(x->tipo, expr->tipo) == nullptr) error("Error de tipo");
}

Tipo^ EstElem::comprobar(Tipo^ p1, Tipo^ p2){
	if (p1->GetType() == Arreglo::typeid || p2->GetType() == Arreglo::typeid) return nullptr;
	else if (p1 == p2) return p2;
	else if (Tipo::numerico(p1) && Tipo::numerico(p2)) return p2;
	else return nullptr;
}

void EstElem::gen(int b, int a){
	String^ s1 = indice->reducir()->toString();
	String^ s2 = expr->reducir()->toString();
	emitir(arreglo->toString() + " [ " + s1 + " ] = " + s2);
}