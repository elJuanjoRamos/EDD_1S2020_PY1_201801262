#include "GameChipNode.h";
#include "string.h";
using namespace std;

class Queue_GameChip
{
public: 
	GameChipNode* first, * last;
	Queue_GameChip();
	void Push(string l, int p, int c);
	void DeleteQueue();
	void Print();
	GameChipNode* Pop();
	GameChipNode* Front()const;
	bool IsEmpty() const;
};

