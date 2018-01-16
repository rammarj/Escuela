#pragma once
#ifndef _PALABRA_H_
#define _PALABRA_H_

#include "Token.h"
ref class Palabra :
public Token
{
public:
	String^ lexema;
	static Palabra ^and = gcnew Palabra("&&", Etiqueta::AND);
	static Palabra ^or = gcnew Palabra("||", Etiqueta::OR);
	static Palabra ^eq = gcnew Palabra("==", Etiqueta::EQ);
	static Palabra ^ne = gcnew Palabra("!=", Etiqueta::NE);
	static Palabra ^le = gcnew Palabra("<=", Etiqueta::LE);
	static Palabra ^ge = gcnew Palabra(">=", Etiqueta::GE);
	static Palabra ^minus = gcnew Palabra("minus", Etiqueta::MINUS);
	static Palabra ^True = gcnew Palabra("true", Etiqueta::TRUE);
	static Palabra ^False = gcnew Palabra("false", Etiqueta::FALSE);
	static Palabra ^t = gcnew Palabra("t", Etiqueta::TEMP);

	Palabra(String ^s, int etiqueta);
	String^ toString();
	
};
#endif
