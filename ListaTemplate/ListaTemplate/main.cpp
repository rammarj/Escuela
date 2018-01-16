
#include "stdafx.h"
#include "Lista.cpp"
#include "Pedido.h"
#include <iostream>

using namespace std;

Lista<Pedido> pedidos;

void listar()
{
	cout << "Total de pedidos: " << pedidos.getSize() << endl << endl;
	for (size_t i = 0; i < pedidos.getSize(); i++)
	{
		Pedido pedido = pedidos.getValueAt(i);	
		cout << "No. pedido: " << i+1 << endl;
		cout << "Cliente: " << pedido.getCliente() << endl;
		cout << "Tipo: " << pedido.getTipo() << endl;
		cout << "Cantidad: " << pedido.getCantidad() << endl << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned short int eleccion;
	unsigned int cliente;
	unsigned int cantidad;
	unsigned short int eliminar;
	Pedido pedido;
	char tipo;
	do{
		cout << "==============================================" << endl;
		cout << "\t\tLista de pedidos"<<endl;
		cout << "==============================================" << endl;
		cout << "\tMenu" << endl << endl;
		cout << "1) Agregar" << endl;
		cout << "2) eliminar" << endl;
		cout << "3) listar" << endl;
		cout << "4) limpiar lista de pedidos" << endl;
		cout << "5) salir" << endl;
		cout << "Elije opcion: ";
		cin >> eleccion;
		switch (eleccion)
		{
		case 1:
			cout << "Agregar..."<<endl<<"Escriba los datos del pedido:" << endl;
			cout << "Cliente: "; cin >> cliente;
			cout << "Tipo: "; cin >> tipo;
			cout << "Cantidad: "; cin >> cantidad;
			pedido.setCliente(cliente);
			pedido.setTipo(tipo);
			pedido.setCantidad(cantidad);
			pedidos.add(pedido);
			cout << "Pedido agregado";
			break;
		case 2:
			listar();
			cout << "Elija el numero de pedido a eliminar: "; cin >> eliminar;
			if (eliminar > 0 && eliminar <= pedidos.getSize())
				pedidos.removeElementAt(eliminar);
			cout << "Hecho";
			break;
		case 3:
			listar();
			break;
		case 4:
			pedidos.clear();
			cout << "Hecho";
			break;
		case 5:

			break;
		default:
			cout << "esa opcion no existe!";
			break;
		}
		getchar();
	} while (eleccion!=5);
	return 0;
}
