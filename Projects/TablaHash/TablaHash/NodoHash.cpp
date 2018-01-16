#include "stdafx.h"
#include "NodoHash.h"

NodoHash::NodoHash(){
	this->clave = 0;
	this->valor = "";
}

long double NodoHash::getClave(){
	return this->clave;
}

string NodoHash::getValor(){
	return this->valor;
}

void NodoHash::setClave(long double clave){
	this->clave = clave;
}

void NodoHash::setValor(string valor){
	this->valor = valor;
}

NodoHash::~NodoHash(){}
