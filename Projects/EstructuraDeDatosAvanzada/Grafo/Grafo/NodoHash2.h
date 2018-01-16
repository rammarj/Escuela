#ifndef _NODO_HASH_2_H_
#define _NODO_HASH_2_H_

#include<string.h>
#include<winstring.h>
#include<iostream>
using namespace std;
/**
* Todos los nodos que tiene la lista se crean desde esta clase.
* @author: Joaquin R. Martinez
*/
class NodoHash2
{
private:
	/**
	* NodoHash2 siguiente
	*/
	NodoHash2* next;
	/**
	* NodoHash2 anterior
	*/
	NodoHash2* before;
	/**
	* Valor que guarda el nodo
	*/
	string key;
	int value;
	

public:
	/**
	* Crea un nuevo nodo
	*/
	NodoHash2();
	/**
	* Establece el apuntador al siguiente nodo.
	*/
	void setNext(NodoHash2* next);
	/**
	* Establece el valor que guardará el nodo.
	*/
	void setKey(string key);
	void setValue(int value);
	/**
	* Obtiene el nodo siguiente establecido.
	*/
	NodoHash2* getNext();
	/**
	* Obtiene el dato que guarda el nodo.
	*/
	string getKey();
	int getValue();
	/**
	* Establece el nodo anterior a este nodo.
	*/
	void setBefore(NodoHash2* before);
	/**
	* Obtiene el nodo anterior establecido.
	*/
	NodoHash2* getBefore();
	static NodoHash2* load(string data);
	~NodoHash2();

	bool operator==(const NodoHash2&n){
		return(this->key == n.key && this->value == n.value);
	}
};

#endif