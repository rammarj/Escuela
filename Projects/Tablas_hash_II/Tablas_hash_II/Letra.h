#ifndef _LETRA_H_
#define _LETRA_H_
#include "Lista.cpp"
class Letra
{
private:
	Lista<Lista<char>> letras;
	char letra;

public:
	Letra(char l=' ');
	unsigned int short getNumeroLetra();
	unsigned int getNumeroLetras();
	~Letra();
	void operator=(const Letra&l){
		this->letra = l.letra;
	}
};

#endif