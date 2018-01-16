#include "RSA.h"

/*
* Algoritmo de Euclides
*/
int gcd(int a, int b) {	
	int temp;
	if (a >= 0 && b >= 0) {
		while (a != 0) {
			temp = b % a;
			b = a;
			a = temp;
		}
		return b;
	}
	return 0; //no valido si es negativo	
}

/*
* Algoritmo extendido de Euclides.
*/
int gcd_extendido(int e, int phi) {
	int c, d, x, y, x1, x2, y1, temp_phi, temp1, temp2;
	if (e >= 0 && phi >= 0) {
		d = 0;
		x1 = 0;
		x2 = 1;
		y1 = 1;
		temp_phi = phi;
		while (e > 0) {
			temp1 = temp_phi / e;
			temp2 = temp_phi - temp1 * e;
			temp_phi = e;
			e = temp2;

			x = x2 - temp1* x1;
			y = d - temp1 * y1;

			x2 = x1;
			x1 = x;
			d = y1;
			y1 = y;
		}
		if (temp_phi == 1)
			return (d + phi);
	}
	return 0;
}

bool esPrimo(int num){
	if (num == 2)
		return true;
	if (num < 2 || num % 2 == 0)
		return false;
	int max = num / 2;
	for (int n = 3; n <= max; n++)
	if (num % n == 0)
		return false;
	return true;
}


int random(int min_num, int max_num)
{
	int result = 0, low_num = 0, hi_num = 0;

	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1; // include max_num in output
	}
	else {
		low_num = max_num + 1; // include max_num in output
		hi_num = min_num;
	}
	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}

void generarParClaves(int p, int q, int* e, int *d, int *n){
	int phi, e, g;
	
	if (esPrimo(p) && esPrimo(q) && (p != q)){
		//n = pq
		n = p * q;
		//Phi is the totient of n
		phi = (p - 1) * (q - 1);
		//Choose an integer e such that e and phi(n) are coprime
		e = random(1, phi);
		//Use Euclid's Algorithm to verify that e and phi(n) are comprime
		g = gcd(e, phi);
		while (g != 1){
			e = random(1, phi);
			g = gcd(e, phi);
		}
		//Use Extended Euclid's Algorithm to generate the private key
		d = gcd_extendido(e, phi);

		//Return public and private keypair
		//Public key is(e, n) and private key is(d, n)
		//((e, n), (d, n));
	}
	return NULL;
}

int* encrypt(pk, plaintext){
	//Unpack the key into it's components
	key, n = pk
	//Convert each letter in the plaintext to numbers based on the character using a^b mod m
		cipher = [(ord(char) ** key) % n for char in plaintext]
	// Return the array of bytes
	return cipher
}