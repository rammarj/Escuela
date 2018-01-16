#pragma once
#include "Contacto.h"

class Nodo
{
private:
	Nodo* next;
	Nodo* after;
	Contacto contact;

public:
	Nodo();
	void setNext(Nodo* next);
	void setData(Contacto contact);
	Nodo* getNext();
	Contacto getData();
	void setAfter(Nodo* after);
	Nodo* getAfter();
	~Nodo();
};

