#pragma once

#include "Nodo.h"

class Cola
{
public:
	Cola();
	int getSize();
	//Nodo* getTope();
	Nodo* getFirst();
	void push(string);
	bool isEmpty();
	void pop();
	~Cola();

private:
	Nodo *tope, *primero;
	int size;

};

