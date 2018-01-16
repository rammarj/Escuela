#ifndef NOOD_H
#define NOOD_H

#include <iostream>

using namespace std;

class Nodo
{
public:
	Nodo();
	~Nodo();
	string getDato();
	void setDato(string);
	void setNodo(Nodo*);
	Nodo* getNodo();

private:
	string dato;
	Nodo *siguiente;
};

Nodo::Nodo()
{
	this->dato = "";
}

Nodo* Nodo::getNodo(){
	return this->siguiente;
}

Nodo::~Nodo()
{	
}

string Nodo::getDato(){
	return this->dato;
}

void Nodo::setDato(string i){
	this->dato = i;
}

void Nodo::setNodo(Nodo* n){
	this->siguiente = n;
}

#endif
