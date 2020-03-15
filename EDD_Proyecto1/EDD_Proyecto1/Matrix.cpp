#include "Matrix.h"
#include <fstream>
#include <iostream>


void Matrix::InsertElement(int x, int y, string data, bool isDouble, bool isTriple) {
	MatrixNode* column = this->SearchColumn(x);
	MatrixNode* row = this->SearchRow(y);
	
	/*CASO 1: COLUMNA Y FILA NO EXISTEN */
	if (column == 0 && row == 0)
	{
		column = this->CreateColumn(x);
		row = this->CreateRow(y);
		MatrixNode* new_node = new MatrixNode(data, x, y, isDouble, isTriple);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
	//*CASO 2: COLUMNA NO EXISTE, FILA EXISTE*/
	if (column == 0 && row != 0)
	{

		column = this->CreateColumn(x);
		MatrixNode* new_node = new MatrixNode(data, x, y, isDouble, isTriple);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
	/*CASO 3: COLUMNA EXISTE, FILA NO EXISTE*/
	if (column != 0 && row == 0)
	{
		row = this->CreateRow(y);
		MatrixNode* new_node = new MatrixNode(data, x, y, isDouble, isTriple);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
	/*CASO 4: COLUMNA Y FILA EXISTEN*/
	if (column != 0 && row != 0)
	{
		MatrixNode* new_node = new MatrixNode(data, x, y, isDouble, isTriple);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
}


MatrixNode* Matrix::CreateColumn(int x) {
	MatrixNode* nuevo = new MatrixNode("X=" + to_string(x), x, -1, false, false);
	MatrixNode* temp = root;
	/*lastRight->next = col;
	col->next = NULL;
	col->before = lastRight;
	lastRight = col;*/


	
	if (x < root->x) {

		nuevo->next = root;
		root->before = nuevo;
		root = nuevo;
	}
	else {
		MatrixNode* reco = root;
		MatrixNode* ant = root;

		while (x >= reco->x && reco->next != NULL) {
			ant = reco;
			reco = reco->next;
		}
		if (x >= reco->x) {
			reco->next = nuevo;
			nuevo->before = reco;
		}
		else {
			nuevo->next = reco;
			reco->before = nuevo;
			ant->next = nuevo;
			nuevo->before = ant;
		}
	}



	return nuevo;
}

MatrixNode* Matrix::CreateRow(int y) {
	MatrixNode* nuevo = new MatrixNode("Y=" + to_string(y), -1, y, false, false);
	


	if (y < root->y) {

		nuevo->next = root;
		root = nuevo;
	}
	else {
		MatrixNode* reco = root;
		MatrixNode* ant = root;

		while (y >= reco->x && reco->down != NULL) {
			ant = reco;
			reco = reco->down;
		}
		if (y >= reco->y) {
			reco->down = nuevo;
			nuevo->up = reco;
		}
		else {
			nuevo->down = reco;
			reco->up = nuevo;
			ant->down = nuevo;
			nuevo->up = ant;
			
		}
	}

	/*lastDown->down = col;
	col->down = NULL;
	col->up = lastDown;
	lastDown = col;*/
	


	return nuevo;
}

MatrixNode* Matrix::SearchColumn(int x) {
	MatrixNode* temp = root;

	while (temp != NULL)
	{
		if (temp->x == x)
		{
			return temp;
			break;
		}
		temp = temp->next;
	}

	return NULL;
}


MatrixNode* Matrix::SearchRow(int y) {
	MatrixNode* temp = root;
	while (temp != NULL)
	{
		if (temp->y == y)
		{
			return temp;
			break;
		}
		temp = temp->down;
	}
	return NULL;
}



MatrixNode* Matrix::InsertColumn(MatrixNode* new_node, MatrixNode* root) {
	MatrixNode* reco = root;
	MatrixNode* ant = root;

	while (new_node->y >= reco->y && reco->down != NULL) {

		ant = reco;
		reco = reco->down;

	}
	if (new_node->y >= reco->y) {
		reco->down = new_node;
		new_node->up = reco;
		new_node->down = NULL;
	}
	else {
		new_node->down = reco;
		reco->up = new_node;
		ant->down = new_node;
		new_node->up = ant;
		ant = new_node;
	}
	
	/*while (new_node->x >= reco->x && reco->down != NULL) {
	
		ant = reco;
		reco = reco->down;
	
	}
	if (new_node->x >= reco->x) {
		reco->down = new_node;
		new_node->up = reco;
		new_node->down = NULL;
	}
	else {
		new_node->down = reco;
		reco->up = new_node;
		ant->down = new_node;
		new_node->up = ant;
	}*/


	return new_node;
}




MatrixNode* Matrix::InsertRow(MatrixNode* new_node, MatrixNode* root) {
	MatrixNode* reco = root;
	MatrixNode* ant = root;


	while (new_node->x >= reco->x && reco->next != NULL) {
		ant = reco;
		reco = reco->next;
	}
	if (new_node->x >= reco->x) {
		reco->next = new_node;
		new_node->before = reco;
	}
	else {
		new_node->next = reco;
		reco->before = new_node;
		ant->next = new_node;
		new_node->before = ant;
	}

	/*while (new_node->y >= reco->y && reco->next != NULL) {
		ant = reco;
		reco = reco->next;
	}
	if (new_node->y >= reco->y) {
		reco->next = new_node;
		new_node->before = reco;
	}
	else {
		new_node->next = reco;
		reco->before = new_node;
		ant->next = new_node;
		new_node->before = ant;
	}*/
	return new_node;
}




void Matrix::print_headers() {

}


void Matrix::print_x_header(MatrixNode* cabezaY, int x) {
	nodosy = nodosy + "Nodox" + to_string(x) + "->Nodoy" + to_string(cabezaY->index) + "[dir=both]\n";
	while (cabezaY != NULL)
	{
		if (cabezaY->down != NULL)
		{
			nodosy = nodosy +  "Nodoy" + to_string(cabezaY->index) + "->Nodoy" + to_string(cabezaY->down->index) + "[dir=both];\n";
		}
		cabezaY = cabezaY->down;

	}
	
	/*nodos = nodos + "Nodox" + to_string(x) + "->Nodoy" + to_string(cabezaY->index) + "[dir=both]\n";
	while (cabezaY != NULL)
	{
		if (cabezaY->down != NULL)
		{
			nodos = nodos + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + cabezaY->data + '"' + "];\n"
				+ "Nodoy" + to_string(cabezaY->index) + "->Nodoy" + to_string(cabezaY->down->index) + "[dir=both];\n";
		}
		else
		{
			nodos = nodos + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + cabezaY->data + '"' + "];\n";
		}
		cabezaY = cabezaY->down;

	}*/
}
void Matrix::print_y_header(MatrixNode* cabezaX, int index) {
	nodos = nodos + "Nodoy" + to_string(index) + "->Nodoy" + to_string(cabezaX->index) + "[constraint=false, dir=both];\n";
	while (cabezaX != NULL)
	{
		if (cabezaX->next != NULL)
		{
			nodos = nodos + "Nodoy" + to_string(cabezaX->index) + "->Nodoy" + to_string(cabezaX->next->index) + "[constraint=false, dir=both];\n";

		}
		cabezaX = cabezaX->next;
	}

	/*nodos = nodos + "Nodoy" + to_string(index) + "->Nodoy" + to_string(cabezaX->index) + "[constraint=false, dir=both]\n";

	while (cabezaX != NULL)
	{
		if (cabezaX->next != NULL)
		{
			nodos = nodos + "Nodoy" + to_string(cabezaX->index) + " [label = " + '"' + cabezaX->data + '"' + "];\n" +
				+"Nodoy" + to_string(cabezaX->index) + "->Nodoy" + to_string(cabezaX->next->index) + "[constraint=false, dir=both];\n";

			//nodos =  nodos + "Nodoy" + to_string(cabezaX->index) + "->Nodoy" + to_string(cabezaX->next->index) + "[constraint=false, dir=both];\n";
		}
		else {
			nodos = nodos + "Nodoy" + to_string(cabezaX->index) + " [label = " + '"' + cabezaX->data + '"' + "];\n";
		}
		cabezaX = cabezaX->next;
	}*/

}
void Matrix::print_nodes_x() {

}
void Matrix::print_nodes_y() {

}


void Matrix::Print() {
	ofstream ofs("Matrix.dot", ofstream::out);

	/*
	string archivoCabeza = "digraph G {rankdir = TB;\n node[shape = rectangle, height = 0.5, width = 0.5]; \ngraph[nodesep = 0.5]; ";

	//nodos = "Nodo0 [label=\"Y\\X\"];\n";


	MatrixNode* cabezaX = root->next;
	MatrixNode* cabezaY = root->down;
	MatrixNode* aux = root;

	string juntarNodos = "Nodo0->Nodox" + to_string(root->next->index) + "[constraint=false, dir=both];\nNodo0->Nodoy" + to_string(root->down->index) + "[dir=both];\n";

	string texto = "";
	

	string nodoTemp = "Nodo0 [label=\"Y\\X\"];\n";
	string enlaceNodo = "";
	string same = " {rank=same Nodo0 ";
	string samey = " {rank=same ";




	MatrixNode* auxtemp = aux->next;
	//Cabezas X
	while (auxtemp != NULL)
	{
		nodoTemp = nodoTemp + "Nodox" + to_string(auxtemp->index) + "[label = \"" + auxtemp->data + "\"]" + "\n";
		if (auxtemp->next != NULL)
		{
			same = same + "Nodox" + to_string(auxtemp->index) + " ";
		}
		else {
			same = same + "Nodox" + to_string(auxtemp->index);
		}
		auxtemp = auxtemp->next;
	}
	same = same + "}\n";
	


	MatrixNode* temp = root->down;
	//Cabezas Y
	
	while (temp != NULL)
	{
		MatrixNode* auxtemp = temp;
		while (auxtemp != NULL)
		{
			nodoTemp = nodoTemp + "Nodoy" + to_string(auxtemp->index) + "[label = \"" + auxtemp->data + "\"]" + "\n";
			
			if (auxtemp->next != NULL)
			{
				samey = samey + "Nodoy" + to_string(auxtemp->index) + " ";
			}
			else {
				samey = samey + "Nodoy" + to_string(auxtemp->index);
			}
			auxtemp = auxtemp->next;
		}
		if (temp->down != NULL)
		{
			samey = samey + "}\n {rank=same ";
		}
		else {
			samey = samey + "}\n";
		}

		temp = temp->down;
	}

	



	
	//ENLACES CABEZAS
	while (cabezaX != NULL)
	{
		if (cabezaX->next != NULL)
		{
			juntarNodos = juntarNodos  +"Nodox" + to_string(cabezaX->index) + "->Nodox" + to_string(cabezaX->next->index) + "[constraint=false, dir=both];\n";

		}
		cabezaX = cabezaX->next;

	}


	//CABECERAS Y
	while (cabezaY != NULL)
	{
		if (cabezaY->down != NULL)
		{
			juntarNodos = juntarNodos + + "Nodoy" + to_string(cabezaY->index) + "->Nodoy" + to_string(cabezaY->down->index) + "[dir=both];\n";
		}
		cabezaY = cabezaY->down;
	}

	MatrixNode* a = root->next;
	while (a != NULL)
	{
		print_x_header(a->down, a->index);
		a = a->next;
	}

	MatrixNode* b = root->down;
	while (b != NULL)
	{
		print_y_header(b->next, b->index);
		b = b->down;
	}
	
	*/
	
	//CABECERAS X
	/*while (cabezaX != NULL)
	{
		if (cabezaX->next != NULL)
		{
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"' + "X=" + to_string(cabezaX->x) + '"' + "];\n" +
				+"Nodox" + to_string(cabezaX->index) + "->Nodox" + to_string(cabezaX->next->index) + "[constraint=false, dir=both];\n";

		}
		else {
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"' + "X=" + to_string(cabezaX->x) + '"' + "];\n";
		}
		contador++;
		cabezaX = cabezaX->next;

	}*/
	//CABECERAS Y
	/*while (cabezaY != NULL)
	{
		if (cabezaY->down != NULL)
		{
			nodos = nodos + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + "Y=" + to_string(cabezaY->y) + '"' + "];\n"
				+ "Nodoy" + to_string(cabezaY->index) + "->Nodoy" + to_string(cabezaY->down->index) + "[dir=both];\n";
		}
		else
		{
			nodos = nodos + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + "Y=" + to_string(cabezaY->y) + '"' + "];\n";
		}
		cabezaY = cabezaY->down;

	}*/


	//
	/*MatrixNode* temp = root->next;
	while (temp != NULL)
	{
		print_x_header(temp->down, temp->index);
		temp = temp->next;
	}
	MatrixNode* temp1 = root->down;
	while (temp1 != NULL)
	{
		print_y_header(temp1->next, temp1->index);
		temp1 = temp1->down;
	}*/

	








































	//NUEVO CODIGO DE PRUEVA
	string archivoCabeza = "digraph Sparce_Matrix { \n node [shape=box]\n";
	archivoCabeza = archivoCabeza + "Mt[ label = \"Matrix\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];\n";
	archivoCabeza = archivoCabeza + "e0[ shape = point, width = 0 ];\ne1[shape = point, width = 0];\n";



	//CABECERAS Y;
	MatrixNode* cabezaY = root->down;
	enlacesy = "Mt->Nodoy" + to_string(cabezaY->index)+"[dir=both];\n";
	while (cabezaY != NULL)
	{
		if (cabezaY->down != NULL)
		{
			nodosy = nodosy + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + "Y=" + to_string(cabezaY->y) + '"' + " width = 1.5 style = filled, fillcolor = bisque1, group = 1  ];\n";
			enlacesy = enlacesy + "Nodoy" + to_string(cabezaY->index) + "->Nodoy" + to_string(cabezaY->down->index) + "[dir=both];\n";
		}
		else
		{
			nodosy = nodosy + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + "Y=" + to_string(cabezaY->y) + '"' + "width = 1.5 style = filled, fillcolor = bisque1, group = 1  ];\n";
		}
		cabezaY = cabezaY->down;

	}

	//CABECERAS X
	MatrixNode* cabezaX = root->next;
	enlacesx = "Mt->Nodox" + to_string(cabezaX->index) + ";\n";
	string samex = " { rank = same; Mt; ";
	while (cabezaX != NULL)
	{
		if (cabezaX->next != NULL)
		{
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"' + "X=" + to_string(cabezaX->x) + '"' + " width = 1.5 style = filled, fillcolor = lightskyblue, group =" + to_string(cabezaX->index )+ "];\n";
			enlacesx = enlacesx + "Nodox" + to_string(cabezaX->index) + "->Nodox" + to_string(cabezaX->next->index) + "[dir=both];\n";
			samex = samex + "Nodox" + to_string(cabezaX->index) + "; ";
		}
		else {
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"' + "X=" + to_string(cabezaX->x) + '"' + "width = 1.5 style = filled, fillcolor = lightskyblue, group =" + to_string(cabezaX->index) + "];\n";
			samex = samex + "Nodox" + to_string(cabezaX->index) + "}\n";

		}
		cabezaX = cabezaX->next;
	}


	


	//NODOS INTERNOS
	MatrixNode* temp = root->down;
	string nodoTemp = "";
	string samey = "{rank= same; ";
	while (temp != NULL)
	{
		MatrixNode* auxtemp = temp;
		while (auxtemp != NULL)
		{
			MatrixNode* padre = auxtemp;
			do
			{
				padre = padre->up;
			} while (padre->up != NULL);
			nodoTemp = nodoTemp + "Nodoy" + to_string(auxtemp->index) + "[label = \"" + auxtemp->data + "\" width = 1.5, group = " + to_string(padre->index) + "];" + "\n";
			
			if (auxtemp->next != NULL)
			{
				samey = samey + "Nodoy" + to_string(auxtemp->index) + ";";
			}
			else {
				samey = samey + "Nodoy" + to_string(auxtemp->index);
			}
			auxtemp = auxtemp->next;
		}
		if (temp->down != NULL)
		{
			samey = samey + "}\n {rank=same;";
		}
		else {
			samey = samey + "}\n";
		}
		temp = temp->down;
	}


	//obtiene los enlaces hacia abajo 
	MatrixNode* a = root->next;
	while (a != NULL)
	{
		print_x_header(a->down, a->index);
		a = a->next;
	}

	//obtiene los enlaces hacia la derecha
	MatrixNode* b = root->down;
	while (b != NULL)
	{
		print_y_header(b->next, b->index);
		b = b->down;
	}

	string texto = archivoCabeza + nodos + nodosy + enlacesx + enlacesy + samex  + nodoTemp + samey+  "}";
	std::cout << texto;
	
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o Matrix.png Matrix.dot");
	system("Matrix.png");
}








