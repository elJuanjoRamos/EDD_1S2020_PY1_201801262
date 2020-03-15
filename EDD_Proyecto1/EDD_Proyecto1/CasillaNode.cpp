#include "CasillaNode.h"

CasillaNode::CasillaNode() {

}

void CasillaNode::setData(int x1, int y3, bool isd, bool ist) {
	x = x1;
	y = y3;
	sdouble = isd;
	striple = ist;
	isEmpty = false;
}

bool CasillaNode::getData() {
	return isEmpty;
}

int CasillaNode::getX() {
	return x;
}
int CasillaNode::getY() {
	return y;
}
void CasillaNode::toString() {
	cout << "-----------" << endl;;
	cout << "X: " << x<< endl;
	cout << "Y: " << y << endl;
	cout << "double: " << sdouble << endl;
	cout << "triple: " << striple << endl;


}