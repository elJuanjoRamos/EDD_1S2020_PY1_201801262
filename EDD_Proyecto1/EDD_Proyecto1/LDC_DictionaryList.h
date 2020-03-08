#include "DictionaryNode.h";

class LDC_DiccionaryList
{
public:
	DictionaryNode* first, * last = NULL;
	void Insert(string word);
	void Print();
	LDC_DiccionaryList();

};