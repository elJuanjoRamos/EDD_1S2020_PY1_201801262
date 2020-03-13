#include <string>
using namespace std;
class MatrixNode
{
public:
	MatrixNode* next, * before, * up, * down;
	string data;
	bool isDouble;
	bool isTriple;
	int x, y, index;
	static int correlative;
public:
	MatrixNode(string d, int x, int y, bool isd, bool ist);
	MatrixNode();
};

