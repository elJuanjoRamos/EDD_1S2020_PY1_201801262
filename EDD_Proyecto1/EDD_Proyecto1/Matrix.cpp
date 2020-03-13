#include "Matrix.h"
#include <fstream>
#include <iostream>


void Matrix::InsertElement(int x, int y, string data, bool isDouble, bool isTriple) {
	MatrixNode* column = this->SearchColumn(x);
	MatrixNode* row = this->SearchRow(y);
	MatrixNode* new_node = new MatrixNode(data, x, y, isDouble, isTriple);

	/*CASO 1: COLUMNA Y FILA NO EXISTEN */
	if (column == 0 && row == 0)
	{
		column = this->CreateColumn(x);
		row = this->CreateRow(y);
		
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
	//*CASO 2: COLUMNA NO EXISTE, FILA EXISTE*/
	if (column == 0 && row !=0)
	{
		
		column = this->CreateColumn(x);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
	/*CASO 3: COLUMNA EXISTE, FILA NO EXISTE*/
	if (column != 0 && row == 0)
	{
		row = this->CreateRow(y);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
	/*CASO 4: COLUMNA Y FILA EXISTEN*/
	if (column != 0 && row != 0 )
	{
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		return;
	}
}


MatrixNode* Matrix::CreateColumn(int x) {
	MatrixNode* col = new MatrixNode("", x, -1, false, false);
	MatrixNode* reco = root;
	MatrixNode* ant = root;

	lastRight->next = col;
	col->next = NULL;
	col->before = lastRight;
	lastRight = col;


	/*while (x >= reco->y && reco->next != NULL) {
		ant = reco;
		reco = reco->next;
	}
	if (x >= reco->y) {
		reco->next = reco;
		reco->before = reco;
		//new_node->next = NULL;
	}
	else {
		reco->next = reco;
		reco->before = reco;
		ant->next = reco;
		reco->before = ant;
	}*/
	
	return col;
}

MatrixNode* Matrix::CreateRow(int y) {
	MatrixNode* col = new MatrixNode("", -1, y, false, false);
	MatrixNode* reco = root;
	MatrixNode* ant = root;


	/*while (y >= reco->y && reco->down != NULL) {
		ant = reco;
		reco = reco->down;
	}
	if (y >= reco->y) {
		reco->down = col;
		col->up = reco;
	}
	else {
		col->down = reco;
		reco->up = col;
		ant->down = col;
		col->up = ant;
	}*/

	lastDown->down = col;
	col->down = NULL;
	col->up = lastDown;
	lastDown = col;
	


	return col;
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

	while (new_node->x >= reco->x && reco->down != NULL) {
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
	}


	return new_node;
}




MatrixNode* Matrix::InsertRow(MatrixNode* new_node, MatrixNode* root) {
	MatrixNode* reco = root;
	MatrixNode* ant = root;

	while (new_node->y >= reco->y && reco->next != NULL) {
		ant = reco;
		reco = reco->next;
	}
	if (new_node->y >= reco->y) {
		reco->next = new_node;
		new_node->before = reco;
		//new_node->next = NULL;
	}
	else {
		new_node->next = reco;
		reco->before = new_node;
		ant->next = new_node;
		new_node->before= ant;
	}
	return new_node;
}




void Matrix::print_headers() {
	
}


void Matrix::print_x_header(MatrixNode* cabezaY, int x) {
	nodos = nodos + "Nodox" + to_string(x) + "->Nodoy" + to_string(cabezaY->index) + "[dir=both]\n";
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

	}

}
void Matrix::print_y_header(MatrixNode* cabezaX, int index) {

	nodos = nodos + "Nodoy" + to_string(index) + "->Nodoy" + to_string(cabezaX->index) + "[constraint=false, dir=both]\n";

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

	}

}
void Matrix::print_nodes_x() {
	
}
void Matrix::print_nodes_y() {
	
}


void Matrix::Print() {

	
	string archivoCabeza = "digraph G {rankdir = TB; \n node [shape=rectangle, height=0.5, width=0.5]; \n graph[ nodesep = 0.5];\n";

	nodos = "Nodo0 [label=\"Y\\X\"];\n";
	
	ofstream ofs("Matrix.dot", ofstream::out);

	MatrixNode* cabezaX = root->next;
	MatrixNode* cabezaY = root->down;
	MatrixNode* aux = root;
	string juntarNodos="Nodo0->Nodox" + to_string(root->next->index) + "[constraint=false, dir=both];\nNodo0->Nodoy" + to_string(root->down->index) + "[dir=both];\n";

	string texto = "";
	int contador = 1;
	int contador2 = 1;


	//CABECERAS X
	while (cabezaX != NULL)
	{
		if (cabezaX->next != NULL)
		{
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"'+ "X=" + to_string(cabezaX->x) + '"' + "];\n"+
			+"Nodox" + to_string(cabezaX->index) + "->Nodox" + to_string(cabezaX->next->index) + "[constraint=false, dir=both];\n";
		
		}
		else {
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"' + "X=" + to_string(cabezaX->x) + '"' + "];\n";
		}
		contador++;
		cabezaX = cabezaX->next;

	}
	//CABECERAS Y
	while (cabezaY != NULL)
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

	}


	//
	MatrixNode* temp = root->next;
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
	}




	
	
	//std::cout << texto;
	texto = archivoCabeza + nodos + juntarNodos + "}";
	std::cout << texto;
	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o Matrix.png Matrix.dot");
	system("Matrix.png");
}

	






