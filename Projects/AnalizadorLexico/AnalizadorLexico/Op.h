#ifndef _OP_H_
#define _OP_H_

#include "Expr.h"
#include "Temp.h"

ref class Op :
public Expr
{
public:
	Op(Token^ id, Tipo^ p);
	Expr^ reducir();
};

#endif