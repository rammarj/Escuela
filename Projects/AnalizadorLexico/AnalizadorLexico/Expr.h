#ifndef _EXPR_H_
#define _EXPR_H_

#include "Nodo.h"

ref class Expr :
public Nodo
{
public:
	Token ^op;
	Tipo ^tipo;
	Expr(Token^ tok, Tipo^ p);
	Expr^ gen();
	Expr^ reducir();
	void salto(int t, int f);
	void emitirsaltos(String^ prueba, int t, int f);
	String^ toString();
};

#endif