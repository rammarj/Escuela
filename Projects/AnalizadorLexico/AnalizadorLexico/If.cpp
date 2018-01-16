#include "If.h"


If::If(Expr^ x, Instr^s)
{
	expr = x;
	instr = s;
	if (expr->tipo != Tipo::Bool) expr->error("Se requiere booleano en if");
}

void If::gen(int b, int a){
	int etiqueta = nuevaEtiqueta();
	expr->salto(0, a);
	emitirEtiqueta(etiqueta);
	instr->gen(etiqueta, a);
}
