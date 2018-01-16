// String.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<string>
#include <iostream>
#include <stdlib.h>
using namespace std;

string replace(string in, string old, string replace){
	int pos = 0;
	pos = in.find(old);
	while (pos!=string::npos)
	{
		in.replace(pos, old.length(), replace);
		pos = in.find(old);
	}
	return in;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int s;
	string a = "joaquinc dds joaquin";
	//string a = "sa ds";
	string b = "joaquin";
	s = b.length() - 1;
		cout << replace(a,b,"");
		for (int i = s; i>=0; i--)
		{
			cout << b[i];
		}
	system("pause>null");
	return 0;
}

