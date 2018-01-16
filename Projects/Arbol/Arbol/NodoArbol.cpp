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
void setDato(type*dato){
	this->dato = dato;
}

template <class type>
void setDerecho(Nodo<type>* derecho){
	this->derecho = derecho;
}

template <class type>
void setIzquierdo(Nodo<type>* izquierdo){
	this->izquierdo = izquierdo;
}

template <class type>
Nodo<type>::~Nodo()
{
	delete this->dato;
	delete this->izquierdo;
	delete this->derecho;
}

template <class type>
type* Nodo<type>::getDato()
{
	return (this->dato);
}


