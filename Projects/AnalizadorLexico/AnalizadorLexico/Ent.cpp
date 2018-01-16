#include "Ent.h"


Ent::Ent(Ent ^n)
{
	this->tabla = gcnew HashTableAL();
	this->ant = n;
}

void Ent::put(Token^ w, Id^ i){
	this->tabla->put(w, i);
}

Id^ Ent::get(Token^ w){
	for (Ent^ e = this; e != nullptr; e = e->ant)
	{
		Id^ encontro = (Id^)e->tabla->get(w);
		if (encontro != nullptr) return encontro;
	}
	return nullptr;
}
