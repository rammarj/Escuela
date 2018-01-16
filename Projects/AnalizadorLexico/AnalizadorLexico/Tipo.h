#pragma once
#ifndef _TIPO_H_
#define _TIPO_H_

#include "Palabra.h"
ref class Tipo :
public Palabra
{
public:
	int anchura;
	static Tipo^ Int = gcnew Tipo("int", Etiqueta::BASIC, 4);
	static Tipo^ Float = gcnew Tipo("float", Etiqueta::BASIC, 8);
	static Tipo^ Char = gcnew Tipo("char", Etiqueta::BASIC, 1);
	static Tipo^ Bool = gcnew Tipo("bool", Etiqueta::BASIC, 1);

	Tipo(String^ s, int etiqueta, int ancho);
	static bool numerico(Tipo^ p);
	static Tipo^ maximo(Tipo^ a, Tipo^ b);
};
#endif
