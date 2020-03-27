#include "ScoreBoardList.h"
#include <fstream>

void ScoreBoardList::Insert(int points, string username) {
    ScoreBoardNode* nuevo = new ScoreBoardNode();

    nuevo->points = points;
    nuevo->username = username;

    if (first == NULL) {
        first = nuevo;
    }
    else {
        if (points < first->points) {
            
            nuevo->next = first;
            first = nuevo;
        }
        else {
            ScoreBoardNode* reco = first;
            ScoreBoardNode* ant = first;

            while (points >= reco->points && reco->next != NULL) {
                ant = reco;
                reco = reco->next;
            }
            if (points >= reco->points) {
                reco->next = nuevo;
            }
            else {
                nuevo->next = reco;
                ant->next = nuevo;
            }
        }
    }
}

void ScoreBoardList::Print(string user) {
	string archivoCabeza = "digraph G {rankdir=LR;"
		"node[shape = box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs("ScoreBoard.dot", ofstream::out);

	ScoreBoardNode* aux = first;
	string texto = "";
	int contador = 0;

	while (aux != NULL)
	{
		if (user != "ALL")
		{
			if (aux->username == user)
			{
				nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + " Jugador: " + aux->username + string("\\lPuntos: ") + to_string(aux->points) + '"' + "];\n";
				contador++;
			}
		}
		else {
			nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + "Jugador: " + aux->username + string("\\l") + to_string(aux->points) + '"' + "];\n";
			contador++;

		}
		aux = aux->next;
	}

	for (size_t i = contador - 1; i > 0; i--)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i - 1) + ";\n";
	}

	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o ScoreBoard.png ScoreBoard.dot");
	system("ScoreBoard.png");
}

