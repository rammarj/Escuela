#ifndef _CONEXION_H_
#define _CONEXION_H_

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace PPx1{

	/*Clase para conexion con gestor de base de datos MySQL*/
	public ref class Conexion{
	/*host de la base de datos (default localhost/127.0.0.1)*/
	private: String^ host;
	/*Usuario de la base de datos (default superusuario 'root')*/
	private: String^ user;
	/*Contraseña del usuario de la base de datos (default sin contraseña por defecto de MySQL)*/
	private: String^ pass;
	/*nombre de la base de datos a utilizar*/
	private: String^ db;
	/*puerto de conexion de la BD (default 3306)*/
	private: int port;
	/*conexion MySQL*/
	private: MySqlConnection^ conn;

	public:
		Conexion(){
			this->host = L"localhost";
			this->user = L"root";
			this->pass = L"";
			this->db = L"multmedia_px1_electronica";
			this->port = 3306;
		}
		/*obtiene la conexion a la BD*/
		public: MySqlConnection^ getConexion(){
			MySql::Data::MySqlClient::MySqlConnectionStringBuilder^ s = gcnew MySqlConnectionStringBuilder();
			s->Database = this->db;
			s->Server = this->host;
			s->Port = this->port;
			s->Password = this->pass;
			s->UserID = this->user;
			MySqlConnection^ conn = gcnew MySqlConnection(s->ConnectionString);
			return conn;
		}

	};

}
#endif