#pragma once
class Pedido
{
private:
	unsigned int cliente;
	unsigned int cantidad;
	char tipo;

public:
	Pedido();
	void setCliente(unsigned int);
	unsigned int getCliente();
	unsigned int getCantidad();
	void setCantidad(unsigned int);
	void setTipo(char);
	char getTipo();
	~Pedido();
};

