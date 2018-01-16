#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
	this->value = "";
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

void Nodo::setData(string value){
	this->value = value;
}

string Nodo::getData(){
	return(this->value);
}

Nodo::~Nodo(){}
