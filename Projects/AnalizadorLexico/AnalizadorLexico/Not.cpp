#include "Not.h"


Not::Not(Token^ tok, Expr^ x2) :Logica(tok, x2, x2)
{
}

void Not::salto(int t, int f){
	expr2->salto(f, t);
}

String^ Not::toString(){
	return op->toString() + " " + expr2->toString();
}
