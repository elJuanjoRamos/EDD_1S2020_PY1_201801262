#include <iostream>
using namespace std;
class GameChipNode
{
public:
	GameChipNode* next;
	char letter;
	int points;
	int cant;
	GameChipNode(char l, int p, int c);
};

