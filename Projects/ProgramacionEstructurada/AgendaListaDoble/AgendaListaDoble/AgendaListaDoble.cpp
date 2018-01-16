// AgendaListaDoble.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Agenda.h"
#include <stdlib.h>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int opc, opc2, edad;
	unsigned int index;
	string nombre, app, apm, tel;
	Contacto c;
	Agenda a;
	do
	{
		system("cls");
		cout << "\n\n\t\t\tRegistro de personas";
		cout << "\n\t1) add persona";
		cout << "\n\t2) eliminar persona";
		cout << "\n\t3) buscar persona";
		cout << "\n\t4) desplegar";
		cout << "\n\t5) salir";
		cout << "\n\telige: "; cin >> opc;
		switch (opc)
		{
		case 1:
			do{
				system("cls");
				cout << "\n\n\t\t\tRegitro de personas";
				cout << "\n\t1) add persona al inicio";
				cout << "\n\t2) add persona al final";
				cout << "\n\t3) add persona por posicion";
				cout << "\n\t4) regresar al menu principal";
				cout << "\n\telige: "; cin >> opc2;
				if (opc2 > 0 && opc2 < 4)
				{
					cout << "\n\n\tNombre: "; cin >> nombre;
					cout << "\tapellido paterno: "; cin >> app;
					cout << "\tapellido materno: "; cin >> apm;
					cout << "\tedad: "; cin >> edad;
					cout << "\ttelefono: "; cin >> tel;
					c.setNombre(nombre);
					c.setApPaterno(app);
					c.setApMaterno(apm);
					c.setEdad(edad);
					c.setTelefono(tel);
				}
				switch (opc2)
				{
				case 1:
					a.getLista()->insertElementAt(0,c);
					break;
				case 2:
					a.getLista()->add(c);
					break;
				case 3:
					cout << "\n\tindice del elemento: "; cin >> index;
					if (index>0&&index<=a.getLista()->getSize())
					{
						a.getLista()->insertElementAt(index - 1, c);
					}
					break;
				case 4:
					break;
				default:
					break;
				}
			} while (opc2!=4);
			break;
		case 2:
			do{
				system("cls");
				cout << "\n\n\t\t\tEliminacion de personas";
				cout << "\n\t1) eliminar al inicio";
				cout << "\n\t2) eliminar al final";
				cout << "\n\t3) eliminar por posicion";
				cout << "\n\t4) regresar al menu principal";
				cout << "\n\telige: "; cin >> opc2;
				switch (opc2)
				{
				case 1:
					a.getLista()->removeElementAt(0);
					break;
				case 2:
					a.getLista()->removeElementAt(a.getLista()->getSize() - 1);
					break;
				case 3:
					cout << "\n\tindice del elemento: "; cin >> index;
					if (index>0 && index <= a.getLista()->getSize())
					{
						a.getLista()->removeElementAt(index - 1);
					}
					break;
				case 4:
					break;
				default:
					break;
				}
			} while (opc2 != 4);
			break;
		case 3:
			cout << "\n\n\tnombre: "; cin >> nombre;
			index = a.search(nombre);
			if (index != -1)
			{
				c = a.getLista()->getValueAt(index);
				cout << "\n\tse encontro el contacto: ";
				cout << "\n\n\tnombre:" << c.getNombre() << "\n";
				cout << "\ttelefono:" << c.getTelefono() << "\n";
			}
			else{
				cout << "\n\n\tNo se encontro el contacto...";
			}
			_getch();
			break;
		case 4:
			cout << "\n\n\t\tdesplegando...";
			for (size_t i = 0; i < a.getLista()->getSize(); i++)
			{
				c = a.getLista()->getValueAt(i);
				cout << "\n\n\n\t" << i + 1 << "\n";
				cout << "\tnombre:" << c.getNombre() << "\n";
				cout << "\tapellido paterno: "<<c.getApPaterno()<<"\n";
				cout << "\tapellido materno: " << c.getApMaterno() << "\n";
				cout << "\tedad: " << c.getEdad() << "\n";
				cout << "\ttelefono: " << c.getTelefono() << "\n";
			}
			_getch();
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (opc != 5);
	return 0;
}

