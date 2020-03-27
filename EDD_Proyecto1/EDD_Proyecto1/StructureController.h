#include <string>
#include <iostream>
#include "UsersBinaryTree.h";
#include "ScoreBoardList.h";
#include "LDC_DictionaryList.h";
#include "Queue_GameChip.h";
#include "Matrix.h";
#include "Letter.h";
#include <time.h>
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

	//LETTERS
	void RandomLetters();


	//GameChip
	void PushGameChip(string letter, int points, int quantity);
	void PrintGameChips();
	GameChipNode* PopChip();
	bool QueueIsEmpty();

	//DICTIONARY
	void InsertDictionary(string text);
	void PrintDictionary();
	DictionaryNode* SearchWord(string word);
	//Board
	void InsertBoardDimention(int d);
	//verifica si la posicion xy este dentro del limite del tablero
	bool ValidateInsertInBoard(int x, int y);


	//Users
	bool InsertUser(string u);
	void PrintUsers();
	TreeNode* SearchUser(string u);
	//Matrix

	void InsertMatrix(int x, int y, string letra, int pts,  bool d, bool t);
	void PrintMatrix();
	void DeleteMatrixNode(int x, int y);
	MatrixNode* SearchLetter(int x, int y);

	//Score Board

	void InsertScore(string name, int points);
	void PrintScore(string user);

};

