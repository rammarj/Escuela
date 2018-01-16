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

void Lista::add(Persona nodo){
	Nodo* nuevo = new Nodo();
	if (nuevo)
	{
		nuevo->setData(nodo);
		if (this->size == 0)
		{
			this->first = nuevo;
		}
		else{
			Nodo* last = getLast(this->first);
			last->setNext(nuevo);
		}
		this->size++;
	}
}

int Lista::indexOf(Persona contact){
	for (size_t i = 0; i < this->size; i++)
	{
		Persona current = getValueAt(i);
		if (current == contact)
		{
			return i;
		}
	}
	return -1;
}

Persona Lista::getValueAt(int index){
	Nodo* ret = this->first;
	if (index>=0&&index<this->size)
	{
		for (size_t i = 0; i < index; i++)
		{
			ret = ret->getNext();
		}
		return ret->getData();
	}
}

void Lista::removeElementAt(int index){
	if (index>=0&&index<this->size)
	{
		Nodo* del;
		if (index>0 && getNodeAt(index))
		{
			Nodo* ret = getNodeAt(index-1);
			del = ret->getNext();
			if (del){
				ret->setNext(del->getNext());
				delete del;
			}
			else{
				ret->setNext(nullptr);
			}
		}
		else if(index == 0)
		{
			del = getNodeAt(index);
			this->first = del->getNext();
			delete del;
		}
		this->size--;
	}
}

void Lista::insertElementAt(int index, Persona contact){
	if (index >= 0){
		Nodo* nuevo = new Nodo();
		if (nuevo)
		{
			nuevo->setData(contact);
			Nodo* pos = getNodeAt(index);
			if (pos){
				nuevo->setNext(pos);
				if (getNodeAt(index-1))
				{
					getNodeAt(index - 1)->setNext(nuevo);
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

bool Lista::isEmpty(){
	return(this->first == nullptr);
}

Lista::~Lista()
{
	clear();
}
