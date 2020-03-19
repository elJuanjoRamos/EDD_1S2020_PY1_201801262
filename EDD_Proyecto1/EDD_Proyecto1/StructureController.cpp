#include "StructureController.h"



//SINGLETON
StructureController* StructureController::instance = 0;

StructureController* StructureController::getInstance()
{
    if (instance == 0)
    {
        instance = new StructureController();
    }

    return instance;
}

StructureController::StructureController(){}



//DICTIONARY

void StructureController::InsertDictionary(string t) {
    diccionario.Insert(t);
}

void StructureController::PrintDictionary() {
    diccionario.Print();
}


void StructureController::InsertDouble(int x, int y, bool d, bool t) {

}


// BOARD

void StructureController::InsertBoardDimention(int d) {
    /*for (size_t i = 1; i <= d; i++)
    {
        this->mat.CreateColumn(d);
        this->mat.CreateRow(d);
    }*/
    this->boardDimention = d;
}
bool StructureController::ValidateInsertInBoard(int x, int y) {
    if (x <= boardDimention && y <= boardDimention)
    {
        return true;
    }
    return false;
}

//USERS 

bool StructureController::InsertUser(string user) {
    if (arbol.Search(user) == NULL)
    {
        arbol.Insert(user);
        return true;
    }
    else {
        return false;
    }
    return false;
}

void StructureController::PrintUsers() {
    arbol.Print();
}


//Matrix 
void StructureController::InsertMatrix(int x, int y, string letter, bool doubl, bool triple) {
    mat.InsertElement(x, y, letter, doubl, triple);
}

void StructureController::PrintMatrix() {
    mat.Print();
}

