#include "Logica.h"


Logica::Logica(Token^ tok, Expr^ x1, Expr^ x2) :Expr(tok, nullptr)
{
	expr1 = x1;
	expr2 = x2;
	tipo = comprobar(expr1->tipo, expr2->tipo);
	if (tipo == nullptr) error("Error de tipo");
}

Tipo^ Logica::comprobar(Tipo^ p1, Tipo^ p2){
	if (p1 == Tipo::Bool && p2 == Tipo::Bool)return Tipo::Bool;
	else return nullptr;
}

Expr^ Logica::gen(){
	int f = nuevaEtiqueta(), a = nuevaEtiqueta();
	Temp^ temp = gcnew Temp(tipo);
	this->salto(0, f);
	emitir(temp->toString()+" = true");
	emitir("goto L"+a);
	emitirEtiqueta(f);
	emitir(temp->toString()+" = false");
	emitirEtiqueta(a);
	return temp;
}

String^ Logica::toString(){
	return expr1->toString() + " " + op->toString() + " " + expr2->toString();
}

