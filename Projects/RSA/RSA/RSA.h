#ifndef _RSA_ALG_
#define _RSA_ALG_

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int gcd(int, int);
int gcd_extendido(int, int);
bool esPrimo(int);
void generarParClaves(int, int, int*, int*, int*);
int random(int,int);

#endif