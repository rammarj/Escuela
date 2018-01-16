#ifndef _IF_H_
#define _IF_H_

#include "Instr.h"
#include "Expr.h"

ref class If :
public Instr
{
public:
	Expr^ expr;
	Instr^ instr;
	If(Expr^ x, Instr^ s);
	void gen(int b, int a);
};

#endif