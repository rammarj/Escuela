#ifndef _GRAFO_IMPL_H_
#define _GRAFO_IMPL_H_

#include "Lista.h"
#include "Tabla.h"
#include "Tabla2.h"

class GrafoImpl
{
private:
	Lista *nodos;
	string identificador;
	Tabla *relaciones, *adyacencias;
	Tabla2  *vecinos;
	bool direccion;
	Tabla* v;

public:
	GrafoImpl();
	void addNodo(string s);
	void addRelacion(string a, string b);
	void setIdentificador(string s);
	void usarDireccion(bool direccion);
	bool usaDireccion();
	string getIdentificador();
	Lista *getNodos();
	Tabla *getRelaciones();
	string getRelacionesSerializada();
	string getNodosSerializada();
	Tabla *getAdyacencias();	
	Tabla2 *getVecinos();
	string getGrafo();
	~GrafoImpl();
};

#endif