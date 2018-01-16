#ifndef _ACCESO_H_
#define _ACCESO_H_

#include "Op.h"
#include "Id.h"

ref class Acceso :
public Op
{
public:
	Id^ arreglo;
	Expr^ indice;
	Acceso(Id^ a, Expr^ i, Tipo^ p);
	Expr^ gen();
	void salto(int t, int f);
	String^ toString();
};

#endif