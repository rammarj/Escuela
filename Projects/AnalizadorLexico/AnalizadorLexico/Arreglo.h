#ifndef _ARREGLO_H_
#define _ARREGLO_H_

#include "Tipo.h"

ref class Arreglo :
public Tipo
{
public:
	Tipo ^de;
	int tamanio = 1;
	Arreglo(int tm, Tipo ^p);
	String^ toString();
};

#endif