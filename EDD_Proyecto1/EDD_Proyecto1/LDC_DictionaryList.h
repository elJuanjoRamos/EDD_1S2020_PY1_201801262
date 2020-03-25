#include "DictionaryNode.h";

class LDC_DiccionaryList
{
public:
	DictionaryNode* first, * last = NULL;
	void Insert(string word);
	DictionaryNode* search(string letra);
	void Print();
	void Convert(string& s);
	LDC_DiccionaryList();

};