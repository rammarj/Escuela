#ifndef _NODO_H_
#define _NODO_H_
template <class tipo>
class Nodo
{
private:
	Nodo<tipo>* next;
	Nodo<tipo>* after;
	tipo value;
	

public:
	Nodo();
	void setNext(Nodo* next);
	void setData(tipo value);
	Nodo<tipo>* getNext();
	tipo getData();
	void setAfter(Nodo* after);
	Nodo<tipo>* getAfter();
	~Nodo();
};

#endif