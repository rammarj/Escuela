#ifndef _ESTADO_H_
#define _ESTADO_H_

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Estado
{
private:
	string trans[3];

public:
	Estado();
	void setEstado(string estado);
	void setTransicion(string transicion);
	void setSimbolo(string simbolo);
	string getEstado();
	string getTransicion();
	string getSimbolo();
	~Estado();
	bool operator==(const Estado&e){
		return (this->trans[0] == e.trans[0] && this->trans[1] == e.trans[1] && this->trans[2] == e.trans[2]);
	}
};

#endif