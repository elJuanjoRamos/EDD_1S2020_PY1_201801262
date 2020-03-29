#include "UsersBinaryTree.h"




//
TreeNode* UsersBinaryTree::Search(string s)
{
	return SearchUsername(root, s);
}

TreeNode* UsersBinaryTree::SearchUsername(TreeNode* raizSub, string buscado)
{

	if (raizSub == NULL) {
		return NULL;
	}
	else {


		//Convierte el nombre de usuario a un arreglo de char
		char* dataTemp = new char[buscado.length() + 1];
		memcpy(dataTemp, buscado.c_str(), buscado.length() + 1);


		//Convierte el nombre de la raiz a un arreglo de char

		char* rootTemp = new char[raizSub->username.length() + 1];
		memcpy(rootTemp, raizSub->username.c_str(), raizSub->username.length() + 1);


		if (buscado == raizSub->username)
			return raizSub;
		else if (strcmp(dataTemp, rootTemp) < 0)
			return SearchUsername(raizSub->left, buscado);
		else
			return SearchUsername(raizSub->right, buscado);
	}
}

void UsersBinaryTree::Insert(string valor)
{
	root = Insert(root, valor);
	size++;
}

int UsersBinaryTree::getSize()
{
	return size;
}


TreeNode* UsersBinaryTree::Insert(TreeNode* raizSub, string dato)
{
	if (raizSub == NULL) {
		raizSub = new TreeNode(dato.length(), dato);
	}
	else {
		
		//Convierte el nombre de usuario a un arreglo de char
		char* dataTemp = new char[dato.length() + 1];
		memcpy(dataTemp, dato.c_str(), dato.length() + 1);


		//Convierte el nombre de la raiz a un arreglo de char

		char* rootTemp = new char[raizSub->username.length() + 1];
		memcpy(rootTemp, raizSub->username.c_str(), raizSub->username.length() + 1);


		if (strcmp(dataTemp, rootTemp) < 0) //verifica el tama;o de las letras, si es mayor se va a la izquierda, si no a la derecha
		{
			TreeNode* iz;
			iz = Insert(raizSub->left, dato);
			raizSub->left = iz;
		}
		else if (strcmp(dataTemp, rootTemp) >= 0) {
			TreeNode* dr;
			dr = Insert(raizSub->right, dato);
			raizSub->right = dr;
		}
	}
	
	return raizSub;
}

void UsersBinaryTree::InOrder(TreeNode* n)
{
	if (n != NULL)
	{
		InOrder( n->left);
		inorden.Insert(n->index, n->username);
		InOrder(n->right);
	}
}
void UsersBinaryTree::PreOrder(TreeNode* n)
{
	if (n != NULL) {
		preorden.Insert(n->index, n->username);
		PreOrder(n->left);
		PreOrder(n->right);
	}
}
void UsersBinaryTree::PostOrder(TreeNode* n)
{
	if (n != NULL) {
		PostOrder(n->left);
		PostOrder(n->right);
		posorden.Insert(n->index, n->username);
	}
}

TreeNode* UsersBinaryTree::GetRoot()
{
	return root;
}


void UsersBinaryTree::Print(string type)
{
	if (type == "all")
	{
		root->Print();
	}
	else
	{
		TreeNode* temp = root;
		if (type == "inorden")
		{
			InOrder(temp);
			inorden.Print("InOrden: Iqz, Raiz, Der");
			inorden.Clear();
		}
		else if (type == "preorden")
		{
			PreOrder(temp);
			preorden.Print("PreOren: Raiz, Izq, Der");
			preorden.Clear();
		}
		else if (type == "postorden")
		{
			PostOrder(temp);
			posorden.Print("PosOrden: Izq, Der, Raiz");
			posorden.Clear();
		}
		
	}

	

}




