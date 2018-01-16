
/*************************** Saludo ************************/

#include <stdio.h>
#include <stdlib.h>

#define TAM_BUF 20

main(){
	char *mensaje1 = "Bienvenido a C";
	char *mensaje2 = "Te alegrara el haberme conocido";
	char nombre[TAM_BUF];

	system("cls");
	printf("¿Cual es tu nombre? ");
	gets_s(nombre, TAM_BUF);
	printf("\n%s %s\n%s\n", mensaje1, nombre, mensaje2);
	getchar();
}
