#pragma once
#include <iostream>
using namespace std;
class Nodo
{
public:
	Nodo();
	string getDato();
	void setDato(string);
	void setNodo(Nodo*);
	Nodo* getNodo();
	~Nodo();

private:
	Nodo* siguiente;
	string dato;

};

