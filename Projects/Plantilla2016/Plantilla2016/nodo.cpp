#include "stdafx.h"
#include "nodo.h"

template<class type>
Nodo<type>::Nodo(type dato)
{
	this->dato = dato;
	siguiente = NULL;
}

template<class type>
Nodo<type>::~Nodo()
{
	delete(siguiente);
}

template<class type>
void Nodo<type>::setDato(type dato)
{
	this->dato = dato;
}