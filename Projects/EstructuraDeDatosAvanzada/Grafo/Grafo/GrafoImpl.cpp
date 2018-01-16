#include "stdafx.h"
#include "GrafoImpl.h"


GrafoImpl::GrafoImpl()
{
	this->nodos = new Lista();
	this->identificador = "";
	this->relaciones = new Tabla();
	this->adyacencias = new Tabla();
	this->vecinos = new Tabla2();
	this->direccion = false;

	this->v = new Tabla();
}

void GrafoImpl::addNodo(string s){
	if (this->nodos->indexOf(s) == -1)
	{
		this->nodos->add(s);
	}
}

void GrafoImpl::addRelacion(string a, string b){
	if (this->nodos->indexOf(a) != -1 && this->nodos->indexOf(b) != -1) //comprobar si existen los nodos
	{
		NodoHash* d = new NodoHash();
		d->setKey(a);
		d->setValue(b);
		if (this->relaciones->indexOf(d) == -1)
		{
			this->relaciones->add(d);
		}
		else
		{
			delete d;
		}
	}
}

void GrafoImpl::setIdentificador(string id){
	this->identificador = id;
}

string GrafoImpl::getIdentificador(){
	return(this->identificador);
}

Lista* GrafoImpl::getNodos(){
	return(this->nodos);
}

Tabla* GrafoImpl::getRelaciones(){
	return(this->relaciones);
}

string GrafoImpl::getNodosSerializada(){
	string a = "{"; 
	size_t lim = this->nodos->getSize();
	for (size_t i = 0; i < lim; i++)
	{
		a.append(this->nodos->getValueAt(i));
		if (i+1 != lim)
		{
			a.append(", ");
		}
	}
	a.append("}");
	return a;
}

string GrafoImpl::getRelacionesSerializada(){
	string a = "{";
	size_t lim = this->relaciones->getSize();
	for (size_t i = 0; i < lim; i++)
	{
		NodoHash* n = this->relaciones->getValueAt(i);
		a.append("(");
		a.append(n->getKey());
		a.append(", ");
		a.append(n->getValue());
		a.append(")");
		if ((i+1)!=lim)
		{
			a.append(", ");
		}
	}
	a.append("}");
	return a;
}

void GrafoImpl::usarDireccion(bool direccion){
	this->direccion = direccion;
}

bool GrafoImpl::usaDireccion(){
	return this->direccion;
}

Tabla* GrafoImpl::getAdyacencias(){
	string aux = "";
	this->adyacencias->clear();
	this->v->clear();
	//getVecinos();
	//lenado de puntos de inicio
	size_t tam = this->nodos->getSize();
	for (size_t i = 0; i < tam; i++)
		this->adyacencias->add(this->nodos->getValueAt(i), "");
	

	for (size_t i = 0; i < this->relaciones->getSize(); i++)
	{
		NodoHash* a = this->relaciones->getValueAt(i);
		NodoHash* b = new NodoHash();
		b->setKey(a->getValue());
		b->setValue(a->getKey());
		if (this->v->indexOf(b) == -1)
		{
			this->v->add(a);
		}
		delete b;
	}
	cout << "dsd=" << this->v->getSize();
	//lenado de adyacencias (direccion y sin direccion)
	if (this->usaDireccion())
	{
		for (size_t i = 0; i < tam; i++)
		{
			aux = "";
			NodoHash* a = this->adyacencias->getValueAt(i);
			for (size_t j = 0; j < this->relaciones->getSize(); j++)
			{
				NodoHash* b = this->relaciones->getValueAt(j);
				if (a->getKey() == b->getKey())
				{
					aux.append(b->getValue());
					if ((j + 1) != this->relaciones->getSize())
					{
						aux.append(" ");
					}
				}

			}
			this->adyacencias->set(a->getKey(), aux);
		}
	}
	else
	{
		for (size_t i = 0; i < this->v->getSize(); i++)
		{
			NodoHash* nodo = this->v->getValueAt(i);
			NodoHash* nodo_adyacente = this->adyacencias->get(nodo->getKey());
			this->adyacencias->set(nodo_adyacente->getKey(), nodo->getValue());
			this->adyacencias->set(nodo_adyacente->getValue(), nodo->getKey());
		}
	}
	return this->adyacencias;
}

string GrafoImpl::getGrafo(){
	string a = "";
	a.append(this->getIdentificador());
	a.append("=");
	a.append(this->getRelacionesSerializada());
	return a;
}

Tabla2* GrafoImpl::getVecinos(){
	int tam = 0;
	NodoHash* b = new NodoHash();
	NodoHash* a;
	//this->vecinos->clear();
	//this->v->clear();
	
	//lenado de datos
	for (int j = 0; j < this->nodos->getSize(); j++)
		this->vecinos->add(this->nodos->getValueAt(j), 0);
	
	//limpiando posibles vecinos repetidos
	for (size_t i = 0; i < this->relaciones->getSize(); i++)
	{
		a = this->relaciones->getValueAt(i);
		b->setKey(a->getValue());
		b->setValue(a->getKey());

		if (a->getKey() != a->getValue() )
		{
		cout << a->getKey() << ", " << a->getValue();
			this->v->add(a);
		}

	}
	/* //obteniendo num de vecinos
	for (size_t i = 0; i < this->v->getSize(); i++)
	{
		NodoHash* n = this->v->getValueAt(i);
		NodoHash2* o = this->vecinos->get(n->getKey());
		NodoHash2* p = this->vecinos->get(n->getValue());
		this->vecinos->set(o->getKey(), o->getValue() + 1);
		this->vecinos->set(p->getKey(), p->getValue() + 1);
	}*/
	delete b; 
	return this->vecinos;
	
}

GrafoImpl::~GrafoImpl()
{
	delete this->nodos;
	delete this->relaciones;
}
