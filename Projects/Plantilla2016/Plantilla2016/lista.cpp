
#include "stdafx.h"
#include "lista.h"

template <class type>
Lista<type>::Lista()
{
	primero = NULL;
	ultimo = NULL;
	tamano = 0;
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
				return(NULL);
		}
		return(indice->dato);
	}
}

template <class type>
int Lista<type>::getTamano()
{
	return(tamano);
}

template <class type>
bool Lista<type>::vacia()
{
	if (primero == NULL)
		return(true);
	else
		return(false);
}

//nuevo metodo que sirve para reemplazar un valor en una posicion
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

template<class type>
int Lista<type>::pivote(int izq, int der){
	int i;
	int pivote, valor_pivote;
	int aux;
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

template <class type>
Lista<type>::~Lista()
{

}

template<class type>
void Lista<type>::quick_sort(int izq, int der){
	int pivote;
	if (izq < der){
		pivote = pivot(izq, der);
		quickSort(izq, pivote - 1);
		quickSort(pivote + 1, der);
	}
}
////////////////////
////////BUSQUEDAS//
///////////////////
//busqueda binaria
template<class type>
Lista<int> Lista<type>::buscar_binaria(type clave)
{
	int pos = -1;
	Lista<int> posiciones;	
	for (int i = 0; i < this->getTamano(); i++)
	{
		pos = buscarPos(clave);
		if (pos != -1 && posiciones.buscar(pos) == -1)
		{
			posiciones.agregar(pos, posiciones.getTamano());
		}
	}
	return posiciones;
}
//busqueda secuencial
template<class type>
Lista<int> Lista<type>::buscar_secuencial(type t){
	type aux;
	Lista<int> posiciones; //la lista de posiciones
	for (unsigned int i = 0; i < this->getTamano(); i++) //recorrer toda la lista
	{
		aux = this->mostrar(i);
		if (aux == t) //comparar si es el que se esta buscando
		{
			posiciones.agregar(i, posiciones.getTamano()); //aniadir la posicion a la lista
		}
	}
	return posiciones;
}

///////////////////////
////////ORDENAMIENTO//
//////////////////////

//ordenamiento burbuja
template<class type>
void Lista<type>::ordenar_burbuja(){
	type aux;
	for (int i = 0; i < this->getTamano(); i++)//numero de movimientos
	{
		for (int j = 0; j < (this->getTamano() - 1); j++)//ordenar el contenido de la lista
		{
			if (this->mostrar(j) > this->mostrar((j + 1)))
			{
				aux = this->mostrar(j);
				this->reemplazar(j, this->mostrar((j + 1)));
				this->reemplazar((j + 1), aux);
			}
		}
	}
}

//ordenamiento quicksort
template<class type>
void Lista<type>::ordenar_quick_sort(){
	quick_ordenar(0, this->size - 1);
}

//ordenamiento por seleccion directa
template<class type>
void Lista<type>::ordenar_seleccion_directa(){
	type menor, aux;
	int pos_menor;
	for (unsigned int i = 0; i < this->getTamano(); i++)
	{
		menor = this->mostrar(i);
		pos_menor = i;
		//buscar el menor y su posicion
		for (unsigned int j = (i + 1); j < this->getTamano(); j++)
		{
			if (this->mostrar(j) < menor)
			{
				menor = this->mostrar(j);
				pos_menor = j;
			}
		}
		//hacer el intercambio
		aux = mostrar(i);
		this->reemplazar(i, menor);
		this->reemplazar(pos_menor, aux);
	}
}

//ordenamiento por insercion
template<class type>
void Lista<type>::ordenar_insercion(){
	int i, a;
	type aux;
	for (i = 1; i < this->getTamano(); i++) //empezar desde 1
	{
		aux = this->mostrar(i); //guardar el valor a comparar en un auxiliar
		for (a = (i - 1); a >= 0 && this->mostrar(a) > aux; a--)
		{
			this->reemplazar(a + 1, this->mostrar(a)); //recorrer los elementos
		}
		this->reemplazar(a + 1, aux); //poner al elemento en su pocicion real
	}
}

