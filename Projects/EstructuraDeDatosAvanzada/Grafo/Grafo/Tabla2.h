#ifndef _TABLA_2_H_
#define _TABLA_2_H_

#include "NodoHash2.h"
/**
* Una lista doblemente enlazada basado en la clase ´LinkedList´ de Java.
* @author: Joaquin R. Martinez
*/
class Tabla2
{
private:
	/**
	* Primer nodo de la lista.
	*/
	NodoHash2* first;
	/**
	* NodoHash2 auxiliar (para usar en metodo recursivo ´getLast´).
	*/
	NodoHash2* aux;
	/**
	* Tamaño de la lista.
	*/
	unsigned int size;
	/**
	* Obtiene el ultimo nodo de la lista.
	*/
	NodoHash2* getLast(NodoHash2*n);
	/**
	* Obtiene el nodo de la posicion dada.
	*/
	NodoHash2* getNodeAt(int index);

public:
	/**
	* Crea una nueva lista vacia.
	*/
	Tabla2();
	/**
	* Busca el valor dado y regresa la posicion del primer elemento encontrado con ese valor.
	*/
	int indexOf(NodoHash2* val);
	/**
	* Obtiene el valor de la posicion dada.
	*/
	NodoHash2* getValueAt(int index);
	/**
	* Establece el valor dado en la posicion ´index´.
	*/
	void setValueAt(int index, NodoHash2* val);
	/**
	* Añade un nuevo elemento al final de la lista .
	*/
	void add(NodoHash2* val);
	void add(string key, int value);
	/**
	* Elimina un elemento (nodo) en la posicion ´index´.
	*/
	void removeElementAt(int index);
	/**
	* Inserta un nuevo elemento en la posicion ´index´ con el valor ´val´.
	*/
	void insertElementAt(unsigned int index, NodoHash2* val);
	/**
	* Obtiene el tamaño de la lista.
	*/
	unsigned int getSize();
	/**
	* Verifica si la lista está vacía.
	*/
	bool isEmpty();
	/**
	* Limpia la lista dejandola vacia.
	*/
	void clear();
	NodoHash2* get(string key);
	void set(string key, int value);
	/**
	* Destructor de la lista. Limpia la lista de elementos si es que lo hay.
	*/
	~Tabla2();
	void operator = (Tabla2& t){
		for (size_t i = 0; i < this->getSize(); i++)
		{
			this->setValueAt(i, t.getValueAt(i));
		}
	}
};

#endif