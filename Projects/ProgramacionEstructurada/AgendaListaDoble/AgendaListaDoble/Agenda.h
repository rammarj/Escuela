#pragma once
#include "Lista.h"
class Agenda
{
private:
	Lista* contactos;

public:
	Agenda();
	void addContact(Contacto c);
	int search(string name);
	Lista *getLista();
	~Agenda();
};

