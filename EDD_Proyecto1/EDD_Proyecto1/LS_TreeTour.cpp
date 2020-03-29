#include "LS_TreeTour.h"

void LS_TreeTour::Insert(int index, string name) {

    Node* nuevo = new Node(index, name);

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
void LS_TreeTour::Print(string name) {
	
	string archivoCabeza = "digraph G {rankdir=LR;"
		"label=\"" + name + "\";node[shape=box];\n";

	string nodos;
	string juntarNodos;

	ofstream ofs("ArbolRecorrido.dot", ofstream::out);

	Node* aux = first;
	Node* ant = NULL;
	string texto = "";
	int contador = 1;

	while (aux != NULL)
	{
		nodos = nodos + "nodo" + to_string(aux->index) + " [ label =\"" + to_string(aux->index) + " - " + aux->name + "\"];\n";
		contador++;
		ant = aux;
		aux = aux->next;
		if (aux != NULL)
		{
			juntarNodos = juntarNodos + "nodo" + to_string(ant->index) + "-> nodo" + to_string(aux->index) + "\n";
		}
	}
	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "}";
	//std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o ArbolRecorrido.png ArbolRecorrido.dot");
	system("ArbolRecorrido.png");
}

void LS_TreeTour::Clear() {
	first = NULL;
}