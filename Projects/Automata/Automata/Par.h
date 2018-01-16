#ifndef _PAR_H_
#define _PAR_H_

#include <iostream>

using namespace std;

class Par
{
private:
	string a, b;
public:
	Par();
	void setA(string a);
	void setB(string b);
	string getA();
	string getB();
	~Par();
};

#endif