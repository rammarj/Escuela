
/**
* Todos los nodos que tiene la lista se crean desde esta clase.
* @author: Joaquin R. Martinez
*/
class Nodo
{
private:
	/**
	* Nodo siguiente
	*/
	Nodo* next;
	/**
	* Nodo anterior
	*/
	Nodo* before;
	/**
	* Valor que guarda el nodo
	*/
	int value;
	

public:
	/**
	* Crea un nuevo nodo
	*/
	Nodo();
	/**
	* Establece el apuntador al siguiente nodo.
	*/
	void setNext(Nodo* next);
	/**
	* Establece el valor que guardará el nodo.
	*/
	void setData(int value);
	/**
	* Obtiene el nodo siguiente establecido.
	*/
	Nodo* getNext();
	/**
	* Obtiene el dato que guarda el nodo.
	*/
	int getData();
	/**
	* Establece el nodo anterior a este nodo.
	*/
	void setBefore(Nodo* before);
	/**
	* Obtiene el nodo anterior establecido.
	*/
	Nodo* getBefore();
	~Nodo();
};

