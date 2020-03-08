#include <string>
#include <iostream>
#include "TreeNode.h";
using namespace std;
class UsersBinaryTree
{
public:
	TreeNode* root = NULL;
public:
	void Insert(string n);
	TreeNode* Insert(TreeNode* a, string n);
	TreeNode* Search(string n);
	TreeNode* SearchUsername(TreeNode* root, string n);
	TreeNode* GetRoot();
	void InOrder(TreeNode* root);
	void Print();
};

