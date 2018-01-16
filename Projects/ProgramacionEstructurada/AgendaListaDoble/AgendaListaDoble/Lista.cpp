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

void Lista::add(Contacto nodo){
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
			nuevo->setAfter(last);
		}
		this->size++;
	}
}

int Lista::indexOf(Contacto contact){
	for (size_t i = 0; i < this->size; i++)
	{
		Contacto current = getValueAt(i);
		if (current == contact)
		{
			return i;
		}
	}
	return -1;
}

Contacto Lista::getValueAt(int index){
	Nodo* ret = getNodeAt(index);
	return ret->getData();
}

void Lista::removeElementAt(int index){
	if (index>=0&&index<this->size)
	{
		Nodo* del;
		if (index>0)
		{
			Nodo* ret = getNodeAt(index-1);
			del = ret->getNext();
			if (del->getNext())
			{
				ret->setNext(del->getNext());
				del->getNext()->setAfter(ret);
			}
			delete del;
		}
		else
		{
			del = getNodeAt(index);
			this->first = del->getNext();
			delete del;
		}
		this->size--;
	}
}

void Lista::insertElementAt(int index, Contacto contact){
	if (index >= 0){
		Nodo* nuevo = new Nodo();
		if (nuevo)
		{
			nuevo->setData(contact);
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

bool Lista::isEmpty(){
	return(this->first == nullptr);
}

void Lista::clear(){
	if (!isEmpty() && this->size>0)
	{
		removeElementAt(0);
		clear();
	}
}

Lista::~Lista()
{
	clear();
}
