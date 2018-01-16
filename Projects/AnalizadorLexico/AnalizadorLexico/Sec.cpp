#include "Sec.h"


Sec::Sec(Instr^ s1, Instr^ s2)
{
	instr1 = s1;
	instr2 = s2;
}

void Sec::gen(int b, int a)
{
	int etiqueta;
	if (instr1 == Instr::Null) instr2->gen(b, a);
	else if (instr2 == Instr::Null) instr1->gen(b, a);
	else{
		etiqueta = nuevaEtiqueta();
		instr1->gen(b, etiqueta);
		emitirEtiqueta(etiqueta);
		instr2->gen(etiqueta, a);
	}
}
