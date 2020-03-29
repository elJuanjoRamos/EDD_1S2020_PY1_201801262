#include <string>
#include <iostream>
#include "TreeNode.h";
#include "LS_TreeTour.h";
using namespace std;
class UsersBinaryTree
{
public:
	TreeNode* root = NULL;
	LS_TreeTour inorden;
	LS_TreeTour posorden;
	LS_TreeTour preorden;
	int size;
public:
	void Insert(string n);
	int getSize();
	TreeNode* Insert(TreeNode* a, string n);
	TreeNode* Search(string n);
	TreeNode* SearchUsername(TreeNode* root, string n);
	TreeNode* SearchID(TreeNode* raizSub, int index);
	TreeNode* GetRoot();
	void PreOrder(TreeNode* root);
	void InOrder(TreeNode* root);
	void PostOrder(TreeNode* root);
	void Print(string type);
};

