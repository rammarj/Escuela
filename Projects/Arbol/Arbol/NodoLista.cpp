#include "stdafx.h"
#include "NodoLista.h"

template <class tipo>
NodoLista<tipo>::NodoLista()
{
	this->value = 0;
	this->next = nullptr;
	this->after = nullptr;
}
template <class tipo>
void NodoLista<tipo>::setNext(NodoLista<tipo>* next){
	this->next = next;
}
template <class tipo>
NodoLista<tipo>* NodoLista<tipo>::getNext(){
	return(this->next);
}
template <class tipo>
void NodoLista<tipo>::setAfter(NodoLista<tipo>* after){
	this->after = after;
}
template <class tipo>
NodoLista<tipo>* NodoLista<tipo>::getAfter(){
	return(this->after);
}
template <class tipo>
void NodoLista<tipo>::setData(tipo value){
	this->value = value;
}
template <class tipo>
tipo NodoLista<tipo>::getData(){
	return(this->value);
}
template <class tipo>
NodoLista<tipo>::~NodoLista(){
	
}
