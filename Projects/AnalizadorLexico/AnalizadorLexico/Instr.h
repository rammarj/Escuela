#ifndef _INSTR_H_
#define _INSTR_H_

#include "Nodo.h"

ref class Instr :
public Nodo
{
public:
	Instr();
	static Instr^ Null = gcnew Instr();
	void gen(int b, int a);
	int despues = 0;
	static Instr^ Circundante = Instr::Null;
};

#endif