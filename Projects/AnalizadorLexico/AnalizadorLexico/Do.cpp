#include "Do.h"


Do::Do()
{
	expr = nullptr; instr = nullptr;
}

void Do::inic(Instr^ s, Expr^ x){
	expr = x; instr = s;
	if (expr->tipo != Tipo::Bool) expr->error("Se requiere booleano en do");
}

void Do::gen(int b, int a){
	despues = a;
	int etiqueta = nuevaEtiqueta();
	instr->gen(b, etiqueta);
	emitirEtiqueta(etiqueta); 
	expr->salto(b, 0);
}