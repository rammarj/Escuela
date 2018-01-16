#include "stdafx.h"
#include "Persona.h"


Persona::Persona()
{
	this->nombre = "";
	this->telefono = "";
}

void Persona::setNombre(string nombre){
	this->nombre = nombre;
}

void Persona::setTelefono(string telefono){
	this->telefono = telefono;
}

string Persona::getNombre(){
	return(this->nombre);
}

string Persona::getTelefono(){
	return(this->telefono);
}

void Persona::setEdad(int edad){
	this->edad = edad;
}

void Persona::setApPaterno(string ap_paterno){
	this->ap_paterno = ap_paterno;
}

void Persona::setApMaterno(string ap_materno){
	this->ap_materno = ap_materno;
}

string Persona::getApPaterno(){
	return(this->ap_paterno);
}

string Persona::getApMaterno(){
	return(this->ap_materno);
}

int Persona::getEdad(){
	return(this->edad);
}

Persona::~Persona(){}
