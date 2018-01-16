// Pila.cpp: define el punto de entrada de la aplicación de consola.
//

//#include "stdafx.h"
#include <stdlib.h>
//#include <iostream>
#include "pila.h"

//using namespace std;

int main(){//int argc, _TCHAR* argv[]){
	Nodo *nodo;
	Pila* pila = new Pila();
	int opc;
	string dato;
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
			pila->push(dato);
			break;
		case 2:
			nodo = pila->getTope();
			if (nodo)
				cout << "ultimo dato: " << nodo->getDato() << endl;
			else
				cout << "No hay datos" << endl;
	
			break;
		case 3:
			pila->pop();
			break;
		case 4:
			cout << "tamanio: " << pila->getSize() << endl;
			break;
		case 5:	break;
		default:
			break;
		}
		system("pause");
	}while (opc!=5);
	delete pila;
	return 0;
}

