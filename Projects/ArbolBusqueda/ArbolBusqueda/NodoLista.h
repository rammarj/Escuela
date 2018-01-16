#ifndef _NODO_LISTA_H_
#define _NODO_LISTA_H_

template <class tipo>
class NodoLista
{
private:
	NodoLista<tipo>* next;
	NodoLista<tipo>* after;
	tipo value;

public:
	NodoLista();
	void setNext(NodoLista<tipo>* next);
	void setData(tipo value);
	NodoLista<tipo>* getNext();
	tipo getData();
	void setAfter(NodoLista<tipo>* after);
	NodoLista<tipo>* getAfter();
	~NodoLista();
};

#endif