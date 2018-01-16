
#include "stdafx.h"
#include "Lista.h"

#include <iostream>

using namespace std;

template<class tipo>
Lista<tipo>::Lista()
{
	this->first = nullptr;
	this->size = 0;
	this->aux = nullptr;
}

template<class tipo>
Nodo<tipo>* Lista<tipo>::getLast(Nodo<tipo>* n){
	if (n != nullptr){
		this->aux = n->getNext();
		if (aux)
		{
			getLast(this->aux);
		}
		else{
			return n;
		}
	}
	return aux;
}

template<class tipo>
Nodo<tipo>* Lista<tipo>::getNodeAt(int index){
	Nodo<tipo>* ret = this->first;
	if (index >= 0 && index<this->size)
	{
		for (size_t i = 0; i < index; i++)
		{
			ret = ret->getNext();
		}
	}
	return ret;
}

template<class tipo>
void Lista<tipo>::add(tipo val){
	Nodo<tipo>* nuevo = new Nodo<tipo>();
	if (nuevo){
		nuevo->setData(val);
		if (this->size == 0)
		{
			this->first = nuevo;
		}
		else{
			Nodo<tipo>* last = nullptr;
			last = getLast(this->first);
			last->setNext(nuevo);
			nuevo->setAfter(last);
		}
		this->size++;
	}
}

template<class tipo>
int Lista<tipo>::indexOf(tipo val){
	for (size_t i = 0; i < this->size; i++)
	{
		int current = getValueAt(i);
		if (current == val)
		{
			return i;
		}
	}
	return -1;
}

template<class tipo>
tipo Lista<tipo>::getValueAt(int index){
	Nodo<tipo>* ret = getNodeAt(index);
	return ret->getData();
}
template<class tipo>

void Lista<tipo>::setValueAt(int index, tipo val){
	getNodeAt(index)->setData(val);
}

template<class tipo>
bool Lista<tipo>::isEmpty(){
	return(this->first==nullptr);
}

template<class tipo>
void Lista<tipo>::removeElementAt(int index){
	if (index>=0 && index<this->size)
	{
		Nodo<tipo>* del = nullptr;
		if (index>0)
		{
			Nodo<tipo>* ret = getNodeAt(index - 1);
			del = ret->getNext();
			if (del->getNext())
			{
				ret->setNext(del->getNext());
				del->getNext()->setAfter(ret);
			}
			delete del;
		}
		else if (index == 0)
		{
			del = getNodeAt(index);
			this->first = del->getNext();
			delete del;
		}
		this->size--;
	}
}

template<class tipo>
void Lista<tipo>::insertElementAt(unsigned int index, tipo data){
	if (index >= 0){
		Nodo<tipo>* nuevo = new Nodo<tipo>();
		if (nuevo)
		{
			nuevo->setData(data);
			Nodo<tipo>* pos = getNodeAt(index);
			if (pos){
				Nodo<tipo>* ant = pos->getAfter();
				nuevo->setAfter(ant);
				nuevo->setNext(pos);
				pos->setAfter(nuevo);
				if (index>0)
				{
					ant->setNext(nuevo);
				}
			}
			if (index == 0){
				this->first = nuevo;
			}
			this->size++;
		}
	}
}

template<class tipo>
unsigned int Lista<tipo>::getSize(){
	return(this->size);
}

template<class tipo>
void Lista<tipo>::clear(){
	if (!isEmpty() && this->size>0)
	{
		removeElementAt(0);
		clear();
	}
}

template<class tipo>
Lista<tipo>::~Lista(){
	clear();
}
