#include "UsersBinaryTree.h"




//
TreeNode* UsersBinaryTree::Search(string s)
{
	return SearchUsername(root, s);
}

TreeNode* UsersBinaryTree::SearchUsername(TreeNode* raizSub, string buscado)
{
	if (raizSub == NULL)
		return NULL;
	else if (buscado == raizSub->username)
		return raizSub;
	else if (buscado.length() < raizSub->GetLenght())
		return SearchUsername(raizSub->left, buscado);
	else
		return SearchUsername(raizSub->right, buscado);
}


void UsersBinaryTree::Insert(string valor)
{
	root = Insert(root, valor);
}


TreeNode* UsersBinaryTree::Insert(TreeNode* raizSub, string dato)
{
	if (raizSub == NULL)
		raizSub = new TreeNode(dato.length(), dato);
	else {
		if (Search(dato) == NULL) //verifica que no este repetido
		{
			
			//Convierte el nombre de usuario a un arreglo de char
			char* dataTemp = new char[dato.length() + 1];
			memcpy(dataTemp, dato.c_str(), dato.length() + 1);


			//Convierte el nombre de la raiz a un arreglo de char
			
			char* rootTemp = new char[ raizSub->username.length() + 1];
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
	}// tratamiento de repetición
	return raizSub;

	

}

void UsersBinaryTree::InOrder(TreeNode* n)
{
	if (n != NULL)
	{
		InOrder( n->left);

		std::cout << n->username<< " " << n->lenght;
		
		InOrder(n->right);
	}
}

TreeNode* UsersBinaryTree::GetRoot()
{
	return root;
}


void UsersBinaryTree::Print()
{
	root->Print();
}




