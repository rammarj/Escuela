#include "Temp.h"


Temp::Temp(Tipo ^p) :Expr(Palabra::t, p)
{
	numero = ++conteo;
}

String^ Temp::toString(){
	return "t" + numero;
}
