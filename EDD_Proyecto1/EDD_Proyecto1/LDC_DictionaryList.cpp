#include "LDC_DictionaryList.h"
#include <fstream>

LDC_DiccionaryList::LDC_DiccionaryList(){}


void LDC_DiccionaryList::Insert(string word) {
	DictionaryNode* nuevo;

	nuevo = new DictionaryNode(word);
	if (first == NULL) {
		first = nuevo;
		first->next = NULL;
		first->ant = NULL;
		first->next = first;
		last = first;
	}
	else {
		last->next = nuevo;
		nuevo->next = first;
		nuevo->ant = last;
		last = nuevo;

	}
}

void LDC_DiccionaryList::Print() {
	string archivoCabeza = "digraph G {rankdir=LR\n"
		"node[shape = box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs("Dictionary_ListaDobleCircular.dot", ofstream::out);

	DictionaryNode* aux = first->next;
	string texto = "";
	int contador = 0;

	while (aux != first)
	{
		nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + aux->word + '"' + "];\n";
		aux = aux->next;
		contador++;
	}

	for (size_t i = 0; i < contador - 1; i++)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1) + ";\nNodo" + to_string(i + 1) + "->Nodo" + to_string(i) + ";\n";
	}

	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "Nodo0->Nodo" + to_string(contador-1) + "\nNodo"+to_string(contador - 1)+"->Nodo0" + "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o Dictionary_ListaDobleCircular.png Dictionary_ListaDobleCircular.dot");
	system("Dictionary_ListaDobleCircular.png");
}