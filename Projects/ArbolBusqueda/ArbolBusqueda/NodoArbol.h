#ifndef _NODO_ARBOL_H_
#define _NODO_ARBOL_H_

template <class type>

class Nodo
{
private:
	type* dato;
	Nodo* izquierdo;
	Nodo* derecho;

public:
	Nodo(type* dato);
	~Nodo(); 
	template <class T> friend class Arbol;
};

#endif
