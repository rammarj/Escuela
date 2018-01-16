
/* PROG0102.C**************** Cuadrados *********************/

#include <stdio.h>

#define FILAS 5
#define COLS  3

int numeros_pares;

void display( int n )
{
	int cuadrado;

	cuadrado = n * n;
	printf("El cuadrado de %2d es %3d\n", n, cuadrado);
}

int numero_par(int x)
{
	if (x % 2 == 0)
		return(1);
	return 0;
}

main()
{
	static const int a[FILAS][COLS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int fila, columna;

	for (fila = 0; fila < FILAS; fila++)
		for (columna = 0; columna < COLS; columna ++)
		{
			display(a[fila][columna]);
			if (numero_par(a[fila][columna]))			
				numeros_pares++;
		}
	printf("\n\nTotal numeros pares: %d\n", numeros_pares);
	getchar();
}