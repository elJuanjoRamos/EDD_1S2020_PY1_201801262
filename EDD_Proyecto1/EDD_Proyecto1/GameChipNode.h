#include <iostream>
using namespace std;
class GameChipNode
{
public:
	GameChipNode* next;
	string letter;
	int points;
	int cant;
	GameChipNode(string l, int p, int c);
};

