
#include <stdio.h>

extern int var_externa;

extern int sumar(int, int); /*Una funcion por defecto es extern, aqui está explicito*/

main(){
	printf("Valor de variable externa: %d\n", var_externa);
	printf("Uso de funcion externa 'sumar' (suma=variable_externa+5): %d\n", sumar(var_externa, 5));
	getchar();
}
