#pragma once
#ifndef _REAL_H_
#define _REAL_H_

#include "Token.h"
ref class Real :
public Token
{
public:
	float valor;
	Real(float v);
	String^ toString();
};
#endif
