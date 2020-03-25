#include "GameChipNode.h"

GameChipNode::GameChipNode(string l, int p, int c)
{
	letter = l;
	points = p;
	cant = c;
	next = NULL;
}