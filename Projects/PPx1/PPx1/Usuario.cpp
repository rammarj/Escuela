#include "Usuario.h"


Usuario::Usuario()
{
	Conexion^ con = gcnew Conexion();
	this->conexion_bd = con->getConexion();
}
Usuario^ Usuario::todos(){
	return nullptr;
}
