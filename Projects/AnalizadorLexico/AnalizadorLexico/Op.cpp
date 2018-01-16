#include "Op.h"


Op::Op(Token^ tok, Tipo^ p) :Expr(tok, p)
{
}

Expr^ Op::reducir(){
	Expr^ x = gen();
	Temp^ t = gcnew Temp(tipo);
	emitir(t->toString()+" = "+x->toString());
	return t;
}

