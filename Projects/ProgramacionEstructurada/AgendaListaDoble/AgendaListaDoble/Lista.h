#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo* first;
	Nodo* aux;
	unsigned int size;
	Nodo* getLast(Nodo*n);
	Nodo* getNodeAt(int index);

public:
	Lista();
	int indexOf(Contacto contact);
	Contacto getValueAt(int index);
	void add(Contacto nodo);
	void removeElementAt(int index);
	void insertElementAt(int index, Contacto contact);
	unsigned int getSize();
	bool isEmpty();
	void clear();
	~Lista();
};

