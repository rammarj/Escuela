#pragma once
#include <iostream>

using namespace std;

class Token
{
public:
	Token();
	void load(string file_name);
	~Token();
};

