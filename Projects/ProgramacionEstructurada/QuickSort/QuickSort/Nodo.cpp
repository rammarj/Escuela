#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
	this->value = 0;
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

void Nodo::setData(int value){
	this->value = value;
}

int Nodo::getData(){
	return(this->value);
}

Nodo::~Nodo(){}
