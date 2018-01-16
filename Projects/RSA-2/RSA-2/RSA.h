#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 

long int p, q, n, t, flag, e[100], d[100], temp[100], m[100], en[100];
char msg[100];
int esPrimo(long int);
void clavePublica();
long int clavePrivada(long int);
void encriptar();
void desencriptar();

int esPrimo(long int pr)
{
	int i;
	int j = sqrt((double) pr );
	for (i = 2; i <= j; i++)
	{
		if (pr%i == 0)
			return 0;
	}
	return 1;
}

void clavePublica()
{
	int k;
	k = 0;
	for (int i = 2; i<t; i++)
	{
		if (t%i == 0)
			continue;
		flag = esPrimo(i);
		if (flag == 1 && i != p&&i != q)
		{
			e[k] = i; flag = clavePrivada(e[k]);
			if (flag>0)
			{
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}

long int clavePrivada(unsigned long int x)
{
	long int k = 1;
	while (1)
	{
		k = k + t;
		if (k%x == 0)
			return(k / x);
	}
}

void encriptar()
{
	long int pt, ct, key = e[0], k, len;
	int i = 0;
	len = strlen(msg);
	while (i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (int j = 0; j<key; j++)
		{
			k = k*pt;
			k = k%n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	printf("\nTHE ENCRYPTED MESSAGE IS\n");
	for (i = 0; en[i] != -1; i++)
		printf("%c", en[i]);
}

void desencriptar()
{
	long int pt, ct, key = d[0], k;
	int i = 0;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (int j = 0; j<key; j++)
		{
			k = k*ct;
			k = k%n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	printf("\nTHE DECRYPTED MESSAGE IS\n");
	for (int i = 0; m[i] != -1; i++)
		printf("%c", m[i]);
}