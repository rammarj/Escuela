#include "Else.h"


Else::Else(Expr^ x, Instr^ s1, Instr^ s2)
{
	expr = x;
	instr1 = s1;
	instr2 = s2;
	if (expr->tipo != Tipo::Bool) expr->error("Se requiere booleano en if");
}

void Else::gen(int b, int a){
	int etiqueta1 = nuevaEtiqueta();
	int etiqueta2 = nuevaEtiqueta();
	expr->salto(0, etiqueta2);
	emitirEtiqueta(etiqueta1); instr1->gen(etiqueta1, a); emitir("goto L" + a);
	emitirEtiqueta(etiqueta2); instr2->gen(etiqueta2, a);
}
