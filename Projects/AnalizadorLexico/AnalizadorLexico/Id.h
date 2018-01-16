#ifndef _ID_H_
#define _ID_H_

#include "Expr.h"
ref class Id :
public Expr
{
public:
	int desplazamiento;
	Id(Palabra^ id, Tipo^ p, int b);
};

#endif