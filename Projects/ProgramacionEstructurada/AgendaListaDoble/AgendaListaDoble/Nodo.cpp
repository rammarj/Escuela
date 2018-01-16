#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
	this->contact = Contacto();
	this->next = nullptr;
	this->after = nullptr;
}

void Nodo::setNext(Nodo* next){
	this->next = next;
}

Nodo* Nodo::getNext(){
	return(this->next);
}

void Nodo::setAfter(Nodo* after){
	this->after = after;
}

Nodo* Nodo::getAfter(){
	return(this->after);
}

void Nodo::setData(Contacto contact){
	this->contact = contact;
}

Contacto Nodo::getData(){
	return(this->contact);
}

Nodo::~Nodo(){ }
