#include "LD_LetterPlayer.h"
#include <iostream>
#include <fstream>
using namespace std;

LD_LetterPlayer::LD_LetterPlayer()
{
}

void LD_LetterPlayer::Add(char c)
{
	LetterPlayer* letterP;

	letterP = new LetterPlayer(c);
	if (first == NULL) {
		first = letterP;
		first->next = NULL;
		first->previous = NULL;
		last = first;
	}
	else {
		last->next = letterP;
		letterP->next = NULL;
		letterP->previous = last;
		last = letterP;
	}
}

LetterPlayer* LD_LetterPlayer::Search(char search)
{
	LetterPlayer* actual = new LetterPlayer();
	actual = first;
	while (actual != NULL)
	{
		if (actual->letter == search) {
			return actual;
		}
		actual = actual->next;
	}
	return NULL;
}

void LD_LetterPlayer::Clean()
{
	first = NULL;
}

void LD_LetterPlayer::Show()
{
	LetterPlayer* actual = new LetterPlayer();
	actual = first;
	if (first != NULL)
	{
		cout << "LETRAS: ";
		while (actual != NULL)
		{
			cout << actual->letter << ", ";
			actual = actual->next;
		}
		cout << "\n";
	}
	else {
		std::cout << "vacia";
	}
}

char LD_LetterPlayer::Eliminar(char search) {
	LetterPlayer* actual = new LetterPlayer();
	actual = first;
	LetterPlayer* anterior = new LetterPlayer();
	anterior = NULL;
	bool encontrado = false;
	if (actual != NULL) {

		while (actual != NULL && encontrado != true) {

			if (actual->letter == search) {

				if (actual == first) {
					first = first->next;
					first->previous = NULL;
				}
				else if (actual == last) {
					anterior->next = NULL;
					last = anterior;
				}
				else {
					anterior->next = actual->next;
					actual->next->previous = anterior;
				}
				encontrado = true;
			}
			anterior = actual;
			actual = actual->next;
		}
	}
	return search;
}

void LD_LetterPlayer::Print() {
	string archivoCabeza = "digraph G {"
		"node[shape = box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs("LD_LetterPlayer.dot", ofstream::out);

	LetterPlayer* aux = first;
	string texto = "";
	int contador = 0;

	while (aux != NULL)
	{
		if (aux->letter == 'Ñ') {
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + "Ñ" + '"' + "];\n";
		}
		else {
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + aux->letter + '"' + "];\n";
		}
		aux = aux->next;
		contador++;
	}

	for (size_t i = 0; i < contador - 1; i++)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1) + ";\nNodo" + to_string(i + 1) + "->Nodo" + to_string(i) + ";\n";
	}
	texto = archivoCabeza + nodos + juntarNodos + "}";
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o LD_LetterPlayer.png LD_LetterPlayer.dot");
	system("LD_LetterPlayer.png");
}