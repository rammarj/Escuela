#include "Analizador.h"


Analizador::Analizador(AnalizadorLexico^ l)
{
	lex = l; mover();
}

void Analizador::mover(){
	busca = lex->explorar();
}

void Analizador::error(String^ s){
	throw gcnew Exception("cerca de linea " + lex->linea + ": " + s);
}

void Analizador::coincidir(int t){
	if (busca->etiqueta == t) mover();
	else error("error de sintaxis");
}

void Analizador::programa(){
	Instr^ s = bloque();
	int inicio = s->nuevaEtiqueta(), despues = s->nuevaEtiqueta();
	s->emitirEtiqueta(inicio); s->gen(inicio, despues); s->emitirEtiqueta(despues);
}

Instr^  Analizador::bloque(){
	coincidir('{'); Ent^ entGuardado = sup; sup = gcnew Ent(sup);
	decls(); Instr^ s = instrs();
	coincidir('}'); sup = entGuardado;
	return s;
}

void Analizador::decls(){
	while (busca->etiqueta == Etiqueta::BASIC)
	{
		Tipo^ p = tipo(); Token^ tok = busca; coincidir(Etiqueta::ID); coincidir(';');
		Id^ id = gcnew Id((Palabra^)tok, p, usado);
		sup->put(tok, id);
		usado = usado + p->anchura;
	}
}

Tipo^ Analizador::tipo(){
	Tipo^ p = (Tipo^)busca;
	coincidir(Etiqueta::BASIC);
	if (busca->etiqueta != '[') return p;
	else return dims(p);
}

Tipo^ Analizador::dims(Tipo^ p){
	coincidir('['); Token^ tok = busca; coincidir(Etiqueta::NUM); coincidir(']');
	if (busca->etiqueta == '[') p = dims(p);
	return gcnew Arreglo(((Numero^)tok)->valor, p);
}

Instr^ Analizador::instrs(){
	if (busca->etiqueta == '}')return Instr::Null;
	else return gcnew Sec(instr(), instrs());
}

Instr^ Analizador::instr(){
	Expr^ x;
	Instr^ s1, ^s2, ^instrGuardada;
	if (busca->etiqueta == ';')
	{
		mover(); return Instr::Null;
	}
	else if (busca->etiqueta == Etiqueta::IF)
	{
		coincidir(Etiqueta::IF); coincidir('('); x = boolean(); coincidir(')');
		s1 = instr();
		if (busca->etiqueta != Etiqueta::ELSE) return gcnew If(x, s1);
		coincidir(Etiqueta::ELSE);
		s2 = instr();
		return gcnew Else(x, s1, s2);
	}
	else if (busca->etiqueta == Etiqueta::WHILE)
	{
		While^ nodowhile = gcnew While();
		instrGuardada = Instr::Circundante; Instr::Circundante = nodowhile;
		coincidir(Etiqueta::WHILE); coincidir('('); x = boolean(); coincidir(')');
		s1 = instr();
		nodowhile->inic(x, s1);
		Instr::Circundante = instrGuardada;
		return nodowhile;
	}
	else if (busca->etiqueta == Etiqueta::DO)
	{
		Do^ nododo = gcnew Do();
		instrGuardada = Instr::Circundante; Instr::Circundante = nododo;
		coincidir(Etiqueta::DO);
		s1 = instr();
		coincidir(Etiqueta::WHILE); coincidir('('); x = boolean(); coincidir(')');
		coincidir(';');
		nododo->inic(s1, x);
		Instr::Circundante = instrGuardada;
		return nododo;
	}
	else if (busca->etiqueta == Etiqueta::BREAK)
	{
		coincidir(Etiqueta::BREAK); coincidir(';');
		return gcnew Break();
	}
	else if (busca->etiqueta == '{')
		return bloque();	
	else
		return asignar();
}

Instr^ Analizador::asignar()
{
	Instr^ instr; Token^ t = busca;
	coincidir(Etiqueta::ID);
	Id^ id = sup->get(t);
	if (id == nullptr) error(t->toString() + " no declarado");
	if (busca->etiqueta == '=') {
		mover(); instr = gcnew Est(id, boolean());
	}
	else{
		Acceso^ x = desplazamiento(id);
		coincidir('='); instr = gcnew EstElem(x, boolean());
	}
	coincidir(';');
	return instr;
}

Expr^ Analizador::boolean(){
	Expr^ x = unir();
	while (busca->etiqueta == Etiqueta::OR)
	{
		Token^ tok = busca; mover(); x = gcnew Or(tok, x, unir());
	}
	return x;
}

Expr^ Analizador::unir(){
	Expr^ x = igualdad();
	while (busca->etiqueta == Etiqueta::AND)
	{
		Token^ tok = busca; mover(); x = gcnew And(tok, x, igualdad());
	}
	return x;
}

Expr^ Analizador::igualdad(){
	Expr^ x = rel();
	while (busca->etiqueta == Etiqueta::EQ || busca->etiqueta == Etiqueta::NE)
	{
		Token^ tok = busca; mover(); x = gcnew Rel(tok, x, rel());
	}
	return x;
}

Expr^ Analizador::rel(){
	Expr^ x = expr();
	if (busca->etiqueta == '<' || busca->etiqueta == Etiqueta::LE
		|| busca->etiqueta == Etiqueta::GE || busca->etiqueta == '>'){
		Token^ tok = busca; mover(); return gcnew Rel(tok, x, expr());
	}
	return x;
}

Expr^ Analizador::expr(){
	Expr^ x = term();
	while (busca->etiqueta == '+' || busca->etiqueta == '-')
	{
		Token^ tok = busca; mover(); x = gcnew Arit(tok, x, term());
	}
	return x;
}

Expr^ Analizador::term(){
	Expr^ x = unario();
	while (busca->etiqueta == '*' || busca->etiqueta == '/')
	{
		Token^ tok = busca; mover(); x = gcnew Arit(tok, x, unario());
	}
	return x;
}

Expr^ Analizador::unario(){
	if (busca->etiqueta == '-')
	{
		mover(); return gcnew Unario(Palabra::minus, unario());
	}
	else if (busca->etiqueta == '!'){
		Token^ tok = busca; mover(); return gcnew Not(tok, unario());
	}
	else return factor();
}

Expr^ Analizador::factor(){
	Expr^ x = nullptr;
	if (busca->etiqueta == '(')
	{
		mover(); x = boolean(); coincidir(')');
		return x;
	}
	else if (busca->etiqueta == Etiqueta::NUM){
		x = gcnew Constante(busca, Tipo::Int);
		mover(); return x;
	}
	else if (busca->etiqueta == Etiqueta::REAL){
		x = gcnew Constante(busca, Tipo::Float);
		mover(); return x;
	}
	else if (busca->etiqueta == Etiqueta::TRUE){
		x = Constante::True;
		mover(); return x;
	}
	else if (busca->etiqueta == Etiqueta::FALSE){
		x = Constante::False;
		mover(); return x;
	}
	else if (busca->etiqueta == Etiqueta::ID)
	{
		String^ s = busca->toString();
		Id^ id = sup->get(busca);
		if (id == nullptr) error(busca + " no declarado");
		mover();
		if (busca->etiqueta != '[') return id;
		else return desplazamiento(id);
	}
	error("error de sintaxis"); return x;
}

Acceso^ Analizador::desplazamiento(Id^ a){
	Expr^ i, ^w, ^t1, ^t2, ^ubic;
	Tipo^ tipo = a->tipo;
	coincidir('['); i = boolean(); coincidir(']');
	tipo = ((Arreglo^)tipo)->de;
	w = gcnew Constante(tipo->anchura);
	t1 = gcnew Arit(gcnew Token('*'), i, w);
	ubic = t1;
	while (busca->etiqueta == '[') //multi-dimensional
	{
		coincidir('['); i = boolean(); coincidir('[');
		tipo = ((Arreglo^)tipo)->de;
		w = gcnew Constante(tipo->anchura);
		t1 = gcnew Arit(gcnew Token('*'), i, w);
		t2 = gcnew Arit(gcnew Token('+'), ubic, t1);
		ubic = t2;
	}
	return gcnew Acceso(a, ubic, tipo);
}
