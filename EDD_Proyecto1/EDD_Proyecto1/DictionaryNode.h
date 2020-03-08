#include <string>
using namespace std;
class DictionaryNode
{
public:
	string word;
	DictionaryNode* ant, *next;
	DictionaryNode();
	DictionaryNode(string w);

};

