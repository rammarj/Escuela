#ifndef _EST_H_
#define _EST_H_

#include "Instr.h"
#include "Id.h"
ref class Est :
public Instr
{
public:
	Id^ id; Expr^ expr;
	Est(Id^ i, Expr^ x);
	Tipo^ comprobar(Tipo^ p1, Tipo^ p2);
	void gen(int b, int a);
};

#endif