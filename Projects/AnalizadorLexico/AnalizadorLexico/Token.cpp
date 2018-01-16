#include "Token.h"

Token::Token(int t)
{
	etiqueta = t;
}

String^ Token::toString(){
	return (""+(char)etiqueta);
}
