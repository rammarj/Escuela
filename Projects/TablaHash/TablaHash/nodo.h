#pragma once
#ifndef NODO_H
#define NODO_H

template <class type>
class Nodo
{
private:
	type dato;
	Nodo<type> *siguiente;
public:
	Nodo(type dato);
	void setDato(type dato);
	~Nodo();
	template <class tipo> friend class Lista;
};

#endif // NODO_H

