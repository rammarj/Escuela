#ifndef _CONEXION_H_
#define _CONEXION_H_

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

/*Clase para conexion con gestor de base de datos MySQL*/
ref class Conexion
{
private:
	/*host de la base de datos (default localhost/127.0.0.1)*/
	String^ host = "192.168.43.10";
		 /*Usuario de la base de datos (default superusuario 'root')*/
	String^ user = "tienda";
		 /*Contraseña del usuario de la base de datos (default sin contraseña por defecto de MySQL)*/
	String^ pass = "tienda";
		 /*nombre de la base de datos a utilizar*/
	String^ db = "tienda";
		 /*puerto de conexion de la BD (default 3306)*/
	int port = 3306;
		 /*conexion MySQL*/
	MySqlConnection^ conn;

public:
	Conexion();
	MySqlConnection^ getConexion();
};

#endif