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