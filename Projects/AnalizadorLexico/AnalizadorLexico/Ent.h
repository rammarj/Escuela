#pragma once
#ifndef _ENT_H_
#define _ENT_H_

#include "Token.h"
#include "HashTableAL.h"
#include "Id.h"

ref class Ent
{
private:
	HashTableAL^ tabla;

protected:
	Ent ^ant;

public:
	Ent(Ent^ n);
	void put(Token^ w, Id^ i);
	Id^ get(Token^ w);
};

#endif