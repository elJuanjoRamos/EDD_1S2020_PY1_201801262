#include <string>
using namespace std;
class ScoreBoardNode
{
public:
	int points;
	string username;
	ScoreBoardNode* next;
	ScoreBoardNode(int p, string n);
	ScoreBoardNode();


};

