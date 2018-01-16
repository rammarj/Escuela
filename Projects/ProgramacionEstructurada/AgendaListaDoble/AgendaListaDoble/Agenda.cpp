#include "stdafx.h"
#include "Agenda.h"


Agenda::Agenda()
{
	this->contactos = new Lista();
}

void Agenda::addContact(Contacto c){
	this->contactos->add(c);
}

int Agenda::search(string name){
	for (size_t i = 0; i < this->contactos->getSize(); i++)
	{
		if (this->contactos->getValueAt(i).getNombre() == name)
		{
			return i;
		}
	}
	return -1;
}

Lista* Agenda::getLista(){
	return this->contactos;
}

Agenda::~Agenda()
{
	if (this->contactos)
	{
		delete this->contactos;
	}
}
