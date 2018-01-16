// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdint.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int16_t i = 1;
	int8_t *p = (int8_t *)&i;

	if (p[0] == 1)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	//return 0;
	return 0;
}

