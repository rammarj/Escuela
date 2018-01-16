#pragma once
#include <iostream>
#include <string>

using namespace std;

class Contacto
{
private:
	string nombre;
	string ap_paterno;
	string ap_materno;
	int edad;
	string telefono;
public:
	Contacto();
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

	~Contacto();
	bool operator==(const Contacto &c){
		return(this->telefono == c.telefono && this->nombre == c.nombre && this->edad == c.edad 
			&& this->ap_paterno == c.ap_paterno && this->ap_materno == c.ap_materno);
	}
};

