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

	int boardDimention;

	UsersBinaryTree arbol;
	ScoreBoardList listaOrdenada;
	LDC_DiccionaryList diccionario;
	Queue_GameChip queuegame;
	Matrix mat;



	//Methods
	void InsertDictionary(string text);
	void PrintDictionary();
	void InsertDouble(int x, int y, bool a, bool b);


	//Board
	void InsertBoardDimention(int d);
	//verifica si la posicion xy este dentro del limite del tablero
	bool ValidateInsertInBoard(int x, int y);


	//Users
	bool InsertUser(string u);
	void PrintUsers();
};

