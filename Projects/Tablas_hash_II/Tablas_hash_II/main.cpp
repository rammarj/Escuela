// Tablas_hash_II.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "TablaHash.h"
#include <stdlib.h>
#include <stdlib.h>

int _tmain()
{ /////////////////////////////////////////
	//////BLOQUE DE PRUEBAS////////////////
	TablaHash tbl_hash, aux_hash;
	Lista<NodoHash> l_aux;
	unsigned short int opc;
	string palabra;
	char p[60] = "";
	system("color 2");
	do{
		system("cls");
		cout << "\tMENU\n\n\n";
		cout << "1) agregar\n";
		cout << "2) mostrar\n";
		cout << "3) mostrar ordenado\n";
		cout << "4) salir\n";
		cout << "Elegir: "; cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "escribe:\n";
			fflush(stdin);
			gets_s(p,59); //si se utiliza getline no lee el string
			palabra = string(p);
			tbl_hash.add(palabra);			
			break;
		case 2:
			 l_aux= tbl_hash.getLista();
			 cout << "\n";
			 for ( int i = 0; i < l_aux.getTamano(); i++)
			 {
				 cout<< i << "\t->\t" << l_aux.mostrar(i).getValor() << "\n";
			 }
			 cout << "\n\n";
			 system("pause");
			break;
		case 3:
			aux_hash = tbl_hash.obtenercalculadoTablaHash();
			l_aux = aux_hash.getLista();
			cout << "\n";
			for (int i = 0; i < l_aux.getTamano(); i++){
				cout << i << "\t->\t" << l_aux.mostrar(i).getValor() << endl;
			}
			cout << "\n\n";
			system("pause");
			break;
		default:
			break;
		}
		
	} while (opc!=4);
	return 0;
}

