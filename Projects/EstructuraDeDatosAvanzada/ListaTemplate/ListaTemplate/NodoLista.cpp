#include "stdafx.h"
#include "NodoLista.h"
template <class tipo>
Nodo<tipo>::Nodo()
{
	this->value = 0;
	this->next = nullptr;
	this->after = nullptr;
}
template <class tipo>
void Nodo<tipo>::setNext(Nodo<tipo>* next){
	this->next = next;
}
template <class tipo>
Nodo<tipo>* Nodo<tipo>::getNext(){
	return(this->next);
}
template <class tipo>
void Nodo<tipo>::setAfter(Nodo<tipo>* after){
	this->after = after;
}
template <class tipo>
Nodo<tipo>* Nodo<tipo>::getAfter(){
	return(this->after);
}
template <class tipo>
void Nodo<tipo>::setData(tipo value){
	this->value = value;
}
template <class tipo>
tipo Nodo<tipo>::getData(){
	return(this->value);
}
template <class tipo>
Nodo<tipo>::~Nodo(){}
