#include "stdafx.h"
#include "Estado.h"


Estado::Estado()
{
}

string Estado::getEstado(){
	return this->trans[0];
}

string Estado::getSimbolo(){
	return this->trans[1];
}

string Estado::getTransicion(){
	return this->trans[2];
}

void Estado::setEstado(string estado){
	this->trans[0] = estado;
}

void Estado::setSimbolo(string simbolo){
	this->trans[1] = simbolo;
}

void Estado::setTransicion(string transicion){
	this->trans[2] = transicion;
}

Estado::~Estado()
{
}
