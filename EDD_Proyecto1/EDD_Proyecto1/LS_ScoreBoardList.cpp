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

void ScoreBoardList::Print() {

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
		
		nodos = nodos + "Nodo" + to_string(contador) + " [label = " + '"' + aux->username + string("\\l") + to_string(aux->points) + '"' + "];\n";

		aux = aux->next;
		contador++;
	}

	for (size_t i = 0; i < contador - 1; i++)
	{
		juntarNodos = juntarNodos + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1) + ";\n";
	}

	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o ScoreBoard.png ScoreBoard.dot");
	system("ScoreBoard.png");



}