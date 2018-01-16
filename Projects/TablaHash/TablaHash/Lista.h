#ifndef LISTA_H
#define LISTA_H

#include "nodo.cpp"

template<class type>
class Lista
{
private:
	Nodo<type> *primero;
	Nodo<type> *ultimo;
	int tamano;
	int buscarPos(type clave);
	int pivot(int start, int end);
	void quickSort(int start, int end);

public:
	Lista();
	void agregar(type dato, int posicion);
	void agregar(type dato);
	void eliminarDato(type dato);
	void eliminarPosicion(int posicion);
	int buscar(type dato);
	type mostrar(int posicion);
	int getTamano();
	bool vacia();
	void reemplazar(int pos, type nuevo);
	void quick_sort();
	~Lista();

};

#endif

