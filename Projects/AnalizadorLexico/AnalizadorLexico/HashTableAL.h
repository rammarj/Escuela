#ifndef _HASHTABLE_AL_H_
#define _HASHTABLE_AL_H_

using namespace System;

ref class HashTableAL :
public System::Collections::Hashtable
{
private:
	Object^ getValor(int pos);

public:
	HashTableAL();
	Object^ get(Object^ s);
	void put(Object^ key, Object^ value);
};

#endif