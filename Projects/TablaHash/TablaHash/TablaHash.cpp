// TablaHash.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "TablaHash.h"

TablaHash::TablaHash(){//las letras
	letras[0] = ' ';
	letras[1] = 'a';
	letras[2] = 'b';
	letras[3] = 'c'; 
	letras[4] = 'd'; 
	letras[5] = 'e';
	letras[6] = 'f';
	letras[7] = 'g';
	letras[8] = 'h';
	letras[9] = 'i';
	letras[10] = 'j';
	letras[11] = 'k';
	letras[12] = 'l';
	letras[13] = 'm';
	letras[14] = 'n';
	letras[15] = 'o';
	letras[16] = 'p';
	letras[17] = 'p';
	letras[18] = 'q';
	letras[19] = 'r';
	letras[20] = 's';
	letras[21] = 't';
	letras[22] = 'u';
	letras[23] = 'v';
	letras[24] = 'w';
	letras[25] = 'x';
	letras[26] = 'y';
	letras[27] = 'z';
}

TablaHash::~TablaHash(){}
//obtiene el codigo de la letra
int TablaHash::getCodigo(char c){
	for (int i = 0; i < 28; i++)
	{
		if (c == this->letras[i])
		{
			return i;
		}
	}
	return 0;
}
//obtiene el hash de la palabra s
long double TablaHash::getHash(string s){
	long double codigo, acum = 0;
	int pos = 0;
	for (int i = s.length(); i >= 0; i--,pos++)
	{
		codigo = pow(28, pos)*this->getCodigo(s[i]);//operacion para el codigo hash
		acum += codigo; //suma los valores obtenidos 
	}
	return acum; //retornar el hash
}

void TablaHash::agregar(string s){
	NodoHash h;
	h.setClave(0);
	h.setValor(s);
	this->lista.agregar(h);
}
//ordena conforme el hash de las palabras
void TablaHash::ordenar(){
	Lista<string> datos, aux;
	NodoHash h;
	Lista<NodoHash> retorna; //es 
	int mas_larga;
	//obtener la lista de cadenas que hay
	for (int i = 0; i < this->lista.getTamano(); i++)
	{
		h = this->lista.mostrar(i);
		datos.agregar(h.getValor());//agrega a la lista los valores (cadenas que introdujo el usuario)
	}
	mas_larga = this->getPalabraLarga(datos);//obtener la cadena mas larga que hay en la lista
	//rellenar cadenas con espacios
	for (int i = 0; i < datos.getTamano(); i++)
	{
		aux.agregar(this->rellenar_cadena(datos.mostrar(i),mas_larga)); //agrega a la lista auxiliar la cadena con espacios para que
		//todos tengan el mismo tamaño de cadena
	}
	//obtener el hash de cada palabra
	for (int i = 0; i < aux.getTamano(); i++)
	{
		h.setClave(this->getHash(aux.mostrar(i)));//establece la nueva clave ( el hash)
		h.setValor(aux.mostrar(i));//el valor es el mismo que introdujo el usuario
		retorna.agregar(h);//agrega el nodohash a la lista para despues ordenarlo
	}
	retorna.quick_sort(); //aqui ordena con quicksort
	this->lista = retorna;//iguala a la lista actual con la lista ya ordenada
}
//obtiene la palabra mas larga de una lista
int TablaHash::getPalabraLarga(Lista<string> l){
	int largo = 0, aux = 0;
	for (int i = 0; i < l.getTamano(); i++)
	{
		aux = l.mostrar(i).length();
		if (aux>largo)
		{
			largo = aux;
		}
	}
	return largo;
}
//rellena el string con espacios hasta que alcance el numero de letras especificado
string TablaHash::rellenar_cadena(string s, int num_letras){
	int faltantes = num_letras - s.length();
	if (s.length()<num_letras)
	{
		for (int i = 0; i < faltantes; i++)
		{
			s.append(" ");
		}
	}
	return s;
}