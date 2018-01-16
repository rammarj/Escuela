#ifndef _ELSE_H_
#define _ELSE_H

#include "Instr.h"
#include "Expr.h"

ref class Else :
public Instr
{
public:
	Expr^ expr; Instr^ instr1, ^instr2;
	Else(Expr^ x, Instr^ s1, Instr^ s2);
	void gen(int b, int a);
};

#endif