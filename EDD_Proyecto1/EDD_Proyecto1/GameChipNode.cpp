#include "GameChipNode.h"

GameChipNode::GameChipNode(char l, int p, int c)
{
	letter = l;
	points = p;
	cant = c;
	next = NULL;
}