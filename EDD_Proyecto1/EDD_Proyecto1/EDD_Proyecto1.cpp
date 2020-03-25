

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
#include <time.h>
#include <math.h>

Menu menu;
StructureController* controller = StructureController::getInstance();
CasillaController* casillaController = CasillaController::getInstance();




using json = nlohmann::json;
//VARIABLES GLOBALES
string opc = "";


void OpenFile();
void Reports();
void Players();
void PlayGame();
void LetrasAleatorias();
using namespace std;

void LetrasAleatorias() {
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


            controller->PushGameChip(letras[num]->letter, letras[num]->points, 1);
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

int main()
{
    setlocale(LC_ALL, "es_ES");
    //setlocale(LC_CTYPE, "Spanish");

    controller->arbol.Insert("Juan");
    controller->arbol.Insert("Pedro");
    controller->arbol.Insert("Paola");
    controller->arbol.Insert("Rafael");
    /*controller->mat.InsertElement(1, 1, "h", 0,  false, false);
    controller->mat.InsertElement(2, 1, "o", 0, false, false);
    controller->mat.InsertElement(3, 1, "l", 0, false, false);
    controller->mat.InsertElement(4, 1, "a", 0, false, false);
    controller->mat.InsertElement(5, 1, "L", 0, false, false);
    controller->mat.InsertElement(1, 10, "m", 0, false, false);
    controller->mat.InsertElement(2, 10, "u", 0, false, false);
    controller->mat.InsertElement(3, 10, "n", 0, false, false);
    controller->mat.InsertElement(4, 10, "d", 0, false, false);
    controller->mat.InsertElement(5, 10, "o", 0, false, false);
    controller->mat.InsertElement(1, 15, "p", 0, false, false);
    controller->mat.InsertElement(2, 15, "r", 0, false, false);
    controller->mat.InsertElement(3, 15, "o", 0, false, false);
    controller->mat.InsertElement(4, 15, "y", 0, false, false);
    controller->mat.InsertElement(5, 15, "e", 0, false, false);
    controller->mat.InsertElement(6, 15, "c", 0, false, false);
    controller->mat.InsertElement(7, 15, "t", 0, false, false);
    controller->mat.InsertElement(8, 15, "e", 0, false, false);
    controller->mat.Print();*/

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
            PlayGame();
        }//
        else if (opcion == 4) {
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
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Ingrese la opcion: ";
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

void PlayGame() {
    int turno = rand() % 1;
    bool Salir = false;
    TreeNode* player1;
    TreeNode* player2;
    LD_LetterPlayer LDplayer1;
    LD_LetterPlayer LDplayer2;

    LD_LetterPlayer LDplayer1Temp;
    LD_LetterPlayer LDplayer2Temp;



    int pointPlayer1 = 0;
    int pointPlayer1Temp = 0;

    int pointPlayer2 = 0;
    int pointPlayer2Temp = 0;

    LDplayer1.Add("H", 4);
    LDplayer1.Add("O", 1);
    LDplayer1.Add("L", 1);
    LDplayer1.Add("A", 1);
    LDplayer1.Add("D", 2);
    LDplayer1.Add("A", 1);
    LDplayer1.Add("F", 4);



    LDplayer2.Add("M", 3);
    LDplayer2.Add("U", 1);
    LDplayer2.Add("N", 1);
    LDplayer2.Add("D", 2);
    LDplayer2.Add("O", 1);
    LDplayer2.Add("A", 1);
    LDplayer2.Add("F", 4);

    /*for (size_t i = 0; i < 8; i++)
    {
        GameChipNode* let = controller->PopChip();
        LDplayer1.Add(let->letter, let->points);
        LDplayer1Temp.Add(let->letter, let->points);
    }
    for (size_t i = 0; i < 8; i++)
    {
        GameChipNode* let = controller->PopChip();
        LDplayer2.Add(let->letter, let->points);
        LDplayer2Temp.Add(let->letter, let->points);
    }*/

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
                cout << "Player 2:  " << player2->username << "\n";
                LDplayer2.Show();
                cout << "--------------------" << "\n";

                system("pause");
                /*
                ----------------------------------------------------------PARTIDA-------------------------------------------------
                */
                bool partida = false;
                do {

                    if (turno == 0) {

                        LDplayer1.Print();
                        menu.Cls();

                        cout << "-------------------------Turno-------------------------" << "\n";
                        cout << "Player 1:  " << player1->username << "\n";
                        cout << "Punteo:  " << pointPlayer1 << "\n";
                        LDplayer1.Show();
                        cout << "-------------------------------------------------------" << "\n";
                        cout << "1. Jugar" << endl;
                        cout << "2. Cambiar Fichas" << endl;

                        string opc1 = "";
                        do
                        {
                            opc1 = "";
                            cout << "\n" << "Por favor, ingrese el valor: ";
                            cin >> opc1;

                        } while (menu.IsNumber(opc1) != true);


                        bool letras = true;
                        while (letras) {
                            string letra;
                            int x;
                            int y;
                            int opcion;

                            //JUGAR DIRECTAMENTE
                            if (opc1 == "1")
                            {
                                menu.Cls();
                                cout << "-------------------------Turno-------------------------" << "\n";
                                cout << "Player 1:  " << player1->username << "\n";
                                cout << "Punteo:  " << pointPlayer1 << "\n";
                                LDplayer1.Show();
                                cout << "-------------------------------------------------------" << "\n";

                                std::cout << "Letra: ";
                                std::cin >> letra;
                                std::cout << "\n Posicion X: ";
                                std::cin >> x;
                                std::cout << "\n Posicion Y: ";
                                std::cin >> y;
                                LetterPlayer* letterPlayerPoint;
                                letterPlayerPoint = LDplayer1.Search(letra);
                                if (letterPlayerPoint != NULL) {
                                    controller->InsertMatrix(x, y, letra, letterPlayerPoint->punteo, false, false);
                                    LDplayer1.Eliminar(letra);
                                    //Agrega las letras eliminadas a un arreglo temporal
                                    LDplayer1Temp.Add(letterPlayerPoint->letter, letterPlayerPoint->punteo, x, y);
                                    /*
                                    -----------------------------------------------------AGREGAR VALIDACION SI ES DOBLE O TRIPLE PUNTEO LA CASILLA MULTIPLICAR EL PUNTEO-------------------------------
                                    */
                                }
                                std::cout << "1. Seguir, 2. Validar, 3. Cambiar Turno, 4. Terminar Juego " << endl;
                                std::cout << "Elija una opcion: ";

                                std::cin >> opcion;
                                if (opcion == 1) {
                                    letras = true;
                                }
                                else if(opcion == 2) {
                                    /*
                                     ----------------------------------------------------------VALIDACION PALABRA-------------------------------------------------
                                     */
                                    controller->PrintMatrix();
                                    //VALIDAR POSICION DE PALABRA
                                    string orientacion;
                                    int posX;
                                    int posXTemp;
                                    int posY;
                                    int posYTemp;
                                    int longitud;
                                    std::cout << "\n Posicion X: ";
                                    std::cin >> posX;
                                    posXTemp = posX;
                                    std::cout << "\n Posicion Y: ";
                                    std::cin >> posY;
                                    posYTemp = posY;
                                    std::cout << "\n Longitud de palabra: ";
                                    std::cin >> longitud;
                                    std::cout << "\n Orientacion de Palabra: (V/H)";
                                    std::cin >> orientacion;
                                    string palabra;

                                    MatrixNode* temp = NULL;
                                    for (size_t i = 0; i < longitud; i++)
                                    {
                                        temp = controller->SearchLetter(posX, posY);

                                        if (orientacion == "V") {
                                            posY++;
                                        }
                                        else if (orientacion == "H") {
                                            posX++;
                                        }

                                        if (temp != NULL)
                                        {
                                            palabra = palabra + temp->data;
                                            if (temp->isTriple == true) {
                                                pointPlayer1Temp = pointPlayer1Temp + (3 * temp->points);
                                            }
                                            else if (temp->isDouble == true) {
                                                pointPlayer1Temp = pointPlayer1Temp + (2 * temp->points);
                                            }
                                            else {
                                                pointPlayer1Temp = pointPlayer1Temp + temp->points;
                                            }
                                        }
                                        else
                                        {
                                            cout << "No Se contro ningun elemento en la posicion X:" << (posX - 1) << ", Y:" << (posY - 1);
                                            letras = false;
                                            turno = 1;
                                        }

                                    }
                                    cout << "----------------------------------\n";
                                    cout << "|Buscando: " << palabra << endl;
                                    cout << "----------------------------------\n";

                                    DictionaryNode* p = controller->SearchWord(palabra);
                                    if (p != NULL) {
                                        cout << "----------------------------------\n";
                                        cout << "|        Palabra encontrada      |\n";
                                        cout << "----------------------------------\n";
                                        //SI ENCUENTRA LA PALABRA SE AGREGA NUEVOS ELEMENTOS A LA LISTA
                                        //SE LE ASIGNAN NUEVOS VALORES A LA LISTA
                                        LDplayer1Temp.Clean();
                                        int newLenght = LDplayer1.GetLenght();

                                        if (newLenght == 0)
                                        {
                                            newLenght = 7;
                                        }
                                        for (size_t i = 0; i < newLenght; i++)
                                        {
                                            GameChipNode* let = controller->PopChip();
                                            LDplayer1.Add(let->letter, let->points);
                                            //LDplayer1Temp.Add(let->letter, let->points);
                                        }
                                        //LE SUMA AL PLAYER LOS PUNTOS OBTENIDOS
                                        pointPlayer1 = pointPlayer1 + pointPlayer1Temp;
                                        //LIMPIA LOS TEMPORALES
                                        pointPlayer1Temp = 0;

                                    }
                                    else {
                                        //LIMPIA LOS TEMPORALES
                                        pointPlayer1Temp = 0;

                                        cout << "-------------------------------------\n";
                                        cout << "|        Palabra NO encontrada       |\n";
                                        cout << "-------------------------------------\n";


                                        //REGRESA LAS PALABRAS A LA LISTA ORIGINAL DEL USUARIO
                                        LD_LetterPlayer temp = LDplayer1Temp;

                                        while (temp.first != NULL)
                                        {
                                            controller->DeleteMatrixNode(temp.first->x, temp.first->y);
                                            LDplayer1.Add(temp.first->letter, temp.first->punteo);
                                            temp.first = temp.first->next;

                                        }
                                        system("pause");
                                    }
                                    letras = false;
                                    turno = 1;
                                }
                                else if (opcion == 3) {
                                    letras = false;
                                    turno = 1;
                                }
                                else if ( opcion == 4 ) {

                                    cout << "\n Salir acabara con la partida y se le dara la victoria al otro jugador";

                                    cout << "\n Esta seguro que desea salir? ";
                                    cout << "\n 1. Si, Otro numero. No";
                                    string opc2 = "";
                                    do
                                    {
                                        cout << "\n Ingrese una opcion: ";
                                        cin >> opc2;

                                    } while (!menu.IsNumber(opc2));

                                    if (opc2 == "1")
                                    {

                                        partida = true;
                                        turno = 2;
                                        break;
                                    }
                                    else
                                    {
                                        letras = false;
                                        turno = 0;
                                    }

                                }

                            }
                            else if (opc1 == "2")
                            {
                                bool endReplace = true;

                                //Crea un bucle por si desea seguir reemplazando
                                while (endReplace)
                                {

                                    LetterPlayer* letterPlayerPoint = NULL;
                                    do
                                    {
                                        controller->PrintGameChips();
                                        menu.Cls();

                                        cout << "-------------------------Turno-------------------------" << "\n";
                                        cout << "Player 1:  " << player1->username << "\n";
                                        cout << "Punteo:  " << pointPlayer1 << "\n";
                                        LDplayer1.Show();
                                        cout << "-------------------------------------------------------" << "\n";

                                        cout << "Letra por reemplazar: ";
                                        cin >> letra;


                                        letterPlayerPoint = LDplayer1.Search(letra);
                                        if (letterPlayerPoint != NULL) {
                                            //Se hace push otra vez a la cola
                                            controller->PushGameChip(letterPlayerPoint->letter, letterPlayerPoint->punteo, 1);
                                            LDplayer1.Eliminar(letra);

                                            //Inserta a las fichas del jugador la ficha que esta al inicio de la cola
                                            GameChipNode* let = controller->PopChip();
                                            LDplayer1.Add(let->letter, let->points);
                                            LDplayer1Temp.Add(let->letter, let->points);

                                        }


                                    } while (letterPlayerPoint == NULL);
                                    LDplayer1.Print();
                                    menu.Cls();
                                    cout << "-------------------------Turno-------------------------" << "\n";
                                    cout << "Player 1:  " << player1->username << "\n";
                                    cout << "Punteo:  " << pointPlayer1 << "\n";
                                    LDplayer1.Show();
                                    cout << "-------------------------------------------------------" << "\n";

                                    string opcRemplazo = "";
                                    cout << "Desea seguir reemplazando?" << endl;
                                    cout << "1. Si" << endl;
                                    cout << "Otro. No" << endl;
                                    do
                                    {
                                        cout << "Elija una opcion: ";
                                        cin >> opcRemplazo;
                                    } while (!menu.IsNumber(opcRemplazo));
                                    if (opcRemplazo != "1")
                                    {
                                        endReplace = false;
                                    }
                                }


                                letras = false;
                                turno = 1;


                            }




                        }
                    }
                    else if (turno == 1) {


                        LDplayer2.Print();
                        menu.Cls();

                        cout << "-------------------------Turno-------------------------" << "\n";
                        cout << "Player 2:  " << player2->username << "\n";
                        cout << "Punteo:  " << pointPlayer2 << "\n";
                        LDplayer2.Show();
                        cout << "-------------------------------------------------------" << "\n";
                        cout << "1. Jugar" << endl;
                        cout << "2. Cambiar Fichas" << endl;

                        string opc1 = "";
                        do
                        {
                            opc1 = "";
                            cout << "\n" << "Por favor, ingrese el valor: ";
                            cin >> opc1;

                        } while (menu.IsNumber(opc1) != true);


                        /*
                        -----------------------------------------------------------------------JUGADOR 2-------------------------------------------
                        REPLICA DEL 1
                        */
                        bool letras = true;
                        while (letras) {
                            string letra;
                            int x;
                            int y;
                            int opcion;


                            if (opc1 == "1")
                            {

                                std::cout << "Letra: ";
                                std::cin >> letra;
                                std::cout << "\n Posicion X: ";
                                std::cin >> x;
                                std::cout << "\n Posicion Y: ";
                                std::cin >> y;
                                LetterPlayer* letterPlayerPoint;
                                letterPlayerPoint = LDplayer2.Search(letra);
                                if (letterPlayerPoint != NULL) {
                                    controller->InsertMatrix(x, y, letra, letterPlayerPoint->punteo, false, false);
                                    LDplayer2.Eliminar(letra);
                                    /*
                                    -----------------------------------------------------AGREGAR VALIDACION SI ES DOBLE O TRIPLE PUNTEO LA CASILLA MULTIPLICAR EL PUNTEO-------------------------------
                                    */
                                }
                                std::cout << "1. Seguir, 2. Validar, 3. Finalizar ";
                                std::cin >> opcion;
                                if (opcion == 1) {
                                    letras = true;
                                }
                                else {
                                    /*
                                     ----------------------------------------------------------VALIDACION PALABRA-------------------------------------------------
                                     */
                                    controller->PrintMatrix();
                                    //VALIDAR POSICION DE PALABRA
                                    string orientacion;
                                    int posX;
                                    int posXTemp;
                                    int posY;
                                    int posYTemp;
                                    int longitud;
                                    std::cout << "\n Posicion X: ";
                                    std::cin >> posX;
                                    posXTemp = posX;
                                    std::cout << "\n Posicion Y: ";
                                    std::cin >> posY;
                                    posYTemp = posY;
                                    std::cout << "\n Longitud de palabra: ";
                                    std::cin >> longitud;
                                    std::cout << "\n Orientacion de Palabra: (V/H)";
                                    std::cin >> orientacion;
                                    string palabra;
                                    for (size_t i = 0; i < longitud; i++)
                                    {
                                        if (orientacion == "V") {
                                            MatrixNode* temp = controller->SearchLetter(posX, posY);


                                            palabra = palabra + temp->data;
                                            if (temp->isTriple == true) {
                                                pointPlayer2 = pointPlayer2 + (3 * temp->points);
                                            }
                                            else if (temp->isDouble == true) {
                                                pointPlayer2 = pointPlayer2 + (2 * temp->points);
                                            }
                                            else {
                                                pointPlayer2 = pointPlayer2 + temp->points;
                                            }
                                            posY++;
                                        }
                                        else if (orientacion == "H") {
                                            MatrixNode* temp = controller->mat.SearchLetra(posX, posY);
                                            palabra = palabra + temp->data;
                                            if (temp->isTriple == true) {
                                                pointPlayer2 = pointPlayer2 + (3 * temp->points);
                                            }
                                            else if (temp->isDouble == true) {
                                                pointPlayer2 = pointPlayer2 + (2 * temp->points);
                                            }
                                            else {
                                                pointPlayer2 = pointPlayer2 + temp->points;
                                            }
                                            posX++;
                                        }
                                    }
                                    DictionaryNode* p = controller->SearchWord(palabra);
                                    if (p != NULL) {
                                        std::cout << "\n----------------PALABRA------------------ ";
                                        std::cout << palabra;
                                        std::cout << "\n----------------PALABRA------------------ ";
                                        //SI ENCUENTRA LA PALABRA SE LIMPIA LA LISTA
                                        LDplayer2.Clean();
                                        LDplayer2Temp.Clean();
                                        //SE LE ASIGNAN NUEVOS VALORES A LA LISTA
                                        for (size_t i = 0; i < 8; i++)
                                        {
                                            GameChipNode* let = controller->queuegame.Pop();
                                            LDplayer2.Add(let->letter, let->points);
                                            LDplayer2Temp.Add(let->letter, let->points);
                                        }
                                    }
                                    else {
                                        std::cout << "\n----------------PALABRA NOT FOUND------------------ ";
                                        /*
                                            SI NO SE ENCUENTRA LA PALABRA RECORRE DE NUEVO LA MATRIZ CON LOS PARAMETROS ANTERIORES
                                            Y DE AHI LE VA RESTANDO LO QUE LE SUMO DE PUNTEO :( JAJA
                                        */
                                        for (size_t i = 0; i < longitud; i++)
                                        {
                                            if (orientacion == "V") {
                                                MatrixNode* temp = controller->mat.SearchLetra(posXTemp, posYTemp);
                                                if (temp->isTriple == true) {
                                                    pointPlayer1 = pointPlayer1 - (3 * temp->points);
                                                }
                                                else if (temp->isDouble == true) {
                                                    pointPlayer1 = pointPlayer1 - (2 * temp->points);
                                                }
                                                else {
                                                    pointPlayer1 = pointPlayer1 - temp->points;
                                                }
                                                posYTemp++;
                                            }
                                            else if (orientacion == "H") {
                                                MatrixNode* temp = controller->mat.SearchLetra(posXTemp, posYTemp);
                                                if (temp->isTriple == true) {
                                                    pointPlayer1 = pointPlayer1 - (3 * temp->points);
                                                }
                                                else if (temp->isDouble == true) {
                                                    pointPlayer1 = pointPlayer1 - (2 * temp->points);
                                                }
                                                else {
                                                    pointPlayer1 = pointPlayer1 - temp->points;
                                                }
                                                posXTemp++;
                                            }
                                        }
                                    }
                                    letras = false;
                                    turno = 0;
                                }

                            }
                            else if (opc1 == "2")
                            {


                                bool endReplace = true;

                                //Crea un bucle por si desea seguir reemplazando
                                while (endReplace)
                                {

                                    LetterPlayer* letterPlayerPoint = NULL;
                                    do
                                    {
                                        controller->PrintGameChips();
                                        menu.Cls();

                                        cout << "-------------------------Turno-------------------------" << "\n";
                                        cout << "Player 2:  " << player2->username << "\n";
                                        cout << "Punteo:  " << pointPlayer2 << "\n";
                                        LDplayer2.Show();
                                        cout << "-------------------------------------------------------" << "\n";

                                        cout << "Letra por reemplazar: ";
                                        cin >> letra;


                                        letterPlayerPoint = LDplayer2.Search(letra);
                                        if (letterPlayerPoint != NULL) {
                                            //Se hace push otra vez a la cola
                                            controller->PushGameChip(letterPlayerPoint->letter, letterPlayerPoint->punteo, 1);
                                            LDplayer2.Eliminar(letra);

                                            //Inserta a las fichas del jugador la ficha que esta al inicio de la cola
                                            GameChipNode* let = controller->PopChip();
                                            LDplayer2.Add(let->letter, let->points);
                                            LDplayer2Temp.Add(let->letter, let->points);

                                        }


                                    } while (letterPlayerPoint == NULL);
                                    LDplayer2.Print();
                                    menu.Cls();
                                    cout << "-------------------------Turno-------------------------" << "\n";
                                    cout << "Player 2:  " << player2->username << "\n";
                                    cout << "Punteo:  " << pointPlayer2 << "\n";
                                    LDplayer2.Show();
                                    cout << "-------------------------------------------------------" << "\n";

                                    string opcRemplazo = "";
                                    cout << "Desea seguir reemplazando?" << endl;
                                    cout << "1. Si" << endl;
                                    cout << "Otro. No" << endl;
                                    do
                                    {
                                        cout << "Elija una opcion: ";
                                        cin >> opcRemplazo;
                                    } while (!menu.IsNumber(opcRemplazo));
                                    if (opcRemplazo != "1")
                                    {
                                        endReplace = false;
                                    }
                                }
                                letras = false;
                                turno = 0;


                            }

                        }

                    }
                } while (partida == false);


                
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
    } while (Salir == false);

}
