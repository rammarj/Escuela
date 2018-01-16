#include "stdafx.h"
#include "TablaHash.h"

template<class key, class value>
TablaHash<key, value>::TablaHash()
{
	this->first = NULL;
	this->size = 0;
	this->aux = NULL;
}

template<class key, class value>
Nodo<key,value>* TablaHash<key,value>::getLast(Nodo<key,value>* n){
	if (n != nullptr){
		this->aux = n->siguiente;
		if (aux)
		{
			return getLast(this->aux);
		}
		else{
			return n;
		}
	}
	else{
		return aux;
	}
}

template<class key, class value>
Nodo<key, value>* TablaHash<key, value>::getNodeAt(Nodo<key, value>* inicio, key clave){
	if (inicio != NULL){
		if (*(inicio->clave) == clave)
		{
			return inicio;
		}
		else{
			return this->getNodeAt(inicio->siguiente, clave);
		}
	}
	else{
		return NULL;
	}
}

template<class key, class value>
Nodo<key, value>* TablaHash<key, value>::getNodeAt(Nodo<key, value>* inicio, unsigned int index){
	if (this->size >= index)
	{
		Nodo<key, value>* ret = inicio;
		for (unsigned int i = index - 1; i >= 0; i++)
		{
			ret = inicio->siguiente;
		}
	}
	return NULL;
}

template<class key, class value>
void TablaHash<key, value>::add(key clave, value valor){
	Nodo<key, value>* nuevo = new Nodo<key, value>(clave, valor);
	if (nuevo){
		if (this->size == 0)
		{
			this->first = nuevo;
		}
		else{
			Nodo<key, value>* last = nullptr;
			last = this->getLast(this->first);
			last->siguiente = nuevo;
			nuevo->anterior = last;
		}
		this->size++;
	}
}

template<class key, class value>
value TablaHash<key, value>::getValue(key clave){
	Nodo<key, value>* ret = getNodeAt(this->first, clave);
	return ret->valor;
}

template<class key, class value>
void TablaHash<key, value>::setValueAt(key clave, value valor){
	Nodo<key, value>* nodo = this->getNodeAt(this->first, clave);
	nodo->valor = valor;
}

template<class key, class value>
void TablaHash<key, value>::setValueAt(int index, Nodo<key, value>* reemp){
	Nodo<key, value>* nodo = this->getNodeAt(this->first, index);
	nodo = reemp;
}

template<class key, class value>
bool TablaHash<key, value>::isEmpty(){
	return(this->first==NULL);
}

template<class key, class value>
void TablaHash<key, value>::removeElement(key clave){
	Nodo<key, value>* nodo = this->getNodeAt(this->first, clave), *anterior, *siguiente;
	if (nodo!=NULL)
	{
		anterior = nodo->anterior;
		siguiente = nodo->siguiente;
		anterior->siguiente = siguiente;
		siguiente->anterior = anterior;
		nodo = NULL;
		delete nodo;
		this->size--;
	}
}

template<class key, class value>
unsigned int TablaHash<key, value>::getSize(){
	return(this->size);
}

template<class key, class value>
void TablaHash<key, value>::clear(){
	this->first = NULL;
	delete this->first;
}

template<class key, class value>
int TablaHash<key, value>::pivot(int izq, int der){
	int i;
	int pivote;
	key valor_pivote;
	Nodo<key, value>* aux,*aux2, *aux3;
	pivote = izq;
	aux2 = this->getNodeAt(this->first, pivote);
	valor_pivote = aux2->clave;
	for (i = izq + 1; i <= der; i++){
		aux3 = this->getNodeAt(this->first, i);
		if (aux3->clave  < valor_pivote){
			pivote++;
			aux = this->getNodeAt(this->first, i);
			this->setValueAt(i, this->getNodeAt(this->first, pivote));
			this->setValueAt(pivote, aux);

		}
	}
	aux = this->getNodeAt(this->first, izq);
	this->setValueAt(izq, this->getNodeAt(this->first, pivote));
	this->setValueAt(pivote, aux);
	return pivote;
}

template<class key, class value>
void TablaHash<key, value>::quickSort(int izq, int der){
	int pivote;
	if (izq < der){
		pivote = this->pivot(izq, der);
		this->quickSort(izq, pivote - 1);
		this->quickSort(pivote + 1, der);
	}
}


template<class key, class value>
void TablaHash<key, value>::quick_sort(){
	this->quickSort(0, this->size - 1);
}

template<class key, class value>
TablaHash<key, value>::~TablaHash(){
	this->clear();
}

