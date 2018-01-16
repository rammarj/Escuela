// Arbol.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Arbol.cpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int opc;
	int dato = 0;
	bool succes;
	Lista<int>* datos;
	Arbol<int> a;
	do{
		system("cls");
		cout << "\tMenu\n\n";
		cout << "1) agregar\n";
		cout << "2) buscar (ver si un dato ya se encuentra agregado)\n";
		cout << "3) imprimir\n";
		cout << "4) limpiar\n";
		cout << "5) salir\n";
		cout << "Elegir: "; cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "numero: "; cin >> dato;
			succes = a.agregar(dato);
			if (succes)
				cout << "Agregado correctamente.";
			else
				cout << "El dato ya se encuentra registrado.";
			system("pause>null");
			break;
		case 2:
			cout << "\nBuscar: "; cin >> dato;
			succes = a.buscar(dato);
			if (succes)
				cout << "El dato ya esta registrado.";
			else
				cout << "El dato todavia no esta registrado.";
			system("pause>null");
			break;
		case 3:
			datos = a.getDatos(Arbol<int>::IMP_POSORDER);
			for (unsigned int i = 0; i < datos->getSize(); i++){
				cout << datos->getValueAt(i) << ",";
			}
			system("pause>null");
			break;
		case 4:
			a.limpiar();
			system("pause>null");
			break;
		case 5:break;
		default:
			break;
		}
	} while (opc!=5);
	return 0;
}

