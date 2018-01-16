#include "Arit.h"


Arit::Arit(Token^ tok, Expr^ x1, Expr^ x2) :Op(tok,nullptr)
{
	this->expr1 = x1;
	this->expr2 = x2;
	this->tipo = Tipo::maximo(expr1->tipo, expr2->tipo);
	if (tipo == nullptr) error("error de tipo");
}

Expr^ Arit::gen(){
	return gcnew Arit(op, expr1->reducir(), expr2->reducir());
}

String^ Arit::toString(){
	return expr1->toString() + " " + op->toString() + " " + expr2->toString();
}
