#include "Break.h"


Break::Break()
{
	if (Instr::Circundante == nullptr) error("break no encerrada");
	instr = Instr::Circundante;
}

void Break::gen(int b, int a){
	emitir("goto L" + instr->despues);
}
