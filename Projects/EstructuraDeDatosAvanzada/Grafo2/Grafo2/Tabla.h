#ifndef _TABLA_H_
#define _TABLA_H_

#include "NodoHash.h"
/**
* Una lista doblemente enlazada basado en la clase ´LinkedList´ de Java.
* @author: Joaquin R. Martinez
*/
class Tabla
{
private:
	/**
	* Primer nodo de la lista.
	*/
	NodoHash* first;
	/**
	* NodoHash auxiliar (para usar en metodo recursivo ´getLast´).
	*/
	NodoHash* aux;
	/**
	* Tamaño de la lista.
	*/
	unsigned int size;
	/**
	* Obtiene el ultimo nodo de la lista.
	*/
	NodoHash* getLast(NodoHash*n);
	/**
	* Obtiene el nodo de la posicion dada.
	*/
	NodoHash* getNodeAt(int index);

public:
	/**
	* Crea una nueva lista vacia.
	*/
	Tabla();
	/**
	* Busca el valor dado y regresa la posicion del primer elemento encontrado con ese valor.
	*/
	int indexOf(NodoHash* val);
	/**
	* Obtiene el valor de la posicion dada.
	*/
	NodoHash* getValueAt(int index);
	/**
	* Establece el valor dado en la posicion ´index´.
	*/
	void setValueAt(int index, NodoHash* val);
	/**
	* Añade un nuevo elemento al final de la lista .
	*/
	void add(NodoHash* val);
	void add(string key, string value);
	/**
	* Elimina un elemento (nodo) en la posicion ´index´.
	*/
	void removeElementAt(int index);
	/**
	* Inserta un nuevo elemento en la posicion ´index´ con el valor ´val´.
	*/
	void insertElementAt(unsigned int index, NodoHash* val);
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
	NodoHash* get(string key);
	void set(string key, string value);
	/**
	* Destructor de la lista. Limpia la lista de elementos si es que lo hay.
	*/
	~Tabla();
	void operator = (Tabla& t){
		for (size_t i = 0; i < this->getSize(); i++)
		{
			this->setValueAt(i, t.getValueAt(i));
		}
	}
};

#endif