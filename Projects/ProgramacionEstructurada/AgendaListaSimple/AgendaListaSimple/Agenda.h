#pragma once
#include "Lista.h"
class Agenda
{
private:
	Lista* contactos;

public:
	Agenda();
	int search(string name);
	Lista* getLista();
	~Agenda();
};

