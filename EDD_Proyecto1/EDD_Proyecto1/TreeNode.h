#include <string>
#include <fstream>
using namespace std;
class TreeNode
{
public:
	int lenght;
	int index;
	static int correlative;
	string username;
	TreeNode* left, * right;
public:
	TreeNode();
	TreeNode(int l, string s);
	int GetLenght();
	void Print();
	string GetBody();
};

