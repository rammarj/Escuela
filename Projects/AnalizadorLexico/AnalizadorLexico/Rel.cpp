#include "Rel.h"


Rel::Rel(Token^ tok, Expr^ x1, Expr^ x2) :Logica(tok, x1, x2)
{
}

Tipo^ Rel::comprobar(Tipo^ p1, Tipo^ p2){
	if (p1->GetType() == Arreglo::typeid || p2->GetType() == Arreglo::typeid) return nullptr;
	else if (p1 == p2)return Tipo::Bool;
	else return nullptr;
}

void Rel::salto(int t, int f){
	Expr^ a = expr1->reducir();
	Expr^ b = expr2->reducir();
	String^ prueba = a->toString() + " " + op->toString() + " " + b->toString();
	emitirsaltos(prueba, t , f);
}





