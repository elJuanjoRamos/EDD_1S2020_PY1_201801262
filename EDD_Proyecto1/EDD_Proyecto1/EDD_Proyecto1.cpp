

#include <iostream>
#include <string>

#include "UsersBinaryTree.h";
#include "ScoreBoardList.h";
#include "LDC_DictionaryList.h";
#include "Queue_GameChip.h";
#include "Matrix.h";

UsersBinaryTree arbol;
ScoreBoardList listaOrdenada;
LDC_DiccionaryList listaDoble;
Queue_GameChip queuegame;
Matrix mat;
using namespace std;
int main()
{

    /*arbol.Insert("Mark");//4
    arbol.Insert("wicho");//5
    arbol.Insert("lalalalal");
    arbol.Insert("m1");
    arbol.Insert("lalalal");
    arbol.Insert("lalalaldfds");
    arbol.Insert("eeee");
    arbol.Insert("aaaa");
    arbol.Print();*/

    /*listaOrdenada.Insert(10, "nodo1");
    listaOrdenada.Insert(5, "nodo2");
    listaOrdenada.Insert(7, "nodo3");
    listaOrdenada.Insert(50, "nodo4");
    listaOrdenada.Insert(75, "nodo4");
    listaOrdenada.Insert(100, "nodo4");
    listaOrdenada.Print("");*/
    
    /*listaDoble.Insert("wicho");//5
    listaDoble.Insert("lalalalal");
    listaDoble.Insert("m1");
    listaDoble.Insert("lalalal");
    listaDoble.Insert("lalalaldfds");
    listaDoble.Insert("eeee");
    listaDoble.Print();*/
    
    
    /*queuegame.Push('a', 0,5);
    queuegame.Push('c', 50, 8);
    queuegame.Push('d', 9, 6);
    queuegame.Push('f', 3, 100);
    queuegame.Print();
    */
    


    mat.InsertElement(1, 0, "a", false, false);
    mat.InsertElement(2, 0, "b", false, false);
    mat.InsertElement(8, 0, "h", false, false);
    mat.InsertElement(3, 0, "c", false, false);
    mat.InsertElement(5, 0, "e", false, false);
    mat.InsertElement(9, 0, "i", false, false);
    
    mat.InsertElement(2, 1, "u", false, false);
    mat.InsertElement(8, 3, "j", false, false);
    mat.InsertElement(3, 1, "k", false, false);
    

    mat.Print();
    /*mat.print_headers();
    mat.print_nodes_x();

    cout << "\n";
    mat.print_nodes_y();*/
}

