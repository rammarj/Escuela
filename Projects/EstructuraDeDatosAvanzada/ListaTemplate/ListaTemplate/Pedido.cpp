#include "stdafx.h"
#include "Pedido.h"


Pedido::Pedido()
{
}

void Pedido::setCliente(unsigned int cliente){
	this->cliente = cliente;
}

unsigned int Pedido::getCliente(){
	return (this->cliente);
}

unsigned int Pedido::getCantidad(){
	return (this->cantidad);
}

void Pedido::setCantidad(unsigned int cantidad){
	this->cantidad = cantidad;
}

void Pedido::setTipo(enum TIPO tipo){
	this->tipo = tipo;
}

enum Pedido::TIPO Pedido::getTipo(){
	return this->tipo;
}

Pedido::~Pedido()
{
}
