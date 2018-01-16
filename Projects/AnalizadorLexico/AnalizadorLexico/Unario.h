#ifndef _UNARIO_H_
#define _UNARIO_H_

#include "Op.h"

ref class Unario :
public Op
{
public:
	Expr^ expr;
	Unario(Token^ tok, Expr^ x);
	Expr^ gen();
	String^ toString();	
};

#endif