#ifndef _SEC_H_
#define _SEC_H_

#include "Instr.h"

ref class Sec :
public Instr
{
public:
	Instr^ instr1, ^instr2;
	Sec(Instr^ s1, Instr^ s2);
	void gen(int b, int a);
};

#endif