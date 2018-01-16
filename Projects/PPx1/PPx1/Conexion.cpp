#include "Conexion.h"


Conexion::Conexion()
{
}

/*obtiene la conexion a la BD*/
MySqlConnection^ Conexion::getConexion(){
	MySql::Data::MySqlClient::MySqlConnectionStringBuilder^ s = gcnew MySqlConnectionStringBuilder();
	s->Database = this->db;
	s->Server = this->host;
	s->Port = this->port;
	s->Password = this->pass;
	s->UserID = this->user;
	MySqlConnection^ conn = gcnew MySqlConnection(s->ConnectionString);
	return conn;
}