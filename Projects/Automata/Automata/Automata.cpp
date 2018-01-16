// Automata.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Transicion.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int opc, opc2, size;
	string estado, simbolo, hacia_estado, l_estados = "", l_simbolos = "", l_total = "", l_terminales = "";
	string lenguaje, gramatica, estado_inicial, aux;
	Lista<string>* estados, *simbolos, *terminales, *establecer_estados_terminales = new Lista<string>(), *no_term;

	Transicion t;
	do{
		system("cls");
		cout << "\tMenu\n\n";
		cout << "1) escribir automata\n";
		cout << "2) establecer estado inicial\n";
		cout << "3) establecer estados finales\n";
		cout << "4) ver informacion\n";
		cout << "5) salir\n";
		cout << "Elegir: "; cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\nEscribe una transicion. \nescribe el estado: "; cin >> estado;
			cout << "Escribe el simbolo: "; cin >> simbolo;
			cout << "Escribe el estado hacia donde se dirige: "; cin >> hacia_estado;
			t.addTransicion(estado, simbolo, hacia_estado);
			break;
		case 2:
			cout << "\nestado inicial: "; cin >> estado_inicial;
			t.setEmpieza(estado_inicial);
			break;
		case 3:
			do{
				system("cls");
				cout << "\n\tMenu\n\n";
				cout << "1) agregar\n";
				cout << "2) limpiar\n";
				cout << "3 salir del submenu\n";
				cout << "Elegir: "; cin >> opc2;
				switch (opc2)
				{
				case 1:
					cout << "\nEstado: "; cin >> estado;
					establecer_estados_terminales->add(estado);
					break;
				case 2:
					establecer_estados_terminales->clear();
					break;
				case 3:
					t.setTermina(establecer_estados_terminales);
					break;
				default:
					break;
				}
			} while (opc2!=3);
			break;
		case 4:
			l_estados = "", l_simbolos = "", l_total = "", l_terminales = "";
			estados = t.getNombreEstados();
			for (size_t i = 0; i < estados->getSize(); i++)
			{
				l_estados += estados->getValueAt(i);
				l_estados += ", ";
			}
			simbolos = t.getSimbolos();
			for (size_t i = 0; i < simbolos->getSize(); i++)
			{
				l_simbolos += simbolos->getValueAt(i);
				l_simbolos += ", ";
			}
			terminales = t.getTermina();
			for (size_t i = 0; i < terminales->getSize(); i++)
			{
				l_terminales += terminales->getValueAt(i);
			}
			lenguaje = "L = ({";
			lenguaje += l_estados;
			lenguaje += "}, {";
			lenguaje += l_simbolos;
			lenguaje += "}, ";
			lenguaje += t.getEmpieza();
			lenguaje += ", ";
			lenguaje += l_terminales;
			lenguaje += " )";
			///////////
			cout << lenguaje <<"\n";
			////////////////////////////////////////////////////
			size = t.getSimbolosNoTerminales()->getSize();
			aux = "";
			if (!t.estadoInicialConArco())
			{
				size--;
			}
			no_term = t.getSimbolosNoTerminales();
			for (size_t i = 0; i < size; i++)
			{
				aux += no_term->getValueAt(i);
				aux += ", ";
			}
			gramatica = "G=({";
			gramatica += aux;
			gramatica += "}, ";
			aux = "";
			simbolos = t.getSimbolos();
			for (size_t i = 0; i < simbolos->getSize(); i++)
			{
				aux += simbolos->getValueAt(i);
				aux += ", ";
			}
			gramatica += "{";
			gramatica += aux;
			gramatica += "}, P ,S }";
			cout << gramatica << "\n";
			////////////////////////////////////////////////////////////////
			system("pause>null");
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (opc!=4);
	return 0;
}

