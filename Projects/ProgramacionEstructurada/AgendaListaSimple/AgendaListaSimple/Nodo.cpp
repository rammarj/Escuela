#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
	this->contact = Persona();
	this->next = nullptr;
}

void Nodo::setNext(Nodo* next){
	this->next = next;
}

void Nodo::setData(Persona contact){
	this->contact = contact;
}

Nodo* Nodo::getNext(){
	return(this->next);
}

Persona Nodo::getData(){
	return(this->contact);
}

Nodo::~Nodo(){ }
