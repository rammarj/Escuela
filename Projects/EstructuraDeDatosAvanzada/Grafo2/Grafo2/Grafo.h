#pragma once
#include "Lista.h"

class Grafo
{
private:
	Lista* alf;

public:
	Grafo();
	void addAlfabeto(string in);
	
	~Grafo();
};

