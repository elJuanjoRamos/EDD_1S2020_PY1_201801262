#include <string>
#include <iostream>
#include "TreeNode.h";
using namespace std;
class UsersBinaryTree
{
public:
	TreeNode* root = NULL;
	int size;
public:
	void Insert(string n);
	int getSize();
	TreeNode* Insert(TreeNode* a, string n);
	TreeNode* Search(string n);
	TreeNode* SearchUsername(TreeNode* root, string n);
	TreeNode* SearchID(TreeNode* raizSub, int index);
	TreeNode* GetRoot();
	void InOrder(TreeNode* root);
	void Print();
};

