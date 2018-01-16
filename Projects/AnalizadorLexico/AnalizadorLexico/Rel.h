#ifndef _REL_H_
#define _REL_H_

#include "Logica.h"
#include "Arreglo.h"

ref class Rel :
public Logica
{
public:
	Rel(Token^ tok, Expr^ x1, Expr^ x2);
	Tipo^ comprobar(Tipo^ p1, Tipo^ p2);
	void salto(int t, int f);
};

#endif