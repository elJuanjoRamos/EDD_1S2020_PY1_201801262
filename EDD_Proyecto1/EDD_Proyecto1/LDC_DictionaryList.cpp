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

void LDC_DiccionaryList::Convert(string& s) {
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = towlower(s[i]);
	}
}

DictionaryNode* LDC_DiccionaryList::search(string search) {
	DictionaryNode* p;
		p = last->next;
		do {
			string temp = p->word;
			Convert(search);
			Convert(temp);
			if (temp == search)
			{
				return p;
			}
			else {
				p = p->next;
			}
		} while (p != first);
		return NULL;
}

void LDC_DiccionaryList::Delete(string word) {
	DictionaryNode* actual = first;
	DictionaryNode* ant = NULL;
	if (!IsEmpty())
	{
		do
		{
			string temp = actual->word;
			Convert(word);
			Convert(temp);

			if (temp == word)
			{
				if (actual == first)
				{
					if (actual->next == actual)
					{
						first = last = actual = NULL;
						break;
					}
					else
					{
						first = first->next;
						first->ant = last;
						last->next = first;
					}
					
				}
				else if (actual == last)
				{
					last = ant;
					last->next = first;
					first->ant = last;
				}
				else
				{
					ant->next = actual->next;
					actual->next->ant = ant;
				}
				break;
			}
			else
			{
				ant = actual;
				actual = actual->next;

			}
			
		} while (actual != first);
	}
}

bool LDC_DiccionaryList::IsEmpty() {
	return first == NULL;
}
void LDC_DiccionaryList::Print() {
	string name = "Diccionario de juego";
	string archivoCabeza = "digraph G {rankdir=LR\n"
		"graph[label=\"" + name + "\", labelloc=t, fontsize=20]\nnode[shape = box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs("Dictionary_ListaDobleCircular.dot", ofstream::out);

	DictionaryNode* aux = first;
	string texto = "";
	int contador = 0;

	do
	{
		nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + aux->word + '"' + "];\n";
		aux = aux->next;
		contador++;
	} while (aux != first);
	

	for (size_t i = 0; i < contador - 1; i++)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1) + "[dir=both];\n" ;
	}

	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "Nodo0->Nodo" + to_string(contador-1) + "[dir=both]\n"+ "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o Dictionary_ListaDobleCircular.png Dictionary_ListaDobleCircular.dot");
}

void LDC_DiccionaryList::ShowPrint() {
	system("Dictionary_ListaDobleCircular.png");
}