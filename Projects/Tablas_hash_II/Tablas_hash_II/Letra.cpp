#include "stdafx.h"
#include "Letra.h"


Letra::Letra(char letra)
{
	this->letra = letra;
	/////////////////////////////////////////////
	//////////////letras del alfabeto////////////
	/////////////////////////////////////////////
	//a
	Lista<char> a;
	a.agregar('a');
	a.agregar('ä');
	a.agregar('A');
	a.agregar('á');
	a.agregar('Á');
	a.agregar('à');
	a.agregar('À');
	//b
	Lista<char> b;
	b.agregar('b');
	b.agregar('B');
	//c
	Lista<char> c;
	c.agregar('c');
	c.agregar('C');
	//d
	Lista<char> d;
	d.agregar('d');
	d.agregar('D');
	//e
	Lista<char> e;
	e.agregar('e');
	e.agregar('ë');
	e.agregar('è');
	e.agregar('é');
	e.agregar('ë');
	e.agregar('É');
	e.agregar('È');
	e.agregar('E');
	//f
	Lista<char> f;
	f.agregar('f');
	f.agregar('F');
	//g
	Lista<char> g;
	g.agregar('g');
	g.agregar('G');
	//h
	Lista<char> h;
	h.agregar('h');
	h.agregar('H');
	//i
	Lista<char> i;
	i.agregar('i');
	i.agregar('ï');
	i.agregar('í');
	i.agregar('ì');
	i.agregar('I');
	i.agregar('Í');
	i.agregar('Ì');
	//j
	Lista<char> j;
	j.agregar('j');
	j.agregar('J');
	//k
	Lista<char> k;
	k.agregar('k');
	k.agregar('K');
	//m
	Lista<char> m;
	m.agregar('m');
	m.agregar('M');
	//n
	Lista<char> n;
	n.agregar('n');
	n.agregar('N');
	//ñ
	Lista<char> enie;
	enie.agregar('ñ');
	enie.agregar('Ñ');
	//o
	Lista<char> o;
	o.agregar('o');
	o.agregar('ö');
	o.agregar('ò');
	o.agregar('ó');
	o.agregar('O');
	o.agregar('Ò');
	o.agregar('Ó');
	//p
	Lista<char> p;
	p.agregar('p');
	p.agregar('P');
	//q
	Lista<char> q;
	q.agregar('Q');
	q.agregar('q');
	//r
	Lista<char> r;
	r.agregar('r');
	r.agregar('R');
	//s
	Lista<char> s;
	s.agregar('s');
	s.agregar('S');
	//t
	Lista<char> t;
	t.agregar('t');
	t.agregar('T');
	//u
	Lista<char> u;
	u.agregar('u');
	u.agregar('ü');
	u.agregar('ù');
	u.agregar('ú');
	u.agregar('U');
	u.agregar('Ù');
	u.agregar('Ú');
	//v
	Lista<char> v;
	v.agregar('V');
	v.agregar('v');
	//w
	Lista<char> w;
	w.agregar('w');
	w.agregar('W');
	//v
	Lista<char> x;
	x.agregar('x');
	x.agregar('X');
	//v
	Lista<char> y;
	y.agregar('y');
	y.agregar('Y');
	//z
	Lista<char> z;
	z.agregar('z');
	z.agregar('Z');
	/////////////////////////////////////////
	///////agregar a las letras a una lista//////
	/////////////////////////////////////////
	this->letras.agregar(a);
	this->letras.agregar(b);
	this->letras.agregar(c);
	this->letras.agregar(d);
	this->letras.agregar(e);
	this->letras.agregar(f);
	this->letras.agregar(g);
	this->letras.agregar(h);
	this->letras.agregar(i);
	this->letras.agregar(j);
	this->letras.agregar(k);
	this->letras.agregar(m);
	this->letras.agregar(enie);
	this->letras.agregar(o);
	this->letras.agregar(p);
	this->letras.agregar(q);
	this->letras.agregar(r);
	this->letras.agregar(s);
	this->letras.agregar(t);
	this->letras.agregar(u);
	this->letras.agregar(v);
	this->letras.agregar(w);
	this->letras.agregar(x);
	this->letras.agregar(y);
	this->letras.agregar(z);

}

unsigned int short Letra::getNumeroLetra(){
	for (int i = 0; i < this->letras.getTamano(); i++)
	{
		Lista<char> aux = this->letras.mostrar(i);
		for (int j = 0; j < aux.getTamano(); j++)
		{
			if (this->letra == aux.mostrar(j))
			{
				return (i + 1);//retorna el numero de lista en la que se encontro la letra
			}
		}
	}
	return 0; //si no entra en ninguno agregado, retorna cero (aqui incluye el espacio).
}

unsigned int Letra::getNumeroLetras(){
	return this->letras.getTamano();
}

Letra::~Letra()
{
}
