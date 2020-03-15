#include "CasillaNode.h";
#include <string>
#include <iostream>
#include <fstream>      // std::ifstream
#include <typeinfo>

class CasillaController
{
private:
	static CasillaController* instance;
	CasillaController();
	CasillaNode doubleList[100];
	CasillaNode tripleList[100];

public:
	static CasillaController* getInstance();
	void Insert(int x, int y, bool d, bool t);
	void Show();
};

