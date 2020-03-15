#include <string>
#include <iostream>
#include "UsersBinaryTree.h";
#include "ScoreBoardList.h";
#include "LDC_DictionaryList.h";
#include "Queue_GameChip.h";
#include "Matrix.h";

class StructureController
{
private:
	static StructureController* instance;
	StructureController();
public:
	static StructureController* getInstance();

	UsersBinaryTree arbol;
	ScoreBoardList listaOrdenada;
	LDC_DiccionaryList diccionario;
	Queue_GameChip queuegame;
	Matrix mat;



	//Methods
	void InsertDictionary(string text);
	void PrintDictionary();


};

