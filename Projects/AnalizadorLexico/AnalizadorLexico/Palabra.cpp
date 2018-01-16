#include "Palabra.h"


Palabra::Palabra(String ^s, int etiqueta) : Token(etiqueta)
{
	lexema = s;
}

String^ Palabra::toString(){
	return lexema;
}
