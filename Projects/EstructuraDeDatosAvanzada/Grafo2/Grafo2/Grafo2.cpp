// Grafo2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Lista.h"

string replace(string in, string old, string replace){
	int pos = 0;
	pos = in.find(old);
	while (pos != string::npos)
	{
		in.replace(pos, old.length(), replace);
		pos = in.find(old);
	}
	return in;
}

void prefsuf(string cad1){
	string aux;
	int i = 1, iux;
	cout << "\ncadena :"<< cad1 << "\n\n";
	aux = cad1;
	cout << "\nprefijos:\n";
	for (size_t j = 0; j <= aux.length(); j++)
	{
		cout << (i) << ") " << aux.substr(0, j) << "\n";
		i++;
	}
	i = 1;
	cout << "\nsufijos:\n";
	iux = aux.length();
	for (size_t j = iux; j > 0; j--)
	{
		cout << i << ") " << aux.substr(j, iux) << "\n";
		i++;
	}
	cout << i << ") " << aux << "\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	Lista g;
	int opc, tam, iux, i=1;
	string alfabeto, cad1, cad2, aux, cad_aux1, cad_aux2, cad_aux3;
	do{
		system("cls");
		cout << "\n\tMenu\n\n";
		cout << "1) aniadir alfabeto: \n";
		cout << "2) verificar\n";
		cout << "3) limpiar alfabeto\n";
		cout << "4) salir\n";
		cout << "Elegir: "; cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\nsimbolo a aniadir: "; cin >> alfabeto;
			if (g.indexOf(alfabeto) == -1)
			{
				g.add(alfabeto);
			}
			break;
		case 2:
			cout << "\nCadena 1: "; cin >> cad1;
			cout << "Cadena 2: "; cin >> cad2;
			cad_aux1 = cad1;
			cad_aux2 = cad2;
			for (size_t i = 0; i < g.getSize(); i++)
			{
				aux = g.getValueAt(i);
				iux = cad1.find(aux);
				cad_aux1 = replace(cad_aux1, aux, "");
				cad_aux2 = replace(cad_aux2, aux, "");
			}
			if (cad_aux1 != "" || cad_aux2!="")
			{
				cout << "\nAlgunos simbolos de la cadena no estan en el alfabeto!";
			}
			else{
				cout << "\nCadenas concatenadas: \n"<<cad1<<cad2<<"\n";
				cout << "\ncadenas en reversa:\n";
				iux = cad1.length() - 1;
				for (int i = iux; i>=0; i--)
				{
					cout << cad1[i];
				}
				cout << "\n";
				iux = cad2.length() - 1;
				for (int i = iux; i >= 0; i--)
				{
					cout << cad2[i];
				}
				//prefijos
				cout << "\nprefijos y sufijos\n\n";
				prefsuf(cad1);
				cout << "\n\n";
				prefsuf(cad2);
			}
			system("pause>null");
			break;
		case 3:
			g.clear();
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (opc != 4);
	return 0;
}

