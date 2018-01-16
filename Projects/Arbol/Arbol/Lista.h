#ifndef _LISTA_H_
#define _LISTA_H_

#include "NodoLista.cpp"

template<class tipo>
class Lista
{
private:
	NodoLista<tipo>* first;
	NodoLista<tipo>* aux;
	unsigned int size;
	NodoLista<tipo>* getLast(NodoLista<tipo>*n);
	NodoLista<tipo>* getNodeAt(int index);
	int pivot(int start, int end);
	void quickSort(int start, int end);
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
	void quick_sort();
	void sort_burbuja();
	void sort_seleccion_directa();
	void sort_insercion();

	Lista<int>* find_secuencial(tipo t);
	Lista<int>* find_binaria(tipo t);
	int busquedaBinaria(tipo clave, int desde);

	~Lista();

	void operator=(Lista<tipo> &l){
		for (unsigned int i = 0; i < l.getSize(); i++)
		{
			add(l.getValueAt(i));
		}
	}
};

#endif