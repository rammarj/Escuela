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
	int pivote(int , int );
	void quick_sort(int, int);

public:
	Lista();
	void agregar(type dato, int posicion);
	void eliminarDato(type dato);
	void eliminarPosicion(int posicion);
	int buscar(type dato);
	type mostrar(int posicion);
	int getTamano();
	bool vacia();
	void reemplazar(int pos, type nuevo);
	~Lista();
	//ordenamiento
	void ordenar_quick_sort();
	void ordenar_burbuja();
	void ordenar_seleccion_directa();
	void ordenar_insercion();
	//busquedas
	Lista<int> buscar_secuencial(type t);
	Lista<int> buscar_binaria(type dato);
};

#endif // LISTA_H
