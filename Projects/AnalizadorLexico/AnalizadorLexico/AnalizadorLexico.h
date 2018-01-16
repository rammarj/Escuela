#pragma once
#ifndef _ANALIZADOR_LEXICO_H_
#define _ANALIZADOR_LEXICO_H_

#include "Palabra.h"
#include "Tipo.h"
#include "Numero.h"
#include "Real.h"
#include "HashTableAL.h"

ref class AnalizadorLexico
{
public:
	static int linea = 1;
	char preanalisis = ' ';
	HashTableAL^ palabras = gcnew HashTableAL();
	void reservar(Palabra ^w);
	AnalizadorLexico();
	void readch();
	bool readch(char c);
	Token^ explorar();
};
#endif