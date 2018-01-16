
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, *b, c, *d;
	a = 12;
	b = new int;
	*b = 12;
	d = &c;
	c = a + *b;
	printf("la suma es %d y esta almacenada en %x.\n",c,d);
	system("pause");
	delete (b);
	return 0;
}
