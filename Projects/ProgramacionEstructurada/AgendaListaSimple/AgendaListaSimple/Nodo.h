#pragma once
#include "Persona.h"

class Nodo
{
private:
	Nodo* next;
	Persona contact;

public:
	Nodo();
	void setNext(Nodo* next);
	void setData(Persona contact);
	Nodo* getNext();
	Persona getData();
	~Nodo();
};

