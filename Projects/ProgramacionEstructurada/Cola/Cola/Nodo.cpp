#include "Nodo.h"
#include <iostream>

using namespace std;

Nodo::Nodo()
{
	this->siguiente = NULL;
	this->dato = new char[30];
}

string Nodo::getDato(){
	return this->dato;
}

Nodo* Nodo::getNodo(){
	return this->siguiente;
}

void Nodo::setDato(string dato){
	this->dato = dato;
}

void Nodo::setNodo(Nodo* nodo){
	this->siguiente = nodo;
}

Nodo::~Nodo(){

}
