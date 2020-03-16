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


