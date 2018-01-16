#ifndef _NODO_HASH_H_
#define _NODO_HASH_H_

#include <string>
#include <iostream>

using namespace std;

class NodoHash
{
private:
	long double clave;
	string valor;

public:
	NodoHash();
	long double getClave();
	string getValor();
	void setClave(long double);
	void setValor(string);
	~NodoHash();
	void operator=(const NodoHash &h){
		this->clave = h.clave;
		this->valor = h.valor;
	}
	bool operator>(const NodoHash &h){
		return(this->clave>h.clave);
	}
	bool operator<(const NodoHash &h){
		return(this->clave<h.clave);
	}

};

#endif