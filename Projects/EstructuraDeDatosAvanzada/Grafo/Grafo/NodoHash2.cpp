#include "stdafx.h"
#include "NodoHash2.h"


NodoHash2::NodoHash2()
{
	this->value = 0;
	this->key = "";
	this->next = nullptr;
	this->before = nullptr;
}

void NodoHash2::setNext(NodoHash2* next){
	this->next = next;
}

NodoHash2* NodoHash2::getNext(){
	return(this->next);
}

void NodoHash2::setBefore(NodoHash2* before){
	this->before = before;
}

NodoHash2* NodoHash2::getBefore(){
	return(this->before);
}

void NodoHash2::setKey(string key){
	this->key = key;
}

void NodoHash2::setValue(int value){
	this->value = value;
}

string NodoHash2::getKey(){
	return(this->key);
}

int NodoHash2::getValue(){
	return(this->value);
}

static NodoHash2* load(string data){
	NodoHash2* n = new NodoHash2();

}

NodoHash2::~NodoHash2(){}
