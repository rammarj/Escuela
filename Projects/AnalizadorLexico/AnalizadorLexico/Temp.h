#ifndef _TEMP_H_
#define _TEMP_H_

#include "Expr.h"
#include "Palabra.h"

ref class Temp :
public Expr
{
public:
	static int conteo;
	int numero = 0;
	Temp(Tipo^ p);
	String^ toString();
};

#endif