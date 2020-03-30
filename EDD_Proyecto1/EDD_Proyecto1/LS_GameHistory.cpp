#include "LS_GameHistory.h"

void LS_GameHistory::Insert(string w, string l, int pw, int pl) {

	Node* nuevo = new Node(w, l, pw, pl);

	if (first == NULL) {
		first = nuevo;
	}
	else {
		Node* reco = first;

		while (reco->next != NULL) {
			reco = reco->next;
		}
		reco->next = nuevo;

	}
}
void LS_GameHistory::Print() {
	string name = "Historial de partidas";
	string archivoCabeza = "digraph G {"
		"graph[label=\"" + name + "\", labelloc=t, fontsize=20]\nnode[shape = box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs("HistorialPartidas.dot", ofstream::out);

	Node* aux = first;
	Node* ant = NULL;
	string texto = "";
	int contador = 0;

	while (aux != NULL)
	{
		nodos = nodos + "nodo" + to_string(contador) + " [ label =\"" + "Ganador: " + aux->winner + " - Puntos: " + to_string(aux->pointsWinner) + "\\l Perdedor: " + aux->loser + " - Puntos: " + to_string(aux->pointsLoser) + "\"];\n";
		ant = aux;
		int i = contador;
		contador++; 
		aux = aux->next;
		if (aux != NULL)
		{
			juntarNodos = juntarNodos + "nodo" + to_string(i) + "-> nodo" + to_string(contador) + "\n";
		}
		
	}
	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o HistorialPartidas.png HistorialPartidas.dot");
	system("HistorialPartidas.png");
}

void LS_GameHistory::Clear() {
	first = NULL;
}