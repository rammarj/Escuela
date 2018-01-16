
#include "stdafx.h"
#include "Lista.h"

template <class type>
Lista<type>::Lista()
{
	primero = NULL;
	ultimo = NULL;
	tamano = 0;
}

template <class type>
void Lista<type>::agregar(type dato){
	this->agregar(dato, this->getTamano());
}

template <class type>
void Lista<type>::agregar(type dato, int posicion)
{
	if (posicion >= 0 && posicion <= tamano)
	{
		Nodo<type> *nuevo;
		nuevo = new Nodo<type>(dato);
		if (posicion == 0)
		{
			if (tamano == 0)
			{
				nuevo->siguiente = NULL;
				ultimo = nuevo;
			}
			else
			{
				nuevo->siguiente = primero;
			}
			primero = nuevo;
		}
		if (posicion > 0 && posicion < tamano)
		{
			int i = 0;
			Nodo<type> *auxiliar = primero;
			while (i < posicion - 1)
			{
				auxiliar = auxiliar->siguiente;
				i++;
			}
			nuevo->siguiente = auxiliar->siguiente;
			auxiliar->siguiente = nuevo;
		}
		if (posicion == tamano)
		{
			nuevo->siguiente = NULL;
			ultimo->siguiente = nuevo;
			ultimo = nuevo;
		}
		nuevo = NULL;
		tamano++;
	}
}

template <class type>
void Lista<type>::eliminarDato(type dato)
{
	if (tamano > 0)
	{
		Nodo<type> *eliminar, *auxiliar;
		int posicion = 0;
		eliminar = primero;
		auxiliar = NULL;
		while (eliminar->dato != dato)
		{
			auxiliar = eliminar;
			eliminar = eliminar->siguiente;
			posicion++;
			if (eliminar == NULL)
				return;
		}
		if (posicion == 0)
		{
			primero = eliminar->siguiente;
			eliminar->siguiente = NULL;
		}
		else if (posicion > 0 && posicion < tamano - 1)
		{
			auxiliar->siguiente = eliminar->siguiente;
			eliminar->siguiente = NULL;
		}
		else if (posicion == tamano - 1)
		{
			auxiliar->siguiente = NULL;
			ultimo = auxiliar;
		}
		delete(eliminar);
		tamano--;
	}
}

template <class type>
void Lista<type>::eliminarPosicion(int posicion)
{
	if (tamano > 0)
	{
		Nodo<type> *eliminar, *auxiliar;
		int i = 0;
		eliminar = primero;
		auxiliar = NULL;
		while (i != posicion)
		{
			auxiliar = eliminar;
			eliminar = eliminar->siguiente;
			i++;
			if (eliminar == NULL)
				return;
		}
		if (posicion == 0)
		{
			primero = eliminar->siguiente;
			eliminar->siguiente = NULL;
		}
		else if (posicion > 0 && posicion < tamano - 1)
		{
			auxiliar->siguiente = eliminar->siguiente;
			eliminar->siguiente = NULL;
		}
		else if (posicion == tamano - 1)
		{
			auxiliar->siguiente = NULL;
			ultimo = auxiliar;
		}
		delete(eliminar);
		tamano--;
	}
}

template <class type>
int Lista<type>::buscar(type dato)
{
	if (tamano > 0)
	{
		Nodo<type> *indice;
		int posicion = 0;
		indice = primero;
		while (indice->dato != dato)
		{
			indice = indice->siguiente;
			posicion++;
			if (indice == NULL)
				return(-1);
		}
		return(posicion);
	}
}

template <class type>
type Lista<type>::mostrar(int posicion)
{
	if (tamano > 0 && posicion >= 0)
	{
		Nodo<type> *indice;
		int i = 0;
		indice = primero;
		while (i != posicion)
		{
			indice = indice->siguiente;
			i++;
			if (indice == NULL)
				return type();
		}
		return(indice->dato);
	}
	return type();
}

template <class type>
int Lista<type>::getTamano()
{
	return(tamano);
}

template <class type>
bool Lista<type>::vacia()
{
	return (primero == NULL);//corregido codigo innecesario
}

//nuevo metodo que sirve para reemplazar en la posicion el valor dado
template <class type>
void Lista<type>::reemplazar(int pos, type nuevo){
	if (tamano > 0 && pos >= 0)
	{
		type aux;
		Nodo<type> *indice;
		int i = 0;
		indice = primero;
		while (i != pos)
		{
			indice = indice->siguiente;
			i++;
		}
		indice->setDato(nuevo);
	}
}

template<class type>
int Lista<type>::buscarPos(type clave){
	int izquierdo, derecho, puntomedio;
	izquierdo = 0;
	derecho = this->getTamano() - 1;
	while (izquierdo <= derecho)
	{
		puntomedio = (int)((izquierdo + derecho) / 2);
		if (clave == mostrar(puntomedio))
		{
			return puntomedio;
		}
		else if (clave > this->mostrar(puntomedio))
			izquierdo = puntomedio + 1;
		else
			derecho = puntomedio - 1;
	}
	return -1;
}

template <class type>
Lista<type>::~Lista()
{
	
}

template<class type>
int Lista<type>::pivot(int izq, int der){
	int i;
	int pivote;
	type aux, valor_pivote;
	pivote = izq;
	valor_pivote = mostrar(pivote);
	for (i = izq + 1; i <= der; i++){
		if (mostrar(i) < valor_pivote){
			pivote++;
			aux = mostrar(i);
			reemplazar(i, mostrar(pivote));
			reemplazar(pivote, aux);

		}
	}
	aux = mostrar(izq);
	reemplazar(izq, mostrar(pivote));
	reemplazar(pivote, aux);
	return pivote;
}

template<class type>
void Lista<type>::quickSort(int izq, int der){
	int pivote;
	if (izq < der){
		pivote = pivot(izq, der);
		quickSort(izq, pivote - 1);
		quickSort(pivote + 1, der);
	}
}

template<class type>
void Lista<type>::quick_sort(){
	quickSort(0, this->getTamano() - 1);
}
