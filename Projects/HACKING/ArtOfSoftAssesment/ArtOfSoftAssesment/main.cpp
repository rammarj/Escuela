#include <iostream>
#include <conio.h>
#define BLOB_MAX 1024
using namespace std;

int main(){
	/*int jim = -5;
	unsigned int a = jim;
	if (jim < sizeof (int))
		cout<<"hola mundo!"<<endl;
	else
		cout<<"WTF!"<<endl;
	cout << a << endl;*/
	
	/*int a = 99999;
	cout <<"int: "<<a<<", short: "<< (short)a << endl;
	*/

	/*signed int a = -10;
	unsigned int n = a;
	cout << n << endl;
	_getch();
	if (n<0 || n> 1024)
		return 1;
	cout << (int)n << endl;*/
	
	//cout << sizeof("65535") << endl;

	/*if (-1)
		cout << "im here" << endl;
	else
		cout << "im NOT here" << endl;*/

	int bloblen = 0xfffffffd;
	int a = 1;
	unsigned int pktlen = 1024;
	if (bloblen + sizeof(long) > pktlen || bloblen > BLOB_MAX)
		cout << "nada..." << endl;
	cout << "succes!!" << (bloblen &0xff)<< endl;
	_getch();
	
	return 0;
}