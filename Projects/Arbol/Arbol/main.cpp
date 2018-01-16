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
	int dato = 0, padre = 0, lado = 0;
	bool succes;
	Lista<int>* datos;
	Arbol<int> a;
	do{
		system("cls");
		cout << "\tMenu\n\n";
		cout << "1) agregar\n";
		cout << "2) imprimir\n";
		cout << "3) eliminar\n";
		cout << "4) limpiar\n";
		cout << "5) salir\n";
		cout << "Elegir: "; cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "numero: "; cin >> dato;
			cout << "despues del numero: "; cin >> padre;
			cout << "En el lado (1/0): "; cin >> lado;
			succes = a.agregar(dato,padre,(lado==1));
			if (succes)
				cout << "Agregado correctamente";
			else
				cout << "El nodo no se ha agregado";
			system("pause>null");
			break;
		case 2:
			datos = a.getDatos(Arbol<int>::IMP_POSORDER);
			for (int i = 0; i < datos->getSize(); i++){
				cout << datos->getValueAt(i) << ",";
			}
			system("pause>null");
			break;
		case 3: 
			cout << "Valor del nodo a eliminar: "; cin >> dato;
			a.eliminar(dato);
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

