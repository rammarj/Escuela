#ifndef _ANALIZADOR_H_
#define _ANALIZADOR_H_

#include "AnalizadorLexico.h"
#include "Ent.h"
#include "Instr.h"
#include "Arreglo.h"
#include "Sec.h"
#include "If.h"
#include "Else.h"
#include "While.h"
#include "Do.h"
#include "Break.h"
#include "Est.h"
#include "Acceso.h"
#include "EstElem.h"
#include "Or.h"
#include "And.h"
#include "Rel.h"
#include "Arit.h"
#include "Unario.h"
#include "Not.h"
#include "Constante.h"

ref class Analizador
{
private:
	AnalizadorLexico^ lex;
	Token^ busca;

public:
	Ent^ sup = nullptr;
	int usado = 0;
	Analizador(AnalizadorLexico^ l);
	void mover();
	void error(String^ s);
	void coincidir(int t);
	void programa();
	Instr^ bloque();
	void decls();
	Tipo^ tipo();
	Tipo^ dims(Tipo^ p);
	Instr^ instrs();
	Instr^ instr();
	Instr^ asignar();
	Expr^ boolean();
	Expr^ unir();
	Expr^ igualdad();
	Expr^ rel();
	Expr^ expr();
	Expr^ term();
	Expr^ unario();
	Expr^ factor();
	Acceso^ desplazamiento(Id^ a);
};

#endif