#ifndef _TABLA_HASH_H_
#define _TABLA_HASH_H_

#include "stdafx.h"
#include "Nodo.cpp"

template<class key, class value>
class TablaHash
{
private:
	Nodo<key,value>* first;
	Nodo<key, value>* aux;
	unsigned int size;
	Nodo<key, value>* getLast(Nodo<key, value>*);
	Nodo<key, value>* getNodeAt(Nodo<key, value>*, key);
	Nodo<key, value>* getNodeAt(Nodo<key, value>*, unsigned int);
	int pivot(int, int);
	void quickSort(int, int);
	int pos = 0;

public:
	TablaHash();
	value getValue(key);
	void setValueAt(key, value);
	void setValueAt(int, Nodo<key, value>*);
	void add(key, value);
	void removeElement(key);
	unsigned int getSize();
	bool isEmpty();
	void clear();
	void quick_sort();
	~TablaHash();
};

#endif