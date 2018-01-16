#pragma once
#include <string>
#include<iostream>
#include"Lista.cpp"
#include"NodoHash.h"
using namespace std;
class TablaHash
{
private:
	char letras[28];
	long double getHash(string);
	int getCodigo(char);
	Lista<NodoHash> lista;

public:
	TablaHash();
	Lista<NodoHash> getListaHash();
	void agregar(string);
	~TablaHash();
	void ordenar();
	int getPalabraLarga(Lista<string>);
	string rellenar_cadena(string s, int num_letras);
};

