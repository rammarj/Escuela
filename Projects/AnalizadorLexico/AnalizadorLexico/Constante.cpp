#include "Constante.h"


Constante::Constante(Token^ tok, Tipo^ p) : Expr(tok,p)
{
}

Constante::Constante(int i) : Expr(gcnew Numero(i), Tipo::Int)
{
}

void Constante::salto(int t, int f)
{
	if (this == True && t != 0)emitir("goto L"+t);
	else if (this == False && f != 0)emitir("goto L"+f);
}

