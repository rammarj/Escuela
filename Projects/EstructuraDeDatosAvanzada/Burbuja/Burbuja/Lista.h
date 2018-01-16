
#include "Nodo.h"
/**
* Una lista doblemente enlazada basado en la clase ´LinkedList´ de Java.
* @author: Joaquin R. Martinez
*/
class Lista
{
private:
	/**
	* Primer nodo de la lista.
	*/
	Nodo* first;
	/**
	* Nodo auxiliar (para usar en metodo recursivo ´getLast´).
	*/
	Nodo* aux;
	/**
	* Tamaño de la lista.
	*/
	unsigned int size;
	/**
	* Obtiene el ultimo nodo de la lista.
	*/
	Nodo* getLast(Nodo*n);
	/**
	* Obtiene el nodo de la posicion dada.
	*/
	Nodo* getNodeAt(int index);

public:
	/**
	* Crea una nueva lista vacia.
	*/
	Lista();
	/**
	* Busca el valor dado y regresa la posicion del primer elemento encontrado con ese valor.
	*/
	int indexOf(int val);
	/**
	* Obtiene el valor de la posicion dada.
	*/
	int getValueAt(int index);
	/**
	* Establece el valor dado en la posicion ´index´.
	*/
	void setValueAt(int index, int val);
	/**
	* Añade un nuevo elemento al final de la lista .
	*/
	void add(int val);
	/**
	* Elimina un elemento (nodo) en la posicion ´index´.
	*/
	void removeElementAt(int index);
	/**
	* Inserta un nuevo elemento en la posicion ´index´ con el valor ´val´.
	*/
	void insertElementAt(unsigned int index, int val);
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
	/**
	* Ordena la lista (metodo burbuja).
	*/
	void sort_burbuja();
	void sort_seleccion_directa();
	/**
	* Destructor de la lista. Limpia la lista de elementos si es que lo hay.
	*/
	~Lista();
};

