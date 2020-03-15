

#include <iostream>
#include <string>
#include <fstream>      // std::ifstream
#include <typeinfo>

#include "Matrix.h";
#include "Menu.h";
//#include "CasillaController.h";
//#include "StructureController.h";
#include "JSON.h";

Menu menu;
Matrix mat1;
//StructureController* controller = StructureController::getInstance();
//CasillaController* casillaController = CasillaController::getInstance();




using json = nlohmann::json;
//VARIABLES GLOBALES
string opc = "";


void OpenFile();


using namespace std;
int main()
{


	/*bool Salir = false;
	do {
		if (opc == "")
		{
			menu.Cls();
			menu.getMenu();
			do
			{
				opc = "";
				cout << "\n" << "\t\t\t" << "    Por favor, ingrese el valor: ";
				cin >> opc;

			} while (menu.IsNumber(opc) != true);
		}

		int opcion = atoi(opc.c_str());
		opc = "";

        //Open file
        if (opcion == 1)
        {
            menu.Cls();
            OpenFile();
        }
        //Jugar
        else if (opcion == 2) {

        }
        //Reportes
        else if (opcion == 3) {

        }
        //salir
        else if (opcion == 4) {
            Salir = true;
        }

		

	} while (Salir == false);*/


    /*arbol.Insert("becerro");//4
    arbol.Insert("avion");//4
    arbol.Insert("casa");//4
    arbol.Insert("axyz");//4
    arbol.Insert("espora");//4
    arbol.Insert("francia");//4
    arbol.Insert("durazno");//4


    arbol.Print();
    */
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
    


    mat1.InsertElement(1, 0, "a", false, false);
    mat1.InsertElement(2, 0, "b", false, false);
    mat1.InsertElement(8, 0, "h", false, false);
    mat1.InsertElement(3, 0, "c", false, false);
    mat1.InsertElement(5, 0, "e", false, false);
    mat1.InsertElement(9, 0, "i", false, false);
    
    mat1.InsertElement(2, 1, "u", false, false);
    mat1.InsertElement(8, 3, "j", false, false);
    mat1.InsertElement(3, 1, "k", false, false);
    mat1.InsertElement(5, 2, "t", false, false);
    mat1.InsertElement(3, 4, "p", false, false);

    mat1.Print();
    /*mat.print_headers();
    mat.print_nodes_x();

    cout << "\n";
    mat.print_nodes_y();*/
}



void OpenFile() {
    do
    {
        /*Menu::Print(20, 1, "-------------------------------", 10);
        Menu::Print(20, 2, "|    CARGA DE ARCHIVOS 1.0    |", 10);
        Menu::Print(20, 3, "-------------------------------", 10);
        Menu::Print(20, 4, " ", 10);
        cout << "Inserte el nombre de archivo";*/
        puts("Carga de Archivos Simple v1");
        puts("Ingrese el nombre del archivo");
        puts("------------------------------------");
        cout << "\n| Ingrese el nombre del archivo:";
        string fileName = "";
        cin >> fileName;



        std::ifstream i;

        i.open(fileName + ".json", ios::in);

        if (!i.fail())
        {

            std::ifstream i(fileName + ".json");
            json j3;
            i >> j3;


            //INSERTA LAS PALABRAS AL DICCIONARIO
            for (int x = 0; x < j3.at("diccionario").size(); x++)
            {
                cout << "Palabra: " << j3.at("diccionario")[x].at("palabra") << endl;
                //controller->InsertDictionary(j3.at("diccionario")[x].at("palabra"));
            }
            
            //INSERTA LAS CASILLAS DOBLES EN UN ARREGLO TEMPORAL, ESE ARREGLO SIRVE AL MOMENTO DE INSERTAR EN LA MATRIZ, BUSCA EN EL ARREGLO LA POSICION 
            //X, Y Y SI EXISTE DEVUELVE SI ES DOBLE
            for (int i = 0; i < j3.at("casillas").at("dobles").size(); i++)
            {
                //casillaController->Insert(j3.at("casillas").at("dobles")[i].at("x"), j3.at("casillas").at("dobles")[i].at("y"), true, false);
            }
            //INSERTA LAS CASILLAS DOBLES EN UN ARREGLO TEMPORAL, ESE ARREGLO SIRVE AL MOMENTO DE INSERTAR EN LA MATRIZ, BUSCA EN EL ARREGLO LA POSICION 
            //X, Y Y SI EXISTE DEVUELVE SI ES TRIPLE
            for (int i = 0; i < j3.at("casillas").at("triples").size(); i++)
            {
                //casillaController->Insert(j3.at("casillas").at("triples")[i].at("x"), j3.at("casillas").at("triples")[i].at("y"), false, true);
            }
        }
        else {

            puts("");
            puts("--------------------------");
            puts("| Archivo no encontrado! |");
            puts("--------------------------");
            puts("");
            system("pause");
            menu.Cls();
        }




    } while (-1);

}