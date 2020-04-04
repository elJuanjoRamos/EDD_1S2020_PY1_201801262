#include "Queue_GameChip.h"
#include <fstream>
#include <string>
using namespace std;
//Constructor
Queue_GameChip::Queue_GameChip()
{
	first = last = NULL;
}

//INSERT METHOD
void Queue_GameChip::Push(string l, int p, int c)
{
	GameChipNode* newNode = new GameChipNode(l,p,c);
	if (IsEmpty())
	{
		first = newNode;
	}
	else
	{
		last->next = newNode;
	}
	last = newNode;
}

//POP METHOD
GameChipNode* Queue_GameChip::Pop()
{
	if (IsEmpty()) {
		throw "Cola vacía, no se puede extraer.";
	}
	else {
		GameChipNode* aux = first;
		GameChipNode* a = first;
		first = first->next;
		return aux;
	}
}

//FRONT METHOD: retorna el elementod el frente
GameChipNode* Queue_GameChip::Front() const
{
	if (IsEmpty())
		throw "Cola vacía";
	return first;
}
//DELETE: borra la cola
void Queue_GameChip::DeleteQueue()
{
	
	while (first != NULL)
	{
		GameChipNode* a;
		a = first;
		first = first->next;
		delete a;
	}
	last = NULL;
}
//IsEmpty: verifica si la cola esta vacia
bool Queue_GameChip::IsEmpty() const
{
	return first == NULL;
}

//Print: Imprime las letras
void Queue_GameChip::Print() {

	string name = "Fichas de Juego";
	string archivoCabeza = "digraph G {rankdir=LR\n"
		"graph[label=\"" + name + "\", labelloc=t, fontsize=20]\nnode[shape = box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs("Queue_GameChip.dot", ofstream::out);

	GameChipNode* aux = first;
	string texto = "";
	int contador = 0;

	while (aux != NULL)
	{
		if (aux->letter == "Ñ") {
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + "Letra: Ñ" + string("\\lPuntos:") + to_string(aux->points) + '"' + "];\n";
		}
		else {
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + "Letra:" + aux->letter + string("\\lPuntos:") + to_string(aux->points) + '"' + "];\n";
		}

		aux = aux->next;
		contador++;
	}

	for (size_t i = contador - 1; i >0 ; i--)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i - 1) + ";\n";
	}

	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o Queue_GameChip.png Queue_GameChip.dot");
	system("Queue_GameChip.png");


}