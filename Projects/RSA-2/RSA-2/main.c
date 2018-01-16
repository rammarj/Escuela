
#include "RSA.h"

int main()
{
	printf("\nENTER FIRST PRIME NUMBER\n");
	scanf( "%ld", &p);
	flag = esPrimo(p);
	if (flag == 0)
	{
		printf("\nWRONG INPUT\n");
		exit(1);
	}
	printf("\nENTER ANOTHER PRIME NUMBER\n");
	scanf("%ld",&q);
	flag = esPrimo(q);
	if (flag == 0 || p == q)
	{
		printf("\nWRONG INPUT\n");
		exit(1);
	}
	printf("\nENTER MESSAGE\n");
	fflush(stdin);
	scanf("%s", msg);
	for (int i = 0; msg[i] != NULL; i++)
		m[i] = msg[i];
	n = p*q;
	t = (p - 1)*(q - 1);
	clavePublica();

	encriptar();
	desencriptar();
	getchar();
	return 0;
}
