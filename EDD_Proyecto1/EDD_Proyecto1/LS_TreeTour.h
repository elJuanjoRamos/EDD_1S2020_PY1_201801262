#include <string>
#include <fstream>

using namespace std;
class LS_TreeTour
{
public:

	class Node
	{
	public:
		string name;
		int index;
		Node* next;
		Node(int i, string s) {
			name = s;
			index = i;
			next = NULL;
		}
	};
	Node* first;
	void Insert(int index, string name);
	void Print(string name);
	void Clear();
};

