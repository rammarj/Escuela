#include "HashTableAL.h"

HashTableAL::HashTableAL() : Hashtable(){}

void HashTableAL::put(Object^ key, Object^ value)
{
	this->Add(key, value);
	//Console::WriteLine("agregado: "+key+" valor: "+value);	cuestiones de logging para ver donde esta el error
}

Object^ HashTableAL::get(Object^ key){
	unsigned short int index = 0;
	//Console::WriteLine("obtener: " + key);
	for each (Object ^var in this->Keys)
	{
		if (key == var)
		{
			//Console::WriteLine("obtener: "+key+" valor: "+getValor(index));
			return getValor(index);
		}
		index++;
	}
	return nullptr;
}

Object^ HashTableAL::getValor(int pos){
	unsigned short int p = 0;
	for each (Object^ var in this->Values)
	{
		Console::Write(var);
		if (pos == p)
		{
			return var;
		}
		p++;
	}
	return nullptr;
}
