
using namespace MySql::Data::MySqlClient;
using namespace System;
using namespace System::Windows::Forms;

class Conexion
{

public:

	MySqlDataReader^ getReader(String^ sql){
		String^ conectar = L"datasource=localhost;port=3306;username=root;password=i0sec";
		MySqlConnection^ conn = (gcnew MySqlConnection(conectar));
		MySqlCommand^ cmd = (gcnew MySqlCommand(sql, conn));
		MySqlDataReader^ reader;
		try{
			conn->Open();
			reader = cmd->ExecuteReader();
		}
		catch (Exception^ ex){
			delete conectar;
			delete conn;
			delete cmd;
			conn->Close();
		}
		return reader;
	}

	/*void execute(String^ sql){
		String^ conectar = L"datasource=localhost;port=3306;username=root;password=i0sec";
		MySqlConnection^ conn = (gcnew MySqlConnection(conectar));
		MySqlCommand^ cmd = (gcnew MySqlCommand(sql, conn));
		//MySqlDataReader^ reader;
		try{
			conn->Open();
			cmd->ExecuteNonQuery();
		}
		catch (Exception^ ex){
			delete conectar;
			delete conn;
			delete cmd;
			conn->Close();
		}
		//return reader;
	}*/

};
