#pragma once
#ifndef _UTIL_H_
#define _UTIL_H_

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace MySql::Data::MySqlClient;

ref class Util
{
public:
	static void mostrarError(String^ error);
	static void rellenarDatagrid(DataGridView^ dt, ArrayList^ cols, MySqlDataReader^ res);
};

#endif