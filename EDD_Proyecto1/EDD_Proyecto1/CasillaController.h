#include "CasillaNode.h";
#include <string>
#include <iostream>
#include <fstream>      // std::ifstream
#include <typeinfo>
#include <vector> 
class CasillaController
{
private:
	static CasillaController* instance;
	CasillaController();

	vector<CasillaNode> doubleList;
	vector<CasillaNode> tripleList;
	//CasillaNode doubleList[100];
	//CasillaNode tripleList[100];


public:
	static CasillaController* getInstance();
	void Insert(int x, int y, bool d, bool t);	
	void Show();
	void Clear();
	bool getCasillaDoble(int x, int y);
	bool getCasillaTriple(int x, int y);
};

