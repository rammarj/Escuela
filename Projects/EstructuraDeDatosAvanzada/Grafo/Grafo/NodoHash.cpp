#include "stdafx.h"
#include "NodoHash.h"


NodoHash::NodoHash()
{
	this->value = "";
	this->key = "";
	this->next = nullptr;
	this->before = nullptr;
}

void NodoHash::setNext(NodoHash* next){
	this->next = next;
}

NodoHash* NodoHash::getNext(){
	return(this->next);
}

void NodoHash::setBefore(NodoHash* before){
	this->before = before;
}

NodoHash* NodoHash::getBefore(){
	return(this->before);
}

void NodoHash::setKey(string key){
	this->key = key;
}

void NodoHash::setValue(string value){
	this->value = value;
}

string NodoHash::getKey(){
	return(this->key);
}

string NodoHash::getValue(){
	return(this->value);
}

static NodoHash* load(string data){
	NodoHash* n = new NodoHash();

}

NodoHash::~NodoHash(){}
