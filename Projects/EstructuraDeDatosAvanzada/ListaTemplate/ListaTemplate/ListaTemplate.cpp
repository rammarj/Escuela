// ListaTemplate.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Lista.cpp"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Lista<int> *l = new Lista<int>();
	int pos;
	l->add(2);
	l->add(7);
	l->add(2);
	l->add(22);
	l->add(22);
	l->add(2);
	l->add(80);
	l->add(46);
	cout << "\n\nvalores antes de ser ordenados:\n";
	for (size_t i = 0; i < l->getSize(); i++)
	{
		cout << l->getValueAt(i) << endl;
	}
	cin.get();
	//l->sort_insercion();
	//l->sort_seleccion_directa();
	//l->sort_burbuja();
	l->quick_sort();
	cout << "\n\nvalores despues de ser ordenados:\n";
	for (unsigned int i = 0; i < l->getSize(); i++)
	{
		cout << l->getValueAt(i) << endl;
	}
	cin.get();
	Lista<int>* aux = l->find_binaria(2);
	for (unsigned int i = 0; i < aux->getSize(); i++)
	{
		cout << "posicion " << aux->getValueAt(i) << endl;
	}
	delete aux;

	cin.get();
	return 0;
}

