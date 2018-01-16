#include "Or.h"


Or::Or(Token^ tok, Expr^ x1, Expr^ x2) :Logica(tok,x1,x2)
{
}

void Or::salto(int t, int f){
	int etiqueta = t != 0 ? t : nuevaEtiqueta();
	expr1->salto(etiqueta, 0);
	expr2->salto(t,f);
	if (t == 0)emitirEtiqueta(etiqueta);
}
