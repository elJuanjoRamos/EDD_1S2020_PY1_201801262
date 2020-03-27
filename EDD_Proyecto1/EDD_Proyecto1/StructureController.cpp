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
DictionaryNode* StructureController::SearchWord(string word) {
    return diccionario.search(word);
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
TreeNode* StructureController::SearchUser(string u) {
    if (arbol.Search(u) != NULL)
    {
        return arbol.Search(u);
    } 
    return NULL;
}

//Matrix 
void StructureController::InsertMatrix(int x, int y, string letter, int pts, bool doubl, bool triple) {
    mat.InsertElement(x, y, letter, pts, doubl, triple);
}
void StructureController::PrintMatrix() {
    mat.Print();
}
void StructureController::DeleteMatrixNode(int x, int y) {
    mat.Delete(x, y);
}
MatrixNode* StructureController::SearchLetter(int x, int y) {
    return mat.SearchLetra(x, y);
}

//Game chip

void StructureController::PushGameChip(string letter, int points, int quantity) {
    queuegame.Push(letter, points, quantity);
}
void StructureController::PrintGameChips() {
    queuegame.Print();
}
GameChipNode* StructureController::PopChip() {
    return queuegame.Pop();
}
bool StructureController::QueueIsEmpty() {
    return queuegame.IsEmpty();
}

//Score board

void StructureController::InsertScore(string name, int points) {
    listaOrdenada.Insert(points, name);
}
void StructureController::PrintScore(string user) {
    listaOrdenada.Print(user);
}

//LETTERS 

void StructureController::RandomLetters() {
    Letter* letras[25];
    //1
    letras[0] = new Letter("A", 1, 12);
    letras[1] = new Letter("E", 1, 12);
    letras[2] = new Letter("O", 1, 9);
    letras[3] = new Letter("I", 1, 6);
    letras[4] = new Letter("S", 1, 6);
    letras[5] = new Letter("N", 1, 5);
    letras[6] = new Letter("L", 1, 4);
    letras[7] = new Letter("R", 1, 5);
    letras[8] = new Letter("U", 1, 5);
    letras[9] = new Letter("T", 1, 4);
    //2 
    letras[10] = new Letter("D", 2, 5);
    letras[11] = new Letter("G", 2, 2);
    //3 
    letras[12] = new Letter("C", 3, 4);
    letras[13] = new Letter("B", 3, 2);
    letras[14] = new Letter("M", 3, 2);
    letras[15] = new Letter("P", 3, 2);
    //4
    letras[16] = new Letter("H", 4, 2);
    letras[17] = new Letter("F", 4, 1);
    letras[18] = new Letter("V", 4, 1);
    letras[19] = new Letter("Y", 4, 1);
    //5
    letras[20] = new Letter("Q", 5, 1);
    //8
    letras[21] = new Letter("J", 8, 1);
    letras[22] = new Letter("Ñ", 8, 1);
    letras[23] = new Letter("X", 8, 1);
    //10
    letras[24] = new Letter("Z", 10, 1);

    //INGRESAR ALEATORIO
    bool Salir = false;
    srand(time(NULL));
    do {
        int num = rand() % 25;
        //cout << num << " ";
        if (letras[num]->cant > 0) {
            letras[num]->cant = letras[num]->cant - 1;

            PushGameChip(letras[num]->letter, letras[num]->points, 1);
        }
        else {
            int contador = 0;
            for (size_t i = 0; i < 25; i++)
            {
                if (letras[i]->cant > 0) {
                    contador++;
                }
            }
            //cout << "CONTADOR: " << contador << "\n";
            if (contador == 0) {
                Salir = true;
                //controller->PrintGameChips();
            }
        }

    } while (Salir == false);
}