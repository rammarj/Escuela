#ifndef _TABLA_HASH_H
#define _TABLA_HASH_H

#include "NodoHash.h"
#include "Letra.h"
class TablaHash
{
private:
	Lista<NodoHash> lista;
	Lista<string> dividir(string);
	int getNumeroPalabras();
	int getPalabraLarga(Lista<string>);
	Lista<Lista<string>> getNormalizado();
	Lista<string> rellenar(Lista<string>, int n_datos);
	Lista<string> getRenglon(Lista<Lista<string>> normalizado,int r);
	string getRenglonConcatenado(Lista<Lista<string>> normalizado, int renglon);
	long double calcularHash(string);
	string rellenarString(string, int);
	void add(long double, string);

public:
	TablaHash();
	void add(string);
	Lista<NodoHash> getLista();
	TablaHash obtenercalculadoTablaHash();
	~TablaHash();
	void reemplazar(unsigned int pos, string rem);
	void setLista(Lista<NodoHash>);
};

#endif