#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
	this->value = 0;
	this->next = nullptr;
	this->before = nullptr;
}

void Nodo::setNext(Nodo* next){
	this->next = next;
}

Nodo* Nodo::getNext(){
	return(this->next);
}

void Nodo::setBefore(Nodo* before){
	this->before = before;
}

Nodo* Nodo::getBefore(){
	return(this->before);
}

void Nodo::setData(int value){
	this->value = value;
}

int Nodo::getData(){
	return(this->value);
}

Nodo::~Nodo(){}
