

#include <iostream>
#include <string>
#include <fstream>      // std::ifstream
#include <typeinfo>
#include <clocale>
//#include "Matrix.h";
#include "Menu.h";
//#include "CasillaController.h";
#include "StructureController.h";
#include "JSON.h";
#include "Letter.h"
#include "LD_LetterPlayer.h"

Menu menu;
StructureController* controller = StructureController::getInstance();
CasillaController* casillaController = CasillaController::getInstance();




using json = nlohmann::json;
//VARIABLES GLOBALES
string opc = "";


void OpenFile();
void Reports();
void Players();
void IniciarJuego();
void LetrasAleatorias();
using namespace std;

void LetrasAleatorias() {
    Letter *letras[25];
    //1
    letras[0] = new Letter('A', 1, 12);
    letras[1] = new Letter('E', 1, 12);
    letras[2] = new Letter('O', 1, 9);
    letras[3] = new Letter('I', 1, 6);
    letras[4] = new Letter('S', 1, 6);
    letras[5] = new Letter('N', 1, 5);
    letras[6] = new Letter('L', 1, 4);
    letras[7] = new Letter('R', 1, 5);
    letras[8] = new Letter('U', 1, 5);
    letras[9] = new Letter('T', 1, 4);
    //2 
    letras[10] = new Letter('D', 2, 5);
    letras[11] = new Letter('G', 2, 2);
    //3 
    letras[12] = new Letter('C', 3, 4);
    letras[13] = new Letter('B', 3, 2);
    letras[14] = new Letter('M', 3, 2);
    letras[15] = new Letter('P', 3, 2);
    //4
    letras[16] = new Letter('H', 4, 2);
    letras[17] = new Letter('F', 4, 1);
    letras[18] = new Letter('V', 4, 1);
    letras[19] = new Letter('Y', 4, 1);
    //5
    letras[20] = new Letter('Q', 5, 1);
    //8
    letras[21] = new Letter('J', 8, 1);
    letras[22] = new Letter('Ñ', 8, 1);
    letras[23] = new Letter('X', 8, 1);
    //10
    letras[24] = new Letter('Z', 10, 1);

    //INGRESAR ALEATORIO
    bool Salir = false;
    do {
        int num = rand() % 25;
        //cout << num << " ";
        if (letras[num]->cant > 0) {
            letras[num]->cant = letras[num]->cant- 1;
            controller->queuegame.Push(letras[num]->letter, letras[num]->points, 1);
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
                controller->queuegame.Print();
            }
        }
        
    } while (Salir == false);
}

int main()
{
    setlocale(LC_CTYPE, "Spanish");

    controller->arbol.Insert("Juan");
    controller->arbol.Insert("Pedro");
    controller->arbol.Insert("Paola");
    controller->arbol.Insert("Rafael");


	bool Salir = false;
	do {
		if (opc == "")
		{
			menu.Cls();
			menu.getMenu();
            LetrasAleatorias();

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
        //Jugadores
        else if (opcion == 2) {
            Players();
        }
        //Reportes
        else if (opcion == 3) {
            menu.Cls();
            IniciarJuego();
        }//
        else if (opcion == 5) {
            menu.Cls();
            Reports();
        }
        //salir
        else if (opcion == 5) {
            Salir = true;
        }

		

	} while (Salir == false);


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



            //INSERTA LA DIMENSION DEL TABLERO
            controller->InsertBoardDimention(j3.at("dimension"));

            //INSERTA LAS PALABRAS AL DICCIONARIO
            for (int x = 0; x < j3.at("diccionario").size(); x++)
            {
                controller->InsertDictionary(j3.at("diccionario")[x].at("palabra"));
            }
            
            //INSERTA LAS CASILLAS DOBLES EN UN ARREGLO TEMPORAL, ESE ARREGLO SIRVE AL MOMENTO DE INSERTAR EN LA MATRIZ, BUSCA EN EL ARREGLO LA POSICION 
            //X, Y Y SI EXISTE DEVUELVE SI ES DOBLE
            for (int i = 0; i < j3.at("casillas").at("dobles").size(); i++)
            {
                casillaController->Insert(j3.at("casillas").at("dobles")[i].at("x"), j3.at("casillas").at("dobles")[i].at("y"), true, false);
            }
            //INSERTA LAS CASILLAS DOBLES EN UN ARREGLO TEMPORAL, ESE ARREGLO SIRVE AL MOMENTO DE INSERTAR EN LA MATRIZ, BUSCA EN EL ARREGLO LA POSICION 
            //X, Y Y SI EXISTE DEVUELVE SI ES TRIPLE
            for (int i = 0; i < j3.at("casillas").at("triples").size(); i++)
            {
                casillaController->Insert(j3.at("casillas").at("triples")[i].at("x"), j3.at("casillas").at("triples")[i].at("y"), false, true);
            }


            puts("");
            puts("Archivo encontrado con exito!!");
            puts("");
            puts(".La dimension del tablero fue guardada con exito");
            puts(".Las casillas doble y triples fueron guardadas con exito");
            puts(".El diccionario fue guardado con exito");
            puts("Puede ver las palabras del diccionario en la seccion de repores");
            puts("");
            puts("");
            system("pause");
            break;
           
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

void Players() {
    bool Salir = false;
    menu.Cls();
    puts("Menu Jugadores V1");
    puts("-------------------");
    puts("");

    do
    {
        bool nombreValido = false;
        string username;
        do
        {
            cout << "Inserte el nombre de usuario:";
            cin >> username;

            nombreValido = controller->InsertUser(username);
            if (!nombreValido)
            {
                cout << "El nombre de usuario ya fue agregado anteriormente\n";
            }

        } while (nombreValido == false);
        

        cout << "Desea agregar otro nombre?" << endl;
        cout << "1. Si"<< endl;
        cout << "2. No" << endl;
        cout<< "Ingrese la opcion: ";
        string opc = "";
        cin >> opc;
        if (atoi(opc.c_str()) == 2)
        {
            break;
        }

    } while (-1);
}

void Reports() {
    bool Salir = false;
    do {
        if (opc == "")
        {
            menu.Cls();
            puts("Menu Reportes V1");
            puts("Ingrese el numero del reporte que desea ver");
            puts("--------------------------------------------");
            puts("1. Diccionario");
            puts("2. Usuarios");

            do
            {
                opc = "";
                cout << "\n" << "\t\t\t" << "    Por favor, ingrese el valor: ";
                cin >> opc;

            } while (menu.IsNumber(opc) != true);
        }

        int opcion = atoi(opc.c_str());
        opc = "";

        //Print dictionary
        if (opcion == 1)
        {
            controller->PrintDictionary();
        }
        //Jugadores
        else if (opcion == 2) {
            controller->PrintUsers();
        }
        //Reportes
        else if (opcion == 3) {

        }
        //salir
        else if (opcion == 4) {
            Salir = true;
        }



    } while (Salir == false);

}

void IniciarJuego() {
    int turno = rand() % 1;
    bool Salir = false;
    TreeNode *player1;
    TreeNode* player2;
    LD_LetterPlayer LDplayer1;
    LD_LetterPlayer LDplayer2;
    LD_LetterPlayer LDplayer1Temp;
    LD_LetterPlayer LDplayer2Temp;
    
    for (size_t i = 0; i < 8; i++)
    {
        char let = controller->queuegame.Pop()->letter;
        LDplayer1.Add(let);
        LDplayer1Temp.Add(let);
    }
    for (size_t i = 0; i < 8; i++)
    {
        char let = controller->queuegame.Pop()->letter;
        LDplayer2.Add(let);
        LDplayer2Temp.Add(let);
    }

    do {
        menu.Cls();
        if (controller->boardDimention > 0) {
            if (controller->arbol.getSize() >= 2) {
                puts("Nuevo Juego - Scrabble");
                puts("-------------------");
                puts("");
                cout << "Players:  " << controller->arbol.getSize() << "\n";
                cout << "Matrix:  " << controller->boardDimention << "\n";
                /*
                ---------------------------------------------INICIALIZAR JUGADORES-------------------------------------------
                */
                controller->arbol.Print();
                cout << "Ingrese el nombre del primer jugador." << "\n";
                string p1 = "";
                cin >> p1;
                player1 = controller->arbol.Search(p1);

                cout << "Ingrese el nombre del segundo jugador." << "\n";
                string p2 = "";
                cin >> p2;
                player2 = controller->arbol.Search(p2);


                cout << "--------------------" << "\n";
                cout << "Player 1:  " << player1->username << "\n";
                LDplayer1.Show();
                LDplayer1.Print();
                cout << "Player 2:  " << player2->username << "\n";
                LDplayer2.Show();
                LDplayer2.Print();
                cout << "--------------------" << "\n";

                /*
                --------------------------------------PARTIDA--------------------------------------
                */
                bool partida = false;
                do {
                    if (turno == 0) {
                        bool letras = true;
                        while (letras) {
                            string letra;
                            int x;
                            int y;
                            int opcion;
                            cout << "-------------------------------------------------------" << "\n";
                            cout << "Player 1:  " << player1->username << "\n";
                            LDplayer1.Show();
                            cout << "-------------------------------------------------------" << "\n";
                            std::cout << "Letra: ";
                            std::cin >> letra;
                            std::cout << "\n Posicion X: ";
                            std::cin >> x;
                            std::cout << "\n Posicion Y: ";
                            std::cin >> y;
                            controller->InsertMatrix(x, y, letra, false, false);

                            std::cout << "1. Seguir, 2. Validar ";
                            std::cin >> opcion;
                            if (opcion == 1) {
                                letras = true;
                            }
                            else {
                                letras = false;
                                controller->mat.Print();
                                turno = 1;
                            }
                        }                        
                    } else if (turno == 1) {
                        
                        bool letras = true;
                        while (letras) {
                            string letra;
                            int x;
                            int y;
                            int opcion;
                            cout << "----------------------------------------------------" << "\n";
                            cout << "Player 2:  " << player2->username << "\n";
                            LDplayer2.Show();
                            cout << "----------------------------------------------------" << "\n";
                            std::cout << "Letra: ";
                            cin >> letra;
                            std::cout << "\n Posicion X: ";
                            std::cin >> x;
                            std::cout << "\n Posicion Y: ";
                            std::cin >> y;
                            controller->InsertMatrix(x, y, letra, false, false);

                            std::cout << "1. Seguir, 2. Validar ";
                            std::cin >> opcion;
                            if (opcion == 1) {
                                letras = true;
                            }
                            else {
                                letras = false;
                                controller->PrintMatrix();
                                turno = 0;
                            }
                        }
                        
                    }
                } while (partida == false);


                string opc = "";
                cin >> opc;
                if (atoi(opc.c_str()) == 2)
                {
                    break;
                }
            }
            else {
                puts("Nuevo Juego - Scrabble");
                puts("-------------------");
                puts("");
                puts("Debe tener 2 jugadores o mas.");
                system("pause");
                break;
            }
        }
        else {
            puts("Nuevo Juego - Scrabble");
            puts("-------------------");
            puts("");
            puts("Debe configurar la dimension del tablero.");
            system("pause");
            break;
        }
    }  while (Salir == false);
    
}
