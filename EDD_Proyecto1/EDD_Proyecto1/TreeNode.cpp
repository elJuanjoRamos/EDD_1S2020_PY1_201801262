#include "TreeNode.h"

int TreeNode::correlative = 1;

TreeNode::TreeNode()
{
}

TreeNode::TreeNode(int l, string n) {
	this->lenght = l;
	this->username = n;
	this->index = correlative++;
	this->left = this->right = NULL;
}

int TreeNode::GetLenght() {
	return lenght;
}

void TreeNode::Print()
{
	string name = "Arbol de usuarios";
	
	string nodos;
	string juntarNodos;
	string masNodos;

	ofstream ofs("ArbolBinarioBusqueda.dot", ofstream::out);


	string texto = "";


	texto = "digraph grafica{\n" + string("rankdir=TB;") + "graph[label=\"" + name + "\", labelloc=t, fontsize=20]\n" + "node [shape = record, style=filled, fillcolor=white];\n"+ GetBody() + "}";
	
	
	ofs << texto;
	ofs.close();
	system("dot -Tjpg -o ArbolBinarioBusqueda.png ArbolBinarioBusqueda.dot");
	system("ArbolBinarioBusqueda.png");
}


string TreeNode::GetBody() {
	string etiqueta;
	if (left == NULL && right == NULL)
	{
		etiqueta = "nodo" + to_string(index) + " [ label =\"" + to_string(index) + " - " + username + "\"];\n";
	}
	else
	{
		etiqueta = "nodo" + to_string(index) + "[ label =\"" + to_string(index) + " - " + username + "\"];\n";
	}
	if (left != NULL)
	{
		etiqueta = etiqueta + left->GetBody() +
			"nodo" + to_string(index) + "->nodo" + to_string(left->index) + "\n";
	}
	if (right != NULL)
	{
		etiqueta = etiqueta + right->GetBody() +
			"nodo" + to_string(index) + "->nodo" + to_string(right->index) + "\n";
	}
	return etiqueta;
}

