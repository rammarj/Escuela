#include "Cola.h"

Cola::Cola()
{
	this->size = 0;
	this->tope = NULL;
}

void Cola::push(string i){
	Nodo* nuevo = new Nodo();
	if (nuevo){
		nuevo->setDato(i);
		if (this->tope){
			this->tope->setNodo(nuevo);
			this->tope = nuevo;
		}
		else
		{
			this->tope = nuevo;
			this->primero = nuevo;
		}
		this->size++;
	}
}

bool Cola::isEmpty(){
	return (this->tope == NULL);
}

int Cola::getSize(){
	return this->size;
}

Nodo* Cola::getFirst(){
	return this->primero;
}

void Cola::pop(){
	if (!isEmpty()){
		Nodo* aux = getFirst();
		if (aux->getNodo()){
			this->primero = aux->getNodo();
		}
		else{
			this->primero = NULL;
			this->tope = NULL;
		}
		this->size--;
		delete aux;
	}
}

Cola::~Cola()
{
	while (!isEmpty())
	{
		pop();
	}
}
