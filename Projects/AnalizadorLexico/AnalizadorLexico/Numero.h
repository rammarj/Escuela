#pragma once
#ifndef _NUMERO_H_
#define _NUMERO_H_

#include "Token.h"

ref class Numero :
public Token
{
public:
	int valor;
	Numero(int v);
	String^ toString();
};
#endif
