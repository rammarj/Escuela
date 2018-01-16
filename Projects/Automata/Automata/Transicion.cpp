#include "stdafx.h"
#include "Transicion.h"

Transicion::Transicion()
{
	this->estados = new Lista<Estado>();
	this->empieza = "";
	this->termina = new Lista<string>();
	this->estados_gramatica = new Lista<Estado>();
	this->simbolos_no_terminales = new Lista<string>();
}

void Transicion::addTransicion(Estado es){
	this->estados->add(es);
}

void Transicion::addTransicion(string estado, string simbolo, string transicion){
	Estado es;
	es.setEstado(estado);
	es.setSimbolo(simbolo);
	es.setTransicion(transicion);
	addTransicion(es);
}

Lista<Estado>* Transicion::getEstados(){
	return this->estados;
}

string Transicion::getEmpieza(){
	return this->empieza;
}

Lista<string>* Transicion::getTermina(){
	return this->termina;
}

string Transicion::existeTransicion(string estado, string simbolo){
	for (size_t i = 0; i < this->estados->getSize(); i++)
	{
		Estado es = this->estados->getValueAt(i);
		if (es.getEstado()==estado && es.getSimbolo() == simbolo)
		{
			return es.getTransicion();
		}
	}
	return "";      
}

void Transicion::setEmpieza(string empieza){
	this->empieza = empieza;
}

void Transicion::setTermina(Lista<string>* termina){
	this->termina = termina;
}

Lista<string>* Transicion::getNombreEstados(){
	Lista<string>* est = new Lista<string>();
	for (size_t i = 0; i < this->estados->getSize(); i++)
	{
		Estado e = this->estados->getValueAt(i);
		if (est->indexOf(e.getEstado()) == -1)
		{
			est->add(e.getEstado());
		}
	}
	return est;
}

Lista<string>* Transicion::getSimbolos(){
	Lista<string>* est = new Lista<string>();
	for (size_t i = 0; i < this->estados->getSize(); i++)
	{
		Estado e = this->estados->getValueAt(i);
		if (est->indexOf(e.getSimbolo()) == -1)
		{
			est->add(e.getSimbolo());
		}
	}
	return est;
}

bool Transicion::estadoInicialConArco(){
	for (size_t i = 0; i < this->estados->getSize(); i++)
	{
		Estado e = this->estados->getValueAt(i);
		if (e.getEstado()==this->empieza&&e.getEstado()==e.getTransicion())
		{
			return true;
		}
	}
	return false;
}

Lista<Estado>* Transicion::getEstadosGramatica(){
	Lista<Par>* l = new Lista<Par>();
	this->estados_gramatica->clear();
	Par p;
	//lenar con no terminales
	if (estadoInicialConArco())
	{
		for (size_t i = 0; i < this->getNombreEstados()->getSize(); i++)
		{
			string es = this->getNombreEstados()->getValueAt(i);
			p.setA(es);
			p.setB(this->getSimbolosNoTerminales()->getValueAt(i));
			l->add(p);
		}
	}
	else{
		//buscar el inicio y asignarle el simbolo distinguido
		for (size_t i = 0,j=0; i < this->getNombreEstados()->getSize(); i++,j++)
		{
			if (this->getEmpieza()==this->getNombreEstados()->getValueAt(i))
			{
				p.setA(this->getEmpieza());
				p.setB("S");
				l->add(p);
				j--;
			}
			else{
				p.setA(this->getNombreEstados()->getValueAt(j));
				p.setB(this->getSimbolosNoTerminales()->getValueAt(j));
			}
		}
	}	
	//ya estan los pares, ahora los usamos para cambiar en estados_gramatica
	for (size_t i = 0; i < this->getEstados()->getSize(); i++)
	{
		Estado e = this->getEstados()->getValueAt(i);
		//hacer cambios al estado actual
		for (size_t j = 0; j < l->getSize(); j++)
		{
			Par par = l->getValueAt(j);
			if (e.getEstado() == p.getA())
			{
				e.setEstado(p.getB());
			}
			if (e.getTransicion() == p.getA())
			{
				e.setTransicion(p.getB());
			}
		}
		//agregar al estado_gramatica con la modificacion
		estados_gramatica->add(e);
	}
	return estados_gramatica;
}

Lista<string>* Transicion::getSimbolosNoTerminales(){
	this->simbolos_no_terminales->clear();
	char c = 'A';
	string b = "";
	b += c;
	for (size_t i = 0; i < this->getNombreEstados()->getSize(); i++)
	{
		this->simbolos_no_terminales->add(b);
		b = "";
		c ++;
		b += c;
	}
	return simbolos_no_terminales;
}

Transicion::~Transicion()
{
	delete this->estados;
	delete this->termina;
}
