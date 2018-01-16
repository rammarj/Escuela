#pragma once
class Pedido
{
private:
	unsigned int cliente;
	unsigned int cantidad;
	enum TIPO
	{
		A,B,C,D,E,F,G
	} tipo;

public:
	Pedido();
	void setCliente(unsigned int);
	unsigned int getCliente();
	unsigned int getCantidad();
	void setCantidad(unsigned int);
	void setTipo(enum TIPO);
	enum TIPO getTipo();
	~Pedido();
};

