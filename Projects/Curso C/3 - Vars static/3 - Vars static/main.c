

#include <stdio.h>

int contador(void);

main(){

	for (size_t i = 0; i < 10; i++)
	{
		printf("Iteracion %d: %d\n", i, contador());
	}
	getchar();
}

int contador(){
	static int cont = 2; //solo se inicializa una vez, posteriores llamadas a la funcion se toma el ultimo valor dado
	cont+=2;
}

