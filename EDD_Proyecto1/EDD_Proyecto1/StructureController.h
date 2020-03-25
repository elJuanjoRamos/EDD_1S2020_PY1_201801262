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

	//GameChip
	void PushGameChip(string letter, int points, int quantity);
	void PrintGameChips();
	GameChipNode* PopChip();


	//DICTIONARY
	void InsertDictionary(string text);
	void PrintDictionary();
	void InsertDouble(int x, int y, bool a, bool b);
	DictionaryNode* SearchWord(string word);
	//Board
	void InsertBoardDimention(int d);
	//verifica si la posicion xy este dentro del limite del tablero
	bool ValidateInsertInBoard(int x, int y);


	//Users
	bool InsertUser(string u);
	void PrintUsers();

	//Matrix

	void InsertMatrix(int x, int y, string letra, int pts,  bool d, bool t);
	void PrintMatrix();
	void DeleteMatrixNode(int x, int y);
	MatrixNode* SearchLetter(int x, int y);

};

