#include "Est.h"


Est::Est(Id^ i, Expr^ x)
{
	id = i; expr = x;
	if (comprobar(id->tipo, expr->tipo) == nullptr) error("Error de tipo");
}

Tipo^ Est::comprobar(Tipo^ p1, Tipo^ p2){
	if (Tipo::numerico(p1) && Tipo::numerico(p2))return p2;
	else if (p1 == Tipo::Bool && p2 == Tipo::Bool) return p2;
	else return nullptr;
}

void Est::gen(int b, int a){
	emitir(id->toString() + " = " + expr->gen()->toString());
}