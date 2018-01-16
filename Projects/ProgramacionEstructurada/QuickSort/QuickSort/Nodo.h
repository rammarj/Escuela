#pragma once

class Nodo
{
private:
	Nodo* next;
	Nodo* after;
	int value;
	

public:
	Nodo();
	void setNext(Nodo* next);
	void setData(int value);
	Nodo* getNext();
	int getData();
	void setAfter(Nodo* after);
	Nodo* getAfter();
	~Nodo();
};

