#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo* first;
	Nodo* aux;
	unsigned int size;
	Nodo* getLast(Nodo*n);
	Nodo* getNodeAt(int index);
	int pivot(int start, int end);
	void quickSort(int start, int end);

public:
	Lista();
	int indexOf(int val);
	int getValueAt(int index);
	void setValueAt(int index, int val);
	void add(int val);
	void removeElementAt(int index);
	void insertElementAt(unsigned int index, int val);
	unsigned int getSize();
	bool isEmpty();
	void clear();
	void sort();
	~Lista();
};

