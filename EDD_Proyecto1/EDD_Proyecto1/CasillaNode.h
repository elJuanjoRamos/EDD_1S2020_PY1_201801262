#pragma once
#include <string>
#include <iostream>
using namespace std;
class CasillaNode
{
public:
	int x;
	int y;
	bool sdouble;
	bool striple;
	bool isEmpty = true;
	CasillaNode();
	void setData(int x, int y, bool isd, bool ist);
	bool getData();
	int getX();
	int getY();
	void toString();
};

