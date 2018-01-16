#ifndef _TRANSICION_H_
#define _TRANSICION_H_

#include "Lista.cpp"
#include "Estado.h"
#include "Par.h"

class Transicion
{
private:
	Lista<Estado>* estados;
	Lista<string>* termina, *simbolos_no_terminales;
	Lista<Estado>* estados_gramatica;
	string empieza;

public:
	Transicion();
	void addTransicion(Estado es);
	void addTransicion(string estado, string simbolo, string transicion);
	Lista<Estado>* getEstados();
	string getEmpieza();
	Lista<string>* getTermina();
	string existeTransicion(string estado, string simbolo);
	void setEmpieza(string empieza);
	void setTermina(Lista<string>* termina);
	Lista<string>* getNombreEstados();
	Lista<string>* getSimbolos();
	bool estadoInicialConArco();
	Lista<Estado>* getEstadosGramatica();
	Lista<string>* getSimbolosNoTerminales();
	~Transicion();
};

#endif

