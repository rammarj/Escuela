#include "Id.h"


Id::Id(Palabra^ id, Tipo^ p, int b) : Expr(id, p)
{
	this->desplazamiento = b;
}
