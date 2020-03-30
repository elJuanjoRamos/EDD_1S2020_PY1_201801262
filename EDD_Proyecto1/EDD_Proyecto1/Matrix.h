#include "MatrixNode.h";
#include "CasillaController.h";
class Matrix
{
public:
    MatrixNode* root;
    MatrixNode* lastRight; //apuntador ultimo hacia la derecha
    MatrixNode* lastDown; //apuntador ultimo hacia abajo
    string nodos;
    string nodosy;
    string enlacesx;
    string enlacesy;
    CasillaController* casillaCont;

    Matrix() {
        root = new MatrixNode("Y/X", -1, -1, false, false);
        casillaCont = CasillaController::getInstance();
        lastDown = lastRight = root;
    }
    MatrixNode* SearchRow(int y);
    MatrixNode* SearchLetra(int x, int y);
    MatrixNode* SearchColumn(int x);
    MatrixNode* InsertColumn(MatrixNode* new_node, MatrixNode* head_column);
    MatrixNode* InsertRow(MatrixNode* new_node, MatrixNode* head_row);
    MatrixNode* CreateColumn(int y);
    MatrixNode* CreateRow(int x);
    void InsertElement(int x, int y, string data, int pts, bool isDouble, bool isTriple);
    void Print();
    void ShowPrint();
    void Delete(int x, int y);


    ///
    MatrixNode* getDoubleTriple(MatrixNode* x);
    void print_x_header(MatrixNode* x, int index);
    void print_y_header(MatrixNode* y, int index);
    
};

