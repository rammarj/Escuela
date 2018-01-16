#pragma once
#include "Conexion.h"

ref class Usuario
{
private:
	MySqlConnection^ conexion_bd;
	static String^ sql;

public:
	Usuario();
	static Usuario^ todos();
};

