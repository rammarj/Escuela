#include "While.h"


While::While()
{
	expr = nullptr; instr = nullptr;
}

void While::inic(Expr^ x, Instr^ s){
	expr = x; instr = s;
	if (expr->tipo != Tipo::Bool) expr->error("Se requiere booleano en while");
}

void While::gen(int b, int a){
	despues = a;
	expr->salto(0, a);
	int etiqueta = nuevaEtiqueta();
	emitirEtiqueta(etiqueta); instr->gen(etiqueta, b);
	emitir("goto L" + b);
}