#include "Expr.h"


Expr::Expr(Token^ tok, Tipo^ p)
{
	this->op = tok;
	this->tipo = p;
}

Expr^ Expr::gen(){
	return this;
}

Expr^ Expr::reducir(){
	return this;
}

void Expr::salto(int t, int f){
	emitirsaltos(toString(), t, f);
}

void Expr::emitirsaltos(String^ prueba, int t, int f){
	if (t !=0 && f!=0)
	{
		emitir("if " + prueba + " goto L" + t);
		emitir("goto L" + f);
	}
	else if (t != 0)emitir("if " + prueba + " goto L" + t);
	else if (f != 0)emitir("iffalse "+prueba+" goto L"+f);
	else ;
}

String^ Expr::toString(){
	return this->op->toString();
}