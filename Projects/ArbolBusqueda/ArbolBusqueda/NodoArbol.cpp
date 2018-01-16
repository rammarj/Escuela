#include "stdafx.h"
#include "NodoArbol.h"

template <class type>
Nodo<type>::Nodo(type* nodo)
{
	this->dato = nodo;
	this->izquierdo = NULL;
	this->derecho = NULL;
}

template <class type>
Nodo<type>::~Nodo()
{
	delete this->dato;
	delete this->izquierdo;
	delete this->derecho;
}


