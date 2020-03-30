#include "DictionaryNode.h";

class LDC_DiccionaryList
{
public:
	DictionaryNode* first, * last = NULL;
	void Insert(string word);
	DictionaryNode* search(string letra);
	void Print();
	void ShowPrint();
	void Convert(string& s);
	void Delete(string word);
	bool IsEmpty();
	LDC_DiccionaryList();

};