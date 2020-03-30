#include <string>
#include <fstream>
using namespace std;
class LS_GameHistory
{
	class Node
	{
	public:
		string winner;
		string loser;
		int pointsWinner;
		int pointsLoser;
		Node* next;
		Node(string w, string l, int pw, int pl) {
			winner = w;
			loser = l;
			pointsWinner = pw;
			pointsLoser = pl;
			next = NULL;
		}
	};
public:
	Node* first;
	void Insert(string w, string l, int pw, int pl);
	void Print();
	void Clear();
};

