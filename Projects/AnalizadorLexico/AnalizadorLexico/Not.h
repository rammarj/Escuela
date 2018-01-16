#ifndef _NOT_H_
#define _NOT_H_

#include "Logica.h"

ref class Not :
public Logica
{
public:
	Not(Token^ tok, Expr^ x2);
	void salto(int t, int f);
	String^ toString();
};

#endif