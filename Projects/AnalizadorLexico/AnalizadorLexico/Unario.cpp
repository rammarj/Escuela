#include "Unario.h"


Unario::Unario(Token^ tok, Expr^ x) :Op(tok, nullptr)
{
	expr = x;
	tipo = Tipo::maximo(Tipo::Int, expr->tipo);
	if (tipo == nullptr) error("error de tipo");
}

Expr^ Unario::gen(){
	return gcnew Unario(op, expr->reducir());
}

String^ Unario::toString(){
	return op->toString() + " " + expr->toString();
}

