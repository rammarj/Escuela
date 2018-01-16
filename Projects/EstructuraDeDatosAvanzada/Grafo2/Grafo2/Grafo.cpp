#include "stdafx.h"
#include "Grafo.h"


Grafo::Grafo()
{
	this->alf = new Lista();
}


void Grafo::addAlfabeto(string in){
	this->alf->add(in);
}

Grafo::~Grafo()
{
	delete this->alf;
}
