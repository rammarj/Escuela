#include "stdafx.h"
#include "Contacto.h"


Contacto::Contacto()
{
	this->nombre = "";
	this->telefono = "";
}

void Contacto::setNombre(string nombre){
	this->nombre = nombre;
}

void Contacto::setTelefono(string telefono){
	this->telefono = telefono;
}

string Contacto::getNombre(){
	return(this->nombre);
}

string Contacto::getTelefono(){
	return(this->telefono);
}

void Contacto::setEdad(int edad){
	this->edad = edad;
}

void Contacto::setApPaterno(string ap_paterno){
	this->ap_paterno = ap_paterno;
}

void Contacto::setApMaterno(string ap_materno){
	this->ap_materno = ap_materno;
}

string Contacto::getApPaterno(){
	return(this->ap_paterno);
}

string Contacto::getApMaterno(){
	return(this->ap_materno);
}

int Contacto::getEdad(){
	return(this->edad);
}

Contacto::~Contacto(){}
