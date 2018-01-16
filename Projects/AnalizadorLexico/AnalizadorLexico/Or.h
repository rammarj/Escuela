#ifndef _OR_H_
#define _OR_H_

#include "Logica.h"

ref class Or :
public Logica
{
public:
	Or(Token^ tok, Expr^ x1, Expr^ x2);
	void salto(int t, int f);

};

#endif