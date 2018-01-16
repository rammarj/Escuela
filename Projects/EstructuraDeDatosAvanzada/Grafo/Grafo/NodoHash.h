#ifndef _NODO_HASH_H_
#define _NODO_HASH_H_

#include<string.h>
#include<winstring.h>
#include<iostream>
using namespace std;
/**
* Todos los nodos que tiene la lista se crean desde esta clase.
* @author: Joaquin R. Martinez
*/
class NodoHash
{
private:
	/**
	* NodoHash siguiente
	*/
	NodoHash* next;
	/**
	* NodoHash anterior
	*/
	NodoHash* before;
	/**
	* Valor que guarda el nodo
	*/
	string key;
	string value;
	

public:
	/**
	* Crea un nuevo nodo
	*/
	NodoHash();
	/**
	* Establece el apuntador al siguiente nodo.
	*/
	void setNext(NodoHash* next);
	/**
	* Establece el valor que guardará el nodo.
	*/
	void setKey(string key);
	void setValue(string value);
	/**
	* Obtiene el nodo siguiente establecido.
	*/
	NodoHash* getNext();
	/**
	* Obtiene el dato que guarda el nodo.
	*/
	string getKey();
	string getValue();
	/**
	* Establece el nodo anterior a este nodo.
	*/
	void setBefore(NodoHash* before);
	/**
	* Obtiene el nodo anterior establecido.
	*/
	NodoHash* getBefore();
	static NodoHash* load(string data);
	~NodoHash();

};

#endif