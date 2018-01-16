#include "stdafx.h"
#include "Lista.h"
#include <iostream>

using namespace std;

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
			nuevo->setBefore(last);
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
				del->getNext()->setBefore(ret);
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
				Nodo* ant = pos->getBefore();
				nuevo->setBefore(ant);
				nuevo->setNext(pos);
				pos->setBefore(nuevo);
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

void Lista::sort_burbuja(){
	int aux;
	for (size_t i = 0; i < this->getSize(); i++)
	{
		for (size_t j = 0; j < (this->getSize()-1); j++)
		{
			if ( this->getValueAt(j) > this->getValueAt( (j+1) ) )
			{
				aux = this->getValueAt(j);
				this->setValueAt(j, this->getValueAt((j+1)));
				this->setValueAt( (j+1), aux);
			}
		}
	}
}

void Lista::sort_seleccion_directa(){
	int menor, pos_menor, aux;
	for (unsigned int i = 0; i < this->getSize(); i++)
	{
		menor = this->getValueAt(i);
		pos_menor = i;
		for (unsigned int j = (i+1); j < this->getSize(); j++)
		{
			if (this->getValueAt(j)<menor)
			{
				menor = this->getValueAt(j);
				pos_menor = j;
			}
		}
		aux = getValueAt(i);
		this->setValueAt(i, menor);
		this->setValueAt(pos_menor, aux);
	}
}


Lista::~Lista(){
	clear();
}
