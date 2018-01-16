#ifndef _NODO_H_
#define _NODO_H_

#include "stdafx.h"

template <class key, class value>
class Nodo
{
private:
	Nodo<key,value>* anterior;
	Nodo<key, value>* siguiente;
	key* clave;	
	value* valor;

public:
	Nodo(key clave, value valor);
	~Nodo();
	template <class T> friend class TablaHash;
};

#endif