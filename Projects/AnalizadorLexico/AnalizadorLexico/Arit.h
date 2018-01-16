#ifndef _ARIT_H_
#define _ARIT_H_

#include "Op.h"
ref class Arit :
public Op
{
public:
	Expr ^expr1, ^expr2;
	Arit(Token^ id, Expr^ x1, Expr^ x2);
	Expr^ gen();
	String^ toString();
};

#endif