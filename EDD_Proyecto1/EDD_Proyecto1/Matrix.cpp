#include "Matrix.h"
#include <fstream>
#include <iostream>
#include "CasillaNode.h";


void Matrix::InsertElement(int x, int y, string data, int pts, bool isDouble, bool isTriple) {
	MatrixNode* column = this->SearchColumn(x);
	MatrixNode* row = this->SearchRow(y);

	/*CASO 1: COLUMNA Y FILA NO EXISTEN */
	if (column == 0 && row == 0)
	{
		column = this->CreateColumn(x);
		row = this->CreateRow(y);
		MatrixNode* new_node = new MatrixNode(data, pts, x, y, false, false);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		new_node = this->getDoubleTriple(new_node);
		return;
	}
	//*CASO 2: COLUMNA NO EXISTE, FILA EXISTE*/
	if (column == 0 && row != 0)
	{

		column = this->CreateColumn(x);
		MatrixNode* new_node = new MatrixNode(data, pts, x, y, isDouble, isTriple);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		new_node = this->getDoubleTriple(new_node);
		return;
	}
	/*CASO 3: COLUMNA EXISTE, FILA NO EXISTE*/
	if (column != 0 && row == 0)
	{
		row = this->CreateRow(y);
		MatrixNode* new_node = new MatrixNode(data, pts, x, y, isDouble, isTriple);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		new_node = this->getDoubleTriple(new_node);
		return;
	}
	/*CASO 4: COLUMNA Y FILA EXISTEN*/
	if (column != 0 && row != 0)
	{
		MatrixNode* new_node = new MatrixNode(data, pts, x, y, isDouble, isTriple);
		new_node = this->InsertColumn(new_node, column);
		new_node = this->InsertRow(new_node, row);
		new_node = this->getDoubleTriple(new_node);
		return;
	}
}


MatrixNode* Matrix::CreateColumn(int x) {
	MatrixNode* nuevo = new MatrixNode("X=" + to_string(x), x, -1, false, false);
	MatrixNode* temp = root;

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

		nuevo->down = root;
		root = nuevo;
	}
	else {
		MatrixNode* reco = root;
		MatrixNode* ant = root;

		while (y >= reco->y && reco->down != NULL) {
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

MatrixNode* Matrix::SearchLetra(int x, int y) {
	MatrixNode* temp = root;
	MatrixNode* aux = NULL;

	while (temp != NULL)
	{
		if (temp->x == x)
		{
			aux = temp;
			break;
		}
		temp = temp->next;
	}

	while (aux != NULL)
	{
		if (aux->y == y)
		{
			return aux;
			break;
		}
		aux = aux->down;
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

	return new_node;
}

void Matrix::print_x_header(MatrixNode* cabezaY, int x) {
	nodosy = nodosy + "Nodox" + to_string(x) + "->Nodoy" + to_string(cabezaY->index) + "[dir=both]\n";
	while (cabezaY != NULL)
	{
		if (cabezaY->down != NULL)
		{
			nodosy = nodosy + "Nodoy" + to_string(cabezaY->index) + "->Nodoy" + to_string(cabezaY->down->index) + "[dir=both];\n";
		}
		cabezaY = cabezaY->down;

	}
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

}

MatrixNode* Matrix::getDoubleTriple(MatrixNode* node) {

	if (casillaCont->getCasillaDoble(node->x, node->y))
	{
		node->isDouble = true;
		node->isTriple = false;
	}
	else if (casillaCont->getCasillaTriple(node->x, node->y)) {
		node->isTriple = true;
		node->isDouble = false;
	}
	return node;
}


void Matrix::Delete(int x, int y) {
	MatrixNode* temp = root;
	if (temp != NULL)
	{


		while (temp != NULL)
		{

			MatrixNode* temp2 = temp;

			while (temp2 != NULL)
			{
				if (temp2->x == x && temp2->y == y)
				{
					temp2->before->next = temp2->next;
					if (temp2->next != NULL)
					{
						temp2->next->before = temp2->before;
					}
					temp2->before = temp2->next = NULL;
					temp2->up->down = temp2->down;
					if (temp2->down != NULL)
					{
						temp2->down->up = temp2->up;
					}
					temp2->up = temp2->down = NULL;
					temp2 = NULL;
					break;
				}
				temp2 = temp2->next;
			}
			temp = temp->down;

		}

	}
}

void Matrix::Print() {
	ofstream ofs("Matrix.dot", ofstream::out);


	//NUEVO CODIGO DE PRUEVA
	string archivoCabeza = string()+ "digraph Sparce_Matrix { \n node [shape=box, style = " + '"' + "rounded,filled" + '"' + ", fillcolor = bisque1]\n";
	archivoCabeza = archivoCabeza + "\tMt[ label = \"Matrix\", width = 1.5, style = " + '"' + "rounded,filled" + '"' +", fillcolor = firebrick1, group = 1 ];\n";
	archivoCabeza = archivoCabeza + "\te0[ shape = point, width = 0 ];\ne1[shape = point, width = 0];\n";
	string texto = "";
	if (root->next != NULL && root->down != NULL)
	{

	MatrixNode* as = root;

	//CABECERAS Y;
	MatrixNode* cabezaY = root->down;
	enlacesy = "Mt->Nodoy" + to_string(cabezaY->index) + "[dir=both];\n";
	while (cabezaY != NULL)
	{
		if (cabezaY->down != NULL)
		{
			nodosy = nodosy + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + "Y=" + to_string(cabezaY->y) + '"' + " width = 1.5 style = " + '"' + "rounded,filled" + '"' + ", fillcolor = darkseagreen1, group = 1  ];\n";
			enlacesy = enlacesy + "Nodoy" + to_string(cabezaY->index) + "->Nodoy" + to_string(cabezaY->down->index) + "[dir=both];\n";
		}
		else
		{
			nodosy = nodosy + "Nodoy" + to_string(cabezaY->index) + " [label = " + '"' + "Y=" + to_string(cabezaY->y) + '"' + "width = 1.5 style = " + '"' + "rounded,filled" + '"' + ", fillcolor = darkseagreen1, group = 1  ];\n";
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
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"' + "X=" + to_string(cabezaX->x) + '"' + " width = 1.5 style = " + '"' + "rounded,filled" + '"' + ", fillcolor = lightskyblue, group =" + to_string(cabezaX->index) + "];\n";
			enlacesx = enlacesx + "Nodox" + to_string(cabezaX->index) + "->Nodox" + to_string(cabezaX->next->index) + "[dir=both];\n";
			samex = samex + "Nodox" + to_string(cabezaX->index) + "; ";
		}
		else {
			nodos = nodos + "Nodox" + to_string(cabezaX->index) + " [label = " + '"' + "X=" + to_string(cabezaX->x) + '"' + "width = 1.5 style = " + '"' + "rounded,filled" + '"' + ", fillcolor = lightskyblue, group =" + to_string(cabezaX->index) + "];\n";
			samex = samex + "Nodox" + to_string(cabezaX->index) + "}\n";

		}
		cabezaX = cabezaX->next;
	}

	//NODOS INTERNOS
	MatrixNode* temp = root->down;
	string nodoTemp = "";
	string samey = "{rank= same; ";
	string doubleTriple = "";
	while (temp != NULL)
	{
		MatrixNode* auxtemp = temp;

		while (auxtemp != NULL)
		{

			//INDICA SI LA CASILLA ES DOBLE O TRIPLE
			if (auxtemp->isDouble)
			{
				doubleTriple = "\\n doble";
			}
			else if (auxtemp->isTriple)
			{
				doubleTriple = "\\n triple";
			}
			else {
				doubleTriple = "";
			}
			//////


			MatrixNode* padre = auxtemp;
			do
			{
				padre = padre->up;
			} while (padre->up != NULL);

			if (auxtemp->data == "Ñ"  || auxtemp->data  == "¥")
			{
				nodoTemp = nodoTemp + "Nodoy" + to_string(auxtemp->index) + "[label = \"" + "Ñ" + doubleTriple + "\" width = 1.5, group = " + to_string(padre->index) + "];" + "\n";

			}
			else
			{
				nodoTemp = nodoTemp + "Nodoy" + to_string(auxtemp->index) + "[label = \"" + auxtemp->data + doubleTriple + "\" width = 1.5, group = " + to_string(padre->index) + "];" + "\n";
			}
			
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
		if (a->down != NULL)
		{
			print_x_header(a->down, a->index);
		}
		a = a->next;
	}

	//obtiene los enlaces hacia la derecha
	MatrixNode* b = root->down;
	while (b != NULL)
	{
		if (b->next != NULL)
		{
			print_y_header(b->next, b->index);
		}
		b = b->down;
	}

	texto = archivoCabeza + nodos + nodosy + enlacesx + enlacesy + samex + nodoTemp + samey + "}";
	archivoCabeza = nodos = nodosy = enlacesx = enlacesy = samex = nodoTemp = samey = "";

	//std::cout << texto;
	}
	else
	{
		texto = archivoCabeza + "}";
	}

	ofs << texto;

	ofs.close();
	system("dot -Tjpg -o Matrix.png Matrix.dot");
}
void Matrix::ShowPrint() {
	system("Matrix.png");
}
