#include "stdafx.h"
#include "Nodo.h"
template <class key, class value>
Nodo<key, value>::Nodo(key clave, value valor)
{
	this->clave = new key(clave);
	this->valor = new value(valor);
	this->siguiente = NULL;
	this->anterior = NULL;
}

template <class key, class value>
Nodo<key, value>::~Nodo(){
	delete this->clave;
	delete this->valor;
	delete this->siguiente;
	delete this->anterior;
}