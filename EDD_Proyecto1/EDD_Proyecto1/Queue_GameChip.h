#include "GameChipNode.h";

class Queue_GameChip
{
public: 
	GameChipNode* first, * last;
	Queue_GameChip();
	void Push(char l, int p, int c);
	void DeleteQueue();
	void Print();
	GameChipNode* Pop();
	GameChipNode* Front()const;
	bool IsEmpty() const;
};

