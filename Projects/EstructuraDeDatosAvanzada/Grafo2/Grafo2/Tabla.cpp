#include "stdafx.h"
#include "Tabla.h"

Tabla::Tabla()
{
	this->first = nullptr;
	this->size = 0;
	this->aux = nullptr;
}

NodoHash* Tabla::get(string key){
	for (int i = 0; i < this->getSize(); i++)
	{
		NodoHash* n = getNodeAt(i);
		if (n->getKey()==key)
		{
			return n;
		}
	}
	return nullptr;
}

void Tabla::set(string key, string value){
	NodoHash* n = this->get(key);
	if (n!=nullptr)
	{
		n->setValue(value);
	}
}

NodoHash* Tabla::getLast(NodoHash* n){
	if (n != nullptr){
		this->aux = n->getNext();
		if (aux)
		{
			return getLast(this->aux);
		}
		else{
			return n;
		}
	}
	else{
		return nullptr;
	}
}

NodoHash* Tabla::getNodeAt(int index){
	NodoHash* ret = this->first;
	if (index >= 0 && index<this->size)
	{
		for (size_t i = 0; i < index; i++)
		{
			ret = ret->getNext();
		}
	}
	return ret;
}

void Tabla::add(NodoHash* nuevo){
	if (nuevo){
		if (this->size == 0)
		{
			this->first = nuevo;
		}
		else{
			NodoHash* last = nullptr;
			last = getLast(this->first);
			last->setNext(nuevo);
			nuevo->setBefore(last);
		}
		this->size++;
	}
}

void Tabla::add(string key, string value){
	NodoHash* n = new NodoHash();
	n->setKey(key);
	n->setValue(value);
	add(n);
}

int Tabla::indexOf(NodoHash* val){
	for (size_t i = 0; i < this->size; i++)
	{
		NodoHash* current = this->getValueAt(i);
		if (current->getKey() == val->getKey() && current->getValue()==val->getValue())
		{
			return i;
		}
	}
	return -1;
}

NodoHash* Tabla::getValueAt(int index){
	NodoHash* ret = this->getNodeAt(index);
	return ret;
}

void Tabla::setValueAt(int index, NodoHash* val){
	NodoHash* r = getNodeAt(index);
	r = val;
}

bool Tabla::isEmpty(){
	return(this->first==nullptr);
}

void Tabla::removeElementAt(int index){
	if (index>=0 && index<this->size)
	{
		NodoHash* del = nullptr;
		if (index>0)
		{
			NodoHash* ret = getNodeAt(index - 1);
			del = ret->getNext();
			if (del->getNext())
			{
				ret->setNext(del->getNext());
				del->getNext()->setBefore(ret);
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

void Tabla::insertElementAt(unsigned int index, NodoHash* nuevo){
	if (index >= 0){
		if (nuevo)
		{
			NodoHash* pos = getNodeAt(index);
			if (pos){
				NodoHash* ant = pos->getBefore();
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

unsigned int Tabla::getSize(){
	return(this->size);
}

void Tabla::clear(){
	if (!isEmpty() && this->size>0)
	{
		removeElementAt(0);
		clear();
	}
}

Tabla::~Tabla(){
	clear();
}
