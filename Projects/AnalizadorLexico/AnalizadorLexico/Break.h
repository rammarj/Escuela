#ifndef _BREAK_H_
#define _BREAK_H_
#include "Instr.h"
ref class Break :
public Instr
{
public:
	Instr^ instr;
	Break();
	void gen(int b, int a);
};

#endif