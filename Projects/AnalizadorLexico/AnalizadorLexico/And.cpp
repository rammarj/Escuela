#include "And.h"


And::And(Token^ tok, Expr ^x1, Expr ^x2) : Logica(tok,x1,x2)
{
}

void And::salto(int t, int f){
	int etiqueta = f != 0 ? f : nuevaEtiqueta();
	expr1->salto(etiqueta, 0);
	expr2->salto(t,f);
	if (f == 0) emitirEtiqueta(etiqueta);
}

