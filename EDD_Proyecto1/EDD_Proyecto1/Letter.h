#pragma once
#include <iostream>
#include <string>
using namespace std;
class Letter
{
public:
	string letter;
	int points;
	int cant;
	Letter();
	Letter(string l, int p, int c);
};
