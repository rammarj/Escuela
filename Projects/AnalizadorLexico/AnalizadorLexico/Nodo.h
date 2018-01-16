#ifndef _NODO_H_
#define _NODO_H_

#include "AnalizadorLexico.h"

using namespace System;

ref class Nodo
{

public:
	int lineaex = 0;
	Nodo();
	void error(String^ s);
	static int etiquetas = 0;
	int nuevaEtiqueta();
	void emitirEtiqueta(int i);
	void emitir(String^ s);
};

#endif