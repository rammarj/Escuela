#ifndef _EST_ELEM_H_
#define _EST_EEM_H_

#include "Instr.h"
#include "Id.h"
#include "Acceso.h"
#include "Arreglo.h"

ref class EstElem :
public Instr
{
public:
	Id^ arreglo; 
	Expr^ indice, ^expr;
	EstElem(Acceso^ x, Expr^ y);
	Tipo^ comprobar(Tipo^ p1, Tipo^ p2);
	void gen(int b, int a);
};

#endif