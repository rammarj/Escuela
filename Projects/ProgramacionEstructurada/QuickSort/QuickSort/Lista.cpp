#include "stdafx.h"
#include "Lista.h"

Lista::Lista()
{
	this->first = nullptr;
	this->size = 0;
	this->aux = nullptr;
}

Nodo* Lista::getLast(Nodo* n){
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
	else{
		return aux;
	}
}

Nodo* Lista::getNodeAt(int index){
	Nodo* ret = this->first;
	if (index >= 0 && index<this->size)
	{
		for (size_t i = 0; i < index; i++)
		{
			ret = ret->getNext();
		}
	}
	return ret;
}

int Lista::pivot( int izq, int der){
	int i;
	int pivote, valor_pivote;
	int aux;
	pivote = izq;
	valor_pivote = getValueAt(pivote);
	for (i = izq + 1; i <= der; i++){
		if (getValueAt(i) < valor_pivote){
			pivote++;
			aux = getValueAt(i);
			setValueAt(i, getValueAt(pivote));
			setValueAt(pivote, aux);

		}
	}
	aux = getValueAt(izq);
	setValueAt(izq, getValueAt(pivote));
	setValueAt(pivote, aux);
	return pivote;
}

void Lista::quickSort( int izq, int der){
	int pivote;
	if (izq < der){
		pivote = pivot(izq, der);
		quickSort(izq, pivote - 1);
		quickSort(pivote + 1, der);
	}
}

void Lista::add(int val){
	Nodo* nuevo = new Nodo();
	if (nuevo){
		nuevo->setData(val);
		if (this->size == 0)
		{
			this->first = nuevo;
		}
		else{
			Nodo* last = nullptr;
			last = getLast(this->first);
			last->setNext(nuevo);
			nuevo->setAfter(last);
		}
		this->size++;
	}
}

int Lista::indexOf(int val){
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

int Lista::getValueAt(int index){
	Nodo* ret = getNodeAt(index);
	return ret->getData();
}

void Lista::setValueAt(int index, int val){
	getNodeAt(index)->setData(val);
}

bool Lista::isEmpty(){
	return(this->first==nullptr);
}

void Lista::removeElementAt(int index){
	if (index>=0 && index<this->size)
	{
		Nodo* del = nullptr;
		if (index>0)
		{
			Nodo* ret = getNodeAt(index - 1);
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

void Lista::insertElementAt(unsigned int index, int data){
	if (index >= 0){
		Nodo* nuevo = new Nodo();
		if (nuevo)
		{
			nuevo->setData(data);
			Nodo* pos = getNodeAt(index);
			if (pos){
				Nodo* ant = pos->getAfter();
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

unsigned int Lista::getSize(){
	return(this->size);
}

void Lista::clear(){
	if (!isEmpty() && this->size>0)
	{
		removeElementAt(0);
		clear();
	}
}

void Lista::sort(){
	quickSort(0, this->size-1);
}

Lista::~Lista(){
	clear();
}
