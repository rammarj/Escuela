#include "stdafx.h"
#include "Tabla2.h"

Tabla2::Tabla2()
{
	this->first = nullptr;
	this->size = 0;
	this->aux = nullptr;
}

NodoHash2* Tabla2::get(string key){
	for (int i = 0; i < this->getSize(); i++)
	{
		NodoHash2* n = getNodeAt(i);
		if (n->getKey()==key)
		{
			return n;
		}
	}
	return nullptr;
}

void Tabla2::set(string key, int value){
	NodoHash2* n = this->get(key);
	if (n!=nullptr)
	{
		n->setValue(value);
	}
}

NodoHash2* Tabla2::getLast(NodoHash2* n){
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

NodoHash2* Tabla2::getNodeAt(int index){
	NodoHash2* ret = this->first;
	if (index >= 0 && index<this->size)
	{
		for (size_t i = 0; i < index; i++)
		{
			ret = ret->getNext();
		}
	}
	return ret;
}

void Tabla2::add(NodoHash2* nuevo){
	if (nuevo){
		if (this->size == 0)
		{
			this->first = nuevo;
		}
		else{
			NodoHash2* last = nullptr;
			last = getLast(this->first);
			last->setNext(nuevo);
			nuevo->setBefore(last);
		}
		this->size++;
	}
}

void Tabla2::add(string key, int value){
	NodoHash2* n = new NodoHash2();
	n->setKey(key);
	n->setValue(value);
	this->add(n);
	
}

int Tabla2::indexOf(NodoHash2* val){
	for (size_t i = 0; i < this->size; i++)
	{
		NodoHash2* current = getValueAt(i);
		if (current == val)
		{
			return i;
		}
	}
	return -1;
}

NodoHash2* Tabla2::getValueAt(int index){
	NodoHash2* ret = getNodeAt(index);
	return ret;
}

void Tabla2::setValueAt(int index, NodoHash2* val){
	NodoHash2* r = getNodeAt(index);
	r = val;
}

bool Tabla2::isEmpty(){
	return(this->first==nullptr);
}

void Tabla2::removeElementAt(int index){
	if (index>=0 && index<this->size)
	{
		NodoHash2* del = nullptr;
		if (index>0)
		{
			NodoHash2* ret = getNodeAt(index - 1);
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

void Tabla2::insertElementAt(unsigned int index, NodoHash2* nuevo){
	if (index >= 0){
		if (nuevo)
		{
			NodoHash2* pos = getNodeAt(index);
			if (pos){
				NodoHash2* ant = pos->getBefore();
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

unsigned int Tabla2::getSize(){
	return(this->size);
}

void Tabla2::clear(){
	if (!isEmpty() && this->size>0)
	{
		removeElementAt(0);
		clear();
	}
}

Tabla2::~Tabla2(){
	clear();
}
