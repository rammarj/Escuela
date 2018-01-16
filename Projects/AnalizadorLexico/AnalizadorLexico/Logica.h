#ifndef _LOGICA_H_
#define _LOGICA_H_

#include "Expr.h"
#include "Temp.h"

ref class Logica :
public Expr
{
public:
	Expr ^expr1, ^expr2;
	Logica(Token^ tok, Expr^ x1, Expr^ x2);
	Tipo^ comprobar(Tipo ^p1, Tipo^ p2);
	Expr^ gen();
	String^ toString();
};

#endif