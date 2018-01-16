#include "stdafx.h"
#include "Agenda.h"


Agenda::Agenda()
{
	this->contactos = new Lista();
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
	return(this->contactos);
}

Agenda::~Agenda()
{
	if (this->contactos)
	{
		this->contactos->clear();
		delete this->contactos;
	}
}
