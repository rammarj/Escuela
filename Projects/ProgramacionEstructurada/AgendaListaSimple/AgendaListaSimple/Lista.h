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
	int indexOf(Persona contact);
	Persona getValueAt(int index);
	void add(Persona nodo);
	void removeElementAt(int index);
	void insertElementAt(int index, Persona contact);
	unsigned int getSize();
	void clear();
	bool isEmpty();
	~Lista();
};

