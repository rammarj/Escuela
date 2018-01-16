#ifndef _WHILE_H_
#define _WHILE_H_

#include "Instr.h"
#include "Expr.h"

ref class While :
public Instr
{
public:
	Expr^ expr; Instr^ instr;
	While();
	void inic(Expr^ x, Instr^ s);
	void gen(int b, int a);
};

#endif