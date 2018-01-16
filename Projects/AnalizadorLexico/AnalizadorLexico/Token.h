#pragma once
#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "Etiqueta.h"
using namespace System;

ref class Token
{
public:
	int etiqueta;
	Token(int t);
	String^ toString();
};
#endif
