// cola.cpp: define el punto de entrada de la aplicación de consola.
//

//#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "Cola.h"

using namespace std;

int main(){//{int argc, _TCHAR* argv[]){
	Nodo *nodo;
	string dato;
	Cola* cola = new Cola();
	int opc;
	do
	{
		system("cls");
		cout << "1) agregar numero" << endl;
		cout << "2) ver " << endl;
		cout << "3) quitar" << endl;
		cout << "4) ver tamanio" << endl;
		cout << "5) salir" << endl;
		cout << "Elige: "; cin >> opc;
		switch (opc){
		case 1:
			cout << "\ndato: "; cin >> dato;
			cola->push(dato);
			break;
		case 2:
			nodo = cola->getFirst();
			if (nodo)
				cout << "Primer dato: " << nodo->getDato() << endl;
			else
				cout << "No hay datos" << endl;

			break;
		case 3:
			cola->pop();
			break;
		case 4:
			cout << "tamanio: " << cola->getSize() << endl;
			break;
		case 5:	break;
		default:
			break;
		}
		system("pause");
	} while (opc != 5);
	delete cola;
	return 0;
}

