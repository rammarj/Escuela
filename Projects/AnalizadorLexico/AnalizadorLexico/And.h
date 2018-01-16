#ifndef _AND_H_
#define _AND_H_

#include "Logica.h"

ref class And :
public Logica
{
public:
	And(Token^ tok, Expr ^x1, Expr ^x2);
	void salto(int t, int f);
};

#endif