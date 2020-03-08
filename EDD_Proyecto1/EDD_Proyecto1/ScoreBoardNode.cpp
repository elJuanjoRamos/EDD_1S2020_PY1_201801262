#include "ScoreBoardNode.h"
ScoreBoardNode::ScoreBoardNode(int p, string n) {
	this->points= p;
	this->username = n;
	this->next = NULL;
}

ScoreBoardNode::ScoreBoardNode(){}

