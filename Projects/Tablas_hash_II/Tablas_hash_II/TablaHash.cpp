#include "stdafx.h"
#include "TablaHash.h"
//constructor
TablaHash::TablaHash(){}
//privado para operaciones internas
void TablaHash::add(long double clave, string valor){
	NodoHash hash;
	hash.setClave(clave);
	hash.setValor(valor);
	this->lista.agregar(hash);
}
//publico para utilizar en el main porque no se necesita la clave solo el valor (las palabras)
void TablaHash::add( string valor){
	this->add(0,valor);
}
//obtiene la lista que se está usando actualmente
Lista<NodoHash> TablaHash::getLista(){
	return this->lista;
}
//divide el string en una lista bansandose en los espacios
Lista<string> TablaHash::dividir(string s){
	Lista<string> divisiones;
	string aux = "";
	for (unsigned int i = 0; i < s.length(); i++)
	{
		char a = s[i];
		if (a == ' ' || (i+1)==s.length())
		{
			aux = aux + a;
			divisiones.agregar(aux);
			aux = "";
		}
		else{
			aux = aux+a;
		}
	}
	return divisiones;
}
//obtiene la palabra mas larga en la lista como parametro
int TablaHash::getPalabraLarga(Lista<string> l){
	int largo = 0,aux=0;
	for ( int i = 0; i < l.getTamano(); i++)
	{
		aux=l.mostrar(i).length();
		if (aux>largo)
		{
			largo = aux;
		}
	}
	return largo;
}
//obtiene la oracion con la mayor cantidad de palabras (serán las columnas de la simulacion de tabla)
int TablaHash::getNumeroPalabras(){
	Lista<NodoHash> list = this->getLista();
	string oracion = "";
	int num_palabras = 0, num_palabras_mayor=0;
	for ( int i = 0; i < list.getTamano(); i++)
	{
		oracion = list.mostrar(i).getValor();
		num_palabras = dividir(oracion).getTamano();
		if (num_palabras_mayor<num_palabras)
		{
			num_palabras_mayor = num_palabras;
		}
	}
	return num_palabras_mayor;
}
//normalizar la tabla palabras convirtiendolo en una especie de tabla con columnas (numero max. de palabras)
// y con renglones (numero de registros) para que se facilite el manejo de rellenado de espacios faltantes
Lista<Lista<string>> TablaHash::getNormalizado(){
	Lista<NodoHash> list = this->getLista();
	Lista<Lista<string>> normal, aux_norm, aux_norm_2;
	Lista<string> palabras, aux_pal;
	string oracion = "", aux="";
	int num_palabras = this->getNumeroPalabras(), palabra_larga = 0;
	for ( int i = 0; i < list.getTamano(); i++) //obtener las listas
	{
		oracion = list.mostrar(i).getValor();
		palabras = this->dividir(oracion);//crear una lista con todas las palabras de la oracion
		palabras = this->rellenar(palabras, num_palabras);
		normal.agregar(palabras);
	}
	for ( int i = 0; i < this->getLista().getTamano(); i++)
	{
		aux_norm.agregar(this->getRenglon(normal,i));
	}
	//la falla
	for (int i = 0; i < aux_norm.getTamano(); i++)
	{
		palabras = aux_norm.mostrar(i);
		palabra_larga = this->getPalabraLarga(palabras); //obtener la palabra mas larga qu hay en la primera columna
		for (int j = 0; j < palabras.getTamano(); j++)
		{
			aux = this->rellenarString(palabras.mostrar(j), palabra_larga); //rellenado el string al tamaño de la cadena más larga
			palabras.reemplazar(j, aux);//actualizar el tamaño de cada palabra rellenado con espacios			
		}
		aux_norm_2.agregar(palabras);
	}
	return aux_norm_2;
}
//rellena el string con espacios hasta que alcance el numero de letras especificado
string TablaHash::rellenarString(string s, int num_letras){
	 int faltantes = num_letras - s.length();
	if (s.length()<num_letras)
	{
		for ( int i = 0; i < faltantes; i++)
		{
			s.append(" ");
		}
	}
	return s;
}
//rellena la lista especificada hasta que cumpla con el numero de datos especificado
Lista<string> TablaHash::rellenar(Lista<string> l, int n_datos){
	int faltantes = 0;
	if (l.getTamano()<n_datos)
	{
		faltantes = n_datos - l.getTamano();
		for (int i = 0; i < faltantes; i++)
		{
			l.agregar("");
		}
	}
	return l;
}
//calcula el hash del string especificado
long double TablaHash::calcularHash(string s){
	int pos = 0, num_letras;
	Letra letra;
	long double hash = 0.0, acum=0.0;
	num_letras = letra.getNumeroLetras();
	for (int i = s.length(); i >=0; i--, pos++)
	{
		letra = Letra(s[i]);
		hash = pow(num_letras,pos)*letra.getNumeroLetra();
		acum += hash;
	}
	return acum;
}
//obtiene la tabla hash con los hashes ya de los strings y ademas lo retorna ordenado
TablaHash TablaHash::obtenercalculadoTablaHash(){
	TablaHash calculados;
	Lista<Lista<string>> normalizado = this->getNormalizado();
	Lista<string> aux;
	Lista<NodoHash> ret;
	long double hash = 0.0;
	string renglon = "";
	int renglones = this->getLista().getTamano();
	for ( int i = 0; i < normalizado.getTamano(); i++) //obtener las oraciones ya normalizadas
	{
		renglon = this->getRenglonConcatenado(normalizado,i);
		hash = this->calcularHash(renglon);
		calculados.add(hash, this->getLista().mostrar(i).getValor()); //la tabla con las claves precalculadas
	}
	ret = calculados.getLista();
	ret.quick_sort();
	calculados.setLista(ret);
	return calculados;
}
//obtiene el "renglon" especificado concatenado para una lista que está estructurada como una tabla(todas las 
//listas interiores tienen la misma cantidad de elementos)
string TablaHash::getRenglonConcatenado(Lista<Lista<string>> normalizado, int renglon){
	Lista<string> aux;
	string temp = "";
	int columnas = this->getNumeroPalabras();
	for ( int i = 0; i < columnas; i++)
	{
		aux = normalizado.mostrar(i);//esta es la columna
		temp.append(aux.mostrar(renglon)); //concatenar el valor para despues retornarlo
	}
	return temp;
}
//igual que el anterior pero retorna la lista no concatenada
Lista<string> TablaHash::getRenglon(Lista<Lista<string>> normalizado, int r){
	Lista<string> aux, ret;
	for ( int i = 0; i < this->getLista().getTamano(); i++)
	{
		aux = normalizado.mostrar(i);
		ret.agregar(aux.mostrar(r));
	}
	return ret;
}
//destructor que no hace nada porque no se utilizaron punteros
TablaHash::~TablaHash(){ }
//reemplaza la lista usada actualmente para guardar las cadenas por una lista nueva
void TablaHash::setLista(Lista<NodoHash> nuevo){
	this->lista = nuevo;
}
//reemplaza un string en la tabla hash que está en la posicion dada.
void TablaHash::reemplazar(unsigned int pos, string rem){
	NodoHash n;
	n.setValor(rem);
	this->lista.reemplazar(pos,n);
}
