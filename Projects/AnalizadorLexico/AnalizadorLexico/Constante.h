#ifndef _CONSTANTE_H_
#define _CONSTANTE_H_

#include "Expr.h"
#include "Palabra.h"

ref class Constante :
public Expr
{
public:
	Constante(Token^ tok, Tipo^ p);
	Constante(int i);
	 static Constante^ True = gcnew Constante(Palabra::True, Tipo::Bool),
		^False = gcnew Constante(Palabra::False, Tipo::Bool);
	void salto(int t, int f);
};

#endif