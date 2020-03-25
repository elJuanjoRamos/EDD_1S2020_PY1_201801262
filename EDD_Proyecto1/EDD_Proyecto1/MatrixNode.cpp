#include "MatrixNode.h"

MatrixNode::MatrixNode() {
}
int MatrixNode::correlative = 1;

MatrixNode::MatrixNode(string d, int x1, int y1, bool isd, bool ist) {
	this->data = d;
	this->x = x1;
	this->y = y1;
	this->index = correlative++;
	this->isDouble = isd;
	this->isTriple = ist;
	this->next = this->before = this->up = this->down = NULL;
}

MatrixNode::MatrixNode(string d, int pts, int x, int y, bool isd, bool ist)
{
	this->data = d;
	this->points = pts;
	this->x = x;
	this->y = y;
	this->index = correlative++;
	this->isDouble = isd;
	this->isTriple = ist;
	this->next = this->before = this->up = this->down = NULL;
}
