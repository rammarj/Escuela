#ifndef _DO_H_
#define _DO_H_

#include "Instr.h"
#include "Expr.h"

ref class Do :
public Instr
{
public:
	Expr^ expr; Instr^ instr;
	Do();
	void inic(Instr^ s, Expr^ x);
	void gen(int b, int a);
};

#endif