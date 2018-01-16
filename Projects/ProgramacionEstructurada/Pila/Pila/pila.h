#ifndef PILA_H
#define PILA_H

#include "nodo.h"

class Pila{

	public:
		Pila();
		void pop();
		void push(string);
		Nodo* getTope();
		bool vacio();
		int getSize();
		~Pila();

	private:
		Nodo* tope;
		int elementos;

};

Pila::Pila()
{
	this->elementos = 0;
	this->tope = NULL;
}

Pila::~Pila()
{
	while (!vacio()){
		pop();
	}
}

bool Pila::vacio(){
	return (tope==NULL);
}

void Pila::pop(){
	Nodo* aux;
	aux = tope;
	if (!vacio()){
		tope = aux->getNodo();
		this->elementos--;
		delete aux;
	}
}

void Pila::push(string i){
	Nodo* nuevo = new Nodo();
	if (nuevo){
		nuevo->setNodo(this->tope);
		nuevo->setDato(i);
		this->tope = nuevo;
		elementos++;
	}
}

Nodo* Pila::getTope(){
	return this->tope;
}

int Pila::getSize()
{
	return this->elementos;
}

#endif
