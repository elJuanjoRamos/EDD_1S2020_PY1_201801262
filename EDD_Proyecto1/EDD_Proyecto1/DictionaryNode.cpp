#include "DictionaryNode.h"

DictionaryNode::DictionaryNode() {
}
DictionaryNode::DictionaryNode(string n){
	word = n;
	ant = next = NULL;
}

