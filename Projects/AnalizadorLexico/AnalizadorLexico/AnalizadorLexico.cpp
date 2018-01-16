#include "AnalizadorLexico.h"


AnalizadorLexico::AnalizadorLexico()
{
	reservar(gcnew Palabra("if", Etiqueta::IF));
	reservar(gcnew Palabra("else", Etiqueta::ELSE));
	reservar(gcnew Palabra("while", Etiqueta::WHILE));
	reservar(gcnew Palabra("do", Etiqueta::DO));
	reservar(gcnew Palabra("break", Etiqueta::BREAK));
	reservar(Palabra::True);
	reservar(Palabra::False);
	reservar(Tipo::Int);
	reservar(Tipo::Char);
	reservar(Tipo::Bool);
	reservar(Tipo::Float);
}

void AnalizadorLexico::reservar(Palabra^ w){
	palabras->put(w->lexema, w);
}

void AnalizadorLexico::readch(){
	preanalisis = (char) Console::Read();
}

bool AnalizadorLexico::readch(char c){
	readch();
	if (preanalisis != c)
		return false;
	preanalisis = ' ';
	return true;
}

Token^ AnalizadorLexico::explorar(){
	for (;;readch())
	{
		if (preanalisis == ' ' || preanalisis == '\t') continue;
		else if (preanalisis == '\n') linea++;
		else break;
	}
	switch (preanalisis)
	{
	case '&':
		if (readch('&'))return Palabra::and;		
		else return gcnew Token('&');
	case '|':
		if (readch('|'))return Palabra::or;
		else return gcnew Token('|');
	case '=':
		if (readch('='))return Palabra::eq;
		else return gcnew Token('=');
	case '!':
		if (readch('='))return Palabra::ne;
		else return gcnew Token('!');
	case '<':
		if (readch('='))return Palabra::le;
		else return gcnew Token('<');
	case '>':
		if (readch('='))return Palabra::ge;
		else return gcnew Token('>');
	}
	if (Char::IsDigit(preanalisis))
	{
		int v = 0;
		do{
			v = 10 * v + int::Parse("" +preanalisis);
			readch();
		} while (Char::IsDigit(preanalisis));
		if (preanalisis != '.') return gcnew Numero(v);
		float x = v, d = 10;
		for (;; )
		{
			readch();
			if (!Char::IsDigit(preanalisis)) break;
			x = x + int::Parse("" + preanalisis) / d; d = d * 10;
		}
		return gcnew Real(x);
	}
	if (Char::IsLetter(preanalisis))
	{
		String^ s = "";
		do{
			s += preanalisis;
			readch();
		} while (Char::IsLetterOrDigit(preanalisis));
		Palabra^ w = (Palabra^)palabras->get(s);
		if (w != nullptr)
			return w;
		w = gcnew Palabra(s, Etiqueta::ID);
		palabras->put(s, w);
		return w;
	}
	Token ^tok = gcnew Token(preanalisis);
	preanalisis = ' ';
	return tok;
}
