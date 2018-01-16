// Grafo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "GrafoImpl.h"
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	GrafoImpl grafo;
	Tabla2* vecinos;
	Tabla* adyacencias;
	Lista* nodos;
	int opc, index, opc2;
	string nodo, aux;
	cout << "\n\nNombre del nodo: "; cin >> aux;
	grafo.setIdentificador(aux);
	do{
		system("cls");
		cout << "\n\n\t#Menu\n\n";
		cout << "1) Agregar nodo\n";
		cout << "2) Quitar nodo\n";
		cout << "3) Cambiar...\n";
		cout << "4) Agregar relacion\n";
		cout << "5) ver informacion\n";
		cout << "6) Salir\n";
		cout << "Elegir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\nNombre del nodo: "; cin >> nodo;
			grafo.addNodo(nodo);
			break;
		case 2:
			grafo.getNodos()->clear();
			grafo.getRelaciones()->clear();
			break;
		case 3:
			do{
				system("cls");
				cout << "\n\n\tMenu\n\n";
				cout << "1) Cambiar identificador del grafo\n";
				cout << "2) Cambiar uso de direccion\n";
				cout << "3) Volver \n";
				cout << "Elegir: "; cin >> opc2;
				switch (opc2)
				{
				case 1:
					cout << "\nNuevo identificador: "; cin >> aux;
					grafo.setIdentificador(aux);
					break;
				case 2:
					cout << "\n¿Usar direccion?(1 = Si, 0 = No): "; cin >> index;
					if (index == 1)
					{
						grafo.usarDireccion(true);
					}
					else
					{
						grafo.usarDireccion(false);
					}
					break;
				case 3:break;
				default:
					break;
				}
			} while (opc2!=3);
			break;
		case 4:
			cout << "\nNodo de inicio: "; cin >> nodo;
			cout << "Nodo de inicio: "; cin >> aux;
			grafo.addRelacion(nodo, aux);
			break;
		case 5:
			cout << "\nInformacion del grafo...\n\n";
			cout << "identificador: " << grafo.getIdentificador() << "\n";
			cout << "usa direccion: " << ((grafo.usaDireccion()) ? "si" : "no") << "\n";
			cout << "nodos: " << grafo.getNodosSerializada() << "\n";
			cout << "grafo: " << grafo.getGrafo() << "\n";
			vecinos = grafo.getVecinos();
			cout << "\n\nnodo \t vecinos\n\n";
			for (size_t i = 0; i < vecinos->getSize(); i++)
			{
				NodoHash2* n = vecinos->getValueAt(i);
				cout << n->getKey() << "\t  " << n->getValue() << "\n";
			}
			/*adyacencias = grafo.getAdyacencias();
			
			cout << "\n\nnodo\tnodos adyacentes\n\n";
			for (size_t i = 0; i < adyacencias->getSize(); i++)
			{
				NodoHash* nodo = adyacencias->getValueAt(i);
				cout << nodo->getKey() << "\t" << nodo->getValue() << "\n";
			}*/
			system("pause>null");
			break;
		case 6:
			break;
		default:
			break;
		}
	} while (opc != 6);
	return 0;
}

