// QuickSort.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include "Lista.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int opc, opc2;
	int val;
	int index;
	Lista l;
	do{
		system("cls");
		cout << "\t\tOrdenamiento quicksort con lista doblemente enlazada";
		cout << "\n\n\n\t1) add elemento";
		cout << "\n\t2) quitar elemento";
		cout << "\n\t3) actualizar elemento";
		cout << "\n\t4) limpiar lista";
		cout << "\n\t5) mostrar";
		cout << "\n\t6) ordenar (quick sort)";
		cout << "\n\t7) salir";
		cout << "\n\tElija: "; cin >> opc;
		switch (opc)
		{
		case 1:
			do{
				system("cls");
				cout << "\t\tOrdenamiento quicksort con lista doblemente enlazada";
				cout << "\n\n\n\t1) add elemento al inicio";
				cout << "\n\t2) add elemento al final";
				cout << "\n\t3) add elemento por posicion";
				cout << "\n\t4) ir al menu principal";
				cout << "\n\telegir: "; cin >> opc2;
				if (opc2>0&&opc2<4)
				{
					cout << "\n\tvalor: "; cin >> val;
				}
				switch (opc2){
					case 1:
						l.insertElementAt(0, val);
						break;
					case 2:
						l.add(val);
						break;
					case 3:
						cout << "\tposicion (desde 0): "; cin >> index;
						if (index>=0 && index<l.getSize())
						{
							l.insertElementAt(index, val);
						}
						break;
					case 4:
						break;
					default:
						break;
				}
				
			} while (opc2 != 4);
			break;
		case 2:
			do{
				system("cls");
				cout << "\t\tOrdenamiento quicksort con lista doblemente enlazada";
				cout << "\n\n\n\t1) quitar al inicio";
				cout << "\n\t2) quitar al final";
				cout << "\n\t3) quitar por posicion";
				cout << "\n\t4) ir al menu principal";
				cout << "\n\telegir: "; cin >> opc2;
				switch (opc2){
				case 1:
					l.removeElementAt(0);
					break;
				case 2:
					l.removeElementAt(l.getSize()-1);
					break;
				case 3:
					cout << "\tposicion: "; cin >> index;
					l.removeElementAt(index);
					break;
				case 4:
					break;
				default:
					break;
				}

			} while (opc2 != 4);
			cout << "\n\tposicion: "; cin >> val;
			l.removeElementAt(val);
			break;
		case 3:
			cout << "\n\tindex: "; cin >> index;
			cout << "\tindex: "; cin >> val;
			l.setValueAt(index, val);
			break;
		case 4:
			l.clear();
			break;
		case 5:
			cout << "\n\t";
			for (size_t i = 0; i < l.getSize(); i++)
			{
				cout << l.getValueAt(i)<<",";
			}
			_getch();
			break;
		case 6:
			l.sort();
			break;
		case 7:
			break;
		default:
			break;
		}
	} while (opc!=7);
	return 0;
}

