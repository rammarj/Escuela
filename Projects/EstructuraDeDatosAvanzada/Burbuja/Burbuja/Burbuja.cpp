// Burbuja.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Lista.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Lista *l = new Lista();
	l->add(8);
	l->add(7);
	l->add(3);
	l->add(22);
	l->add(43);
	l->add(2);
	l->add(46);
	l->add(80);
	cout << "\n\nvalores antes de ser ordenados:\n";
	for (size_t i = 0; i < l->getSize(); i++)
	{
		cout << l->getValueAt(i) << endl;
	}
	cin.get();
	l->sort_seleccion_directa();
	cout << "\n\nvalores despues de ser ordenados:\n";
	for (size_t i = 0; i < l->getSize(); i++)
	{
		cout << l->getValueAt(i) << endl;
	}
	cin.get();
	return 0;
}

