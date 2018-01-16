#ifndef _LISTA_H_
#define _LISTA_H_

#include "NodoLista.cpp"

template<class tipo>
class Lista
{
private:
	Nodo<tipo>* first;
	Nodo<tipo>* aux;
	unsigned int size;
	Nodo<tipo>* getLast(Nodo<tipo>*n);
	Nodo<tipo>* getNodeAt(int index);
	int pos = 0;

public:
	Lista();
	int indexOf(tipo val);
	tipo getValueAt(int index);
	void setValueAt(int index, tipo val);
	void add(tipo val);
	void removeElementAt(int index);
	void insertElementAt(unsigned int index, tipo val);
	unsigned int getSize();
	bool isEmpty();
	void clear();
	~Lista();
};

#endif