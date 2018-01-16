#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
	string nombre;
	string ap_paterno;
	string ap_materno;
	int edad;
	string telefono;
public:
	Persona();
	void setNombre(string nombre);
	void setTelefono(string telefono);
	void setEdad(int);
	void setApPaterno(string);
	void setApMaterno(string);
	string getNombre();
	string getTelefono();
	string getApPaterno();
	string getApMaterno();
	int getEdad();
	~Persona();
	bool operator==(const Persona &c){
		return(this->telefono == c.telefono && this->nombre == c.nombre && this->edad == c.edad 
			&& this->ap_paterno == c.ap_paterno && this->ap_materno == c.ap_materno);
	}
	void operator=(const Persona &c){
		this->nombre = c.nombre;
		this->ap_paterno = c.ap_paterno;
		this->ap_materno = c.ap_materno;
		this->edad = c.edad;
		this->telefono = c.telefono;
	}
};

