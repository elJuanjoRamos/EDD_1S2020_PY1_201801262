

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
#include "LD_LetterPlayer.h"
#include <math.h>
#include <time.h>

Menu menu;
StructureController* controller = StructureController::getInstance();
CasillaController* casillaController = CasillaController::getInstance();
using json = nlohmann::json;
//VARIABLES GLOBALES
string opc = "";

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
int turno = 0;

bool letras = true;
bool partida = false;

void OpenFile();
void Reports();
void Players();
void PlayGame();
void ValidateWord(string player);
void ValidateInsert(string name, string letter, int points);
void GiveUp(string player);
void ChangeChips(string player, string a);
using namespace std;

void Temp();

int main()
{
    setlocale(LC_ALL, "es_ES");
    //setlocale(LC_CTYPE, "Spanish");

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
        //Juego
        else if (opcion == 3) {

            menu.Cls();
            if (controller->queuegame.IsEmpty())
            {
                controller->RandomLetters();
            }
            PlayGame();
        }//Reportes
        else if (opcion == 4) {
            menu.Cls();
            Reports();
        }
        //salir
        else if (opcion == 5) {
            Salir = true;
        }
        else if (opcion == 6)
        {
            Temp();
        }



    } while (Salir == false);

}

void OpenFile() {
    do
    {
        puts("Carga de Archivos Simple v1");
        puts("Ingrese el nombre del archivo");
        puts("------------------------------------");
        cout << "\n| Ingrese el nombre del archivo:";
        string fileName;
        string line;
        getline(cin, fileName);


        puts("------------------------------------");
        
        std::ifstream i;

        i.open(fileName + ".json", ios::in);

        if (!i.fail())
        {

            std::ifstream i(fileName + ".json");
            json j3;
            i >> j3;

            //INSERTA LA DIMENSION DEL TABLERO
            controller->InsertBoardDimention(j3.at("dimension"));

            puts("");
            puts("Archivo encontrado con exito!!");
            puts("");
            cout << "----------------------" << endl;
            cout << "Dimesion del tablero: " << j3.at("dimension") << endl;
            cout << "----------------------" << endl;
            cout << "Dictionario: " << endl;
            controller->ClearDictionary();
            //INSERTA LAS PALABRAS AL DICCIONARIO
            for (int x = 0; x < j3.at("diccionario").size(); x++)
            {
                controller->InsertDictionary(j3.at("diccionario")[x].at("palabra"));
                cout << "Word: " << j3.at("diccionario")[x].at("palabra") << endl;
            }
            cout << "----------------------" << endl;
            cout << "Casillas Dobles: " << endl;

            //INSERTA LAS CASILLAS DOBLES EN UN ARREGLO TEMPORAL, ESE ARREGLO SIRVE AL MOMENTO DE INSERTAR EN LA MATRIZ, BUSCA EN EL ARREGLO LA POSICION 
            //X, Y Y SI EXISTE DEVUELVE SI ES DOBLE

            casillaController->Clear();
            for (int i = 0; i < j3.at("casillas").at("dobles").size(); i++)
            {
                casillaController->Insert(j3.at("casillas").at("dobles")[i].at("x"), j3.at("casillas").at("dobles")[i].at("y"), true, false);
                cout << "X: " << j3.at("casillas").at("dobles")[i].at("x") << ", Y: " << j3.at("casillas").at("dobles")[i].at("y") << endl;
            }
            //INSERTA LAS CASILLAS DOBLES EN UN ARREGLO TEMPORAL, ESE ARREGLO SIRVE AL MOMENTO DE INSERTAR EN LA MATRIZ, BUSCA EN EL ARREGLO LA POSICION 
            //X, Y Y SI EXISTE DEVUELVE SI ES TRIPLE
            cout << "----------------------" << endl;
            cout << "Casillas Triples: " << endl;

            for (int i = 0; i < j3.at("casillas").at("triples").size(); i++)
            {
                casillaController->Insert(j3.at("casillas").at("triples")[i].at("x"), j3.at("casillas").at("triples")[i].at("y"), false, true);
                cout << "X: " << j3.at("casillas").at("triples")[i].at("x") << ", Y: " << j3.at("casillas").at("triples")[i].at("y") << endl;
            }
            cout << "----------------------" << endl;
            system("pause");
            break;

        }
        else
        {
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
            puts("2. Cola de fichas");
            puts("3. Usuarios");
            puts("4. Puntajes");
            puts("5. Ultimo Tablero");
            puts("6. Historial de partidas");
            puts("7. Salir");

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
        //Fichas
        if (opcion == 2)
        {
            if (controller->queuegame.IsEmpty())
            {
                controller->RandomLetters();
            }
            controller->queuegame.Print();
        }
        //Jugadores
        else if (opcion == 3) {

            menu.Cls();
            cout << "----------REPORTE USUARIOS----------\n";
            cout << "1.Arbol\n";
            cout << "2.Arbol PreOrden\n";
            cout << "3.Arbol InOrder\n";
            cout << "4.Arbol PostOrden\n";
            cout << "Ingrese la opcion: ";
            int opcU = 0;
            cin >> opcU;
            if (opcU == 1)
            {
                controller->PrintUsers("all");
            }
            else if (opcU == 2)
            {
                controller->PrintUsers("preorden");
            }
            else if (opcU == 3)
            {
                controller->PrintUsers("inorden");
            }
            else if (opcU == 4)
            {
                controller->PrintUsers("postorden");
            }
        }
        //Puntajes
        else if (opcion == 4) {
            controller->PrintUsers("all");
            puts("Ingrese El nombre de usuario para ver sus puntajes");
            puts("O ingrese ALL para ver todos los puntajes");
            string user = "";
            cout << "Nombre: ";
            cin >> user;
            controller->PrintScore(user);
        }
        else if (opcion == 5)
        {
            controller->PrintMatrix();
        }
        //Historial de partidas
        else if (opcion == 6)
        {
            controller->PrintHistory();
        }
        //salir
        else if (opcion == 7) {
            Salir = true;
        }
    } while (Salir == false);

}

void PlayGame() {
    srand(time(NULL));
    turno = rand() % 2;

    bool Salir = false;
    partida = false;
    player1 = NULL;
    player2 = NULL;
    LDplayer1.Clean();
    LDplayer2.Clean();

    LDplayer1Temp.Clean();
    LDplayer2Temp.Clean();


    pointPlayer1 = 0;
    pointPlayer1Temp = 0;

    pointPlayer2 = 0;
    pointPlayer2Temp = 0;

    LDplayer1.Add("M", 3);
    LDplayer1.Add("U", 1);
    LDplayer1.Add("N", 1);
    LDplayer1.Add("D", 2);
    LDplayer1.Add("O", 1);
    LDplayer1.Add("A", 1); 
    LDplayer1.Add("A", 1);

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
                cout << "Cant. de Jugadores:  " << controller->arbol.getSize() << "\n";
                cout << "Tam de tablero:  " << controller->boardDimention << "\n";
                /*
                ---------------------------------------------INICIALIZAR JUGADORES-------------------------------------------
                */
                controller->PrintUsers("all");

                do
                {
                    cout << " " << endl;
                    cout << "Ingrese el nombre del primer jugador: ";
                    string p1 = "";
                    cin >> p1;

                    player1 = controller->SearchUser(p1);
                    if (player1 == NULL)
                    {
                        cout << " " << endl;
                        puts("Jugador no encontrado\n");
                    }
                } while (player1 == NULL);

                do
                {
                    cout << " " << endl;
                    cout << "Ingrese el nombre del segundo jugador: ";
                    string p2 = "";
                    cin >> p2;
                    player2 = controller->SearchUser(p2);
                    if (player2 == NULL)
                    {
                        cout << " " << endl;
                        puts("Jugador no encontrado\n");
                    }
                } while (player2 == NULL);

                cout << " " << "\n";
                cout << "Jugadores seleccionados" << "\n";
                cout << "-----------------------" << "\n";
                cout << "Player 1:  " << player1->username << "\n";
                LDplayer1.Show();
                cout << "Player 2:  " << player2->username << "\n";
                LDplayer2.Show();
                cout << "-----------------------" << "\n";

                system("pause");
                /*
                ----------------------------------------------------------PARTIDA-------------------------------------------------
                */
                do {
                    if (turno == 0) {

                        string a = "Fichas de " + player1->username;
                        LDplayer1.Print(a);
                        menu.Cls();

                        cout << "-------------------------Turno-------------------------" << "\n";
                        cout << "Player 1:  " << player1->username << "\n";
                        cout << "Punteo:  " << pointPlayer1 << "\n";
                        LDplayer1.Show();
                        cout << "-------------------------------------------------------" << "\n";
                        cout << "1. Jugar" << endl;
                        cout << "2. Cambiar Fichas" << endl;
                        cout << "3. Pasar Turno" << endl;
                        cout << "4. Terminar Juego" << endl;

                        string opc1 = "";
                        do
                        {
                            opc1 = "";
                            cout << "\n" << "Por favor, ingrese un valor valido: ";
                            cin >> opc1;

                        } while (menu.IsNumber(opc1) != true && (opc1 == "1" || opc1 == "2" || opc1 == "3"));
                        string letra;
                        //JUGAR DIRECTAMENTE
                        if (opc1 == "1")
                        {
                            letras = true;
                            while (letras)
                            {

                                int opcion;
                                menu.Cls();
                                cout << "-------------------------Turno-------------------------" << "\n";
                                cout << "Player 1:  " << player1->username << "\n";
                                cout << "Punteo:  " << pointPlayer1 << "\n";
                                LDplayer1.Show();
                                cout << "-------------------------------------------------------" << "\n";

                                LetterPlayer* letterPlayerPoint;

                                //VALIDACION DE LETRA, EL BUCLE SE REPITE SI NO ENCUENTRA LA LETRA EN LA LISTA DEL USUARIO
                                do
                                {
                                    std::cout << "Letra: ";
                                    std::cin >> letra;
                                    letterPlayerPoint = LDplayer1.Search(letra);

                                } while (letterPlayerPoint == NULL);

                                //SE ENVIAN LOS PARAMETROS A INSERTAR
                                ValidateInsert("player1", letra, letterPlayerPoint->punteo);

                                std::cout << "\n1. Seguir, 2. Validar, 3. Terminar Juego " << endl;
                                std::cout << "Elija una opcion: ";

                                std::cin >> opcion;
                                if (opcion == 1) {
                                    letras = true;
                                }
                                else if (opcion == 2) {
                                    ValidateWord("player1");
                                    letras = false;
                                    turno = 1;
                                }
                                //Rendirse
                                else if (opcion == 3) {

                                    GiveUp("player1");
                                }
                            }

                        }
                        //CAMBIAR FICHAS
                        else if (opc1 == "2")
                        {
                            ChangeChips("player1", a);
                            turno = 1;
                        }
                        //PASAR TURNO
                        else if (opc1 == "3")
                        {
                            turno = 1;
                        }
                        // TERMINAR JUEGO
                        else if (opc1 == "4")
                        {
                            GiveUp("player1");
                        }


                    }
                    else if (turno == 1)
                    {
                        string a = "Fichas de " + player2->username;
                        LDplayer2.Print(a);
                        menu.Cls();

                        cout << "-------------------------Turno-------------------------" << "\n";
                        cout << "Player 2:  " << player2->username << "\n";
                        cout << "Punteo:  " << pointPlayer2 << "\n";
                        LDplayer2.Show();
                        cout << "-------------------------------------------------------" << "\n";
                        cout << "1. Jugar" << endl;
                        cout << "2. Cambiar Fichas" << endl;
                        cout << "3. Pasar Turno" << endl;
                        cout << "4. Terminar Juego" << endl;

                        string opc1 = "";
                        do
                        {
                            opc1 = "";
                            cout << "\n" << "Por favor, ingrese un valor valido: ";
                            cin >> opc1;

                        } while (menu.IsNumber(opc1) != true && (opc1 == "1" || opc1 == "2" || opc1 == "3"));
                        string letra;
                        //JUGAR DIRECTAMENTE
                        if (opc1 == "1")
                        {
                            letras = true;
                            while (letras)
                            {

                                int opcion;
                                menu.Cls();
                                cout << "-------------------------Turno-------------------------" << "\n";
                                cout << "Player 2:  " << player2->username << "\n";
                                cout << "Punteo:  " << pointPlayer2 << "\n";
                                LDplayer2.Show();
                                cout << "-------------------------------------------------------" << "\n";

                                LetterPlayer* letterPlayerPoint;

                                //VALIDACION DE LETRA, EL BUCLE SE REPITE SI NO ENCUENTRA LA LETRA EN LA LISTA DEL USUARIO
                                do
                                {
                                    std::cout << "Letra: ";
                                    std::cin >> letra;
                                    letterPlayerPoint = LDplayer2.Search(letra);

                                } while (letterPlayerPoint == NULL);

                                //SE ENVIAN LOS PARAMETROS A INSERTAR
                                ValidateInsert("player2", letra, letterPlayerPoint->punteo);

                                std::cout << "\n1. Seguir, 2. Validar, 3. Terminar Juego " << endl;
                                std::cout << "Elija una opcion: ";

                                std::cin >> opcion;
                                if (opcion == 1) {
                                    letras = true;
                                }
                                else if (opcion == 2) {
                                    ValidateWord("player2");
                                    letras = false;
                                    turno = 0;
                                }
                                //Rendirse
                                else if (opcion == 3) {

                                    GiveUp("player2");
                                }
                            }

                        }
                        //CAMBIAR FICHAS
                        else if (opc1 == "2")
                        {
                            ChangeChips("player2", a);
                            turno = 0;
                        }
                        //PASAR TURNO
                        else if (opc1 == "3")
                        {
                            turno = 0;
                        }
                        // TERMINAR JUEGO
                        else if (opc1 == "4")
                        {
                            GiveUp("player2");
                        }
                    }
                } while (partida == false);

                break;
                Salir = true;

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

//VALIDAR LA INSERCION DE NODOS EN LA MATRIZ
void ValidateInsert(string name, string letter, int points) {
    int x;
    int y;
    do
    {
        std::cout << "\n Posicion X: ";
        std::cin >> x;
        std::cout << "\n Posicion Y: ";
        std::cin >> y;
        if (!(controller->ValidateInsertInBoard(x, y)))
        {
            std::cout << "\n Posicion XY: NO VALIDA\n";
        }
        if (controller->SearchLetter(x, y) != NULL)
        {
            std::cout << "\n Posicion XY ya ocupada\n";
        }
    } while ((!(controller->ValidateInsertInBoard(x, y))) || (controller->SearchLetter(x, y) != NULL));
    controller->InsertMatrix(x, y, letter, points, false, false);

    if (name == "player1")
    {
        //VALIDACION DE POSICION, EL BUCLE SE REPITE SI LA POSICION XY NO ES VALDIA
         //INSERTAR EL ELEMENTO EN LA MATRIZ 
        LDplayer1.Eliminar(letter);
        //Agrega las letras eliminadas a un arreglo temporal
        LDplayer1Temp.Add(letter, points, x, y);
    }
    else
    {
        //VALIDACION DE POSICION, EL BUCLE SE REPITE SI LA POSICION XY NO ES VALDIA
        //INSERTAR EL ELEMENTO EN LA MATRIZ 
        LDplayer2.Eliminar(letter);
        //Agrega las letras eliminadas a un arreglo temporal
        LDplayer2Temp.Add(letter, points, x, y);

    }
}

//VALIDAR LA PALABRA BUSCADA
void ValidateWord(string player) {

    /*----------------------------VALIDACION PALABRA----------------------------*/

    controller->PrintMatrix();
    //VALIDAR POSICION DE PALABRA
    string orientacion;
    int pointsTemp = 0;
    int posX;
    int posXTemp;
    int posY;
    int posYTemp;
    int longitud;
    //VALIDACION DE QUE LA POSICION A BUSCAR SEA LA CORRECTA
    do
    {
        std::cout << "\n Posicion X: ";
        std::cin >> posX;
        posXTemp = posX;
        std::cout << "\n Posicion Y: ";
        std::cin >> posY;
        posYTemp = posY;
    } while (!(controller->ValidateInsertInBoard(posX, posY)));

    std::cout << "\n Longitud de palabra: ";
    std::cin >> longitud;


    do
    {
        std::cout << "\n Orientacion de Palabra: (V/H): ";
        std::cin >> orientacion;
    } while (menu.IsNumber(orientacion) || (orientacion != "H" && orientacion != "V"));
    
    string palabra;

    MatrixNode* temp = NULL;
    for (size_t i = 0; i < longitud; i++)
    {
        temp = controller->SearchLetter(posX, posY);


        if (temp != NULL)
        {
            if (orientacion == "V") {
                posY++;
                posYTemp = posY;
            }
            else if (orientacion == "H") {
                posX++;
                posXTemp = posX;
            }

            palabra = palabra + temp->data;
            if (temp->isTriple == true) {

                pointsTemp = pointsTemp + (3 * temp->points);
            }
            else if (temp->isDouble == true) {
                pointsTemp = pointsTemp + (2 * temp->points);
            }
            else {
                pointsTemp = pointsTemp + temp->points;
            }
        }
        else
        {
            cout << "No Se contro ningun elemento en la posicion X:" << posX << ", Y:" << posY << endl;
            if (player == "player1")
            {
                turno = 1;
            }
            else
            {
                turno = 0;
            }
            break;
            system("pause");
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
        int newLenght = 0;
        if (player == "player1")
        {
            LDplayer1Temp.Clean();
            newLenght = 7- LDplayer1.GetLenght();

        }
        else
        {
            LDplayer2Temp.Clean();
            newLenght = 7 - LDplayer2.GetLenght();
        }
        for (size_t i = 0; i < newLenght; i++)
        {
            if (!controller->QueueIsEmpty())
            {
                GameChipNode* let = controller->PopChip();
                if (player == "player1")
                {
                    LDplayer1.Add(let->letter, let->points);
                }
                else
                {
                    LDplayer2.Add(let->letter, let->points);
                }
            }
            else
            {
                cout << "-----------------------" << endl;
                cout << "Lista de fichas vacia" << endl;
                cout << "-----------------------" << endl;
                break;
            }
            //LDplayer1Temp.Add(let->letter, let->points);
        }
        //LE SUMA AL PLAYER LOS PUNTOS OBTENIDOS
        if (player == "player1")
        {
            pointPlayer1 = pointPlayer1 + pointsTemp;
            turno = 1;
        }
        else
        {
            pointPlayer2 = pointPlayer2 + pointsTemp;
            turno = 0;
        }
        cout << "Se ha sumado: " << pointsTemp << " pts a su punteo." << endl;
        //LIMPIA LOS TEMPORALES
        pointsTemp = 0;
        system("pause");
    }
    else {
        //LIMPIA LOS TEMPORALES
        pointsTemp = 0;

        cout << "-------------------------------------\n";
        cout << "|        Palabra NO encontrada       |\n";
        cout << "-------------------------------------\n";
        cout << "Las fichas utilizadas se devolveran a su listado\n";


        //REGRESA LAS PALABRAS A LA LISTA ORIGINAL DEL USUARIO
        LD_LetterPlayer temp;

        if (player == "player1")
        {
            temp = LDplayer1Temp;
        }
        else
        {
            temp = LDplayer2Temp;
        }

        while (temp.first != NULL)
        {
            controller->DeleteMatrixNode(temp.first->x, temp.first->y);
            if (player == "player1")
            {
                LDplayer1.Add(temp.first->letter, temp.first->punteo);
            }
            else
            {
                LDplayer2.Add(temp.first->letter, temp.first->punteo);
            }

            temp.first = temp.first->next;

        }
        system("pause");
    }

}

//RENDIRSE
void GiveUp(string player) {


    string winner = "";
    string loser = "";
    int pointsWinner = 0;
    int pointsLoser = 0;



    

    //Si la lista no esta vacia 
    if (!controller->QueueIsEmpty())
    {
        cout << "\n--------------------------------------";
        cout << "\n|               ALERTA                |";
        cout << "\n--------------------------------------";
        cout << "\n Todavia quedan fichas en el juego";
        cout << "\n Salir significa rendirse, esto acabara con la partida y se le dara la victoria al otro jugador";

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
            menu.Cls();

            cout << "\n---------------------------------------";
            cout << "\n|           JUEGO TERMINADO            |";
            cout << "\n---------------------------------------\n";
            
            if (player == "player1")
            {
                winner = player2->username;
                pointsWinner = pointPlayer2;
                loser = player1->username;
                pointsLoser = pointPlayer1;
            }
            else
            {
                winner = player1->username;
                pointsWinner = pointPlayer1;
                loser = player2->username;
                pointsLoser = pointPlayer2;
            }
            cout << "Ganador: " << winner << endl;
            cout << "Puntos: " << pointsWinner << endl;
            cout << "Perdedor: " << loser << endl;
            cout << "Puntos: " << pointsLoser << endl;

            controller->InsertHistory(winner, loser, pointsWinner, pointsLoser);

            cout << "---------------------------------------------" << endl;
            controller->InsertScore(player2->username, pointPlayer2);
            controller->InsertScore(player1->username, pointPlayer1);
            cout << " " << endl;
            cout << "Los datos de los jugadores fueron alamcenados en el historial." << endl;

            partida = true;
            system("pause");
        }
        else
        {
            letras = false;
            if (player == "player1")
            {
                turno = 0;
            }
            else
            {
                turno = 1;
            }
        }
    }
    //La cola esta vacia
    else
    {
        cout << "\n---------------------------------------";
        cout << "\n|           JUEGO TERMINADO            |";
        cout << "\n---------------------------------------";
        cout << "\nYa no quedan fichas en la cola y con las ";
        cout << "\nfichas sobrantes no se pueden formar mas palabras";
        cout << "\n\n Calculando ganador ... \n\n";

        if (pointPlayer1 != pointPlayer2)
        {
            if (pointPlayer1 > pointPlayer2)
            {
                winner = player1->username;pointsWinner = pointPlayer1; 
                loser = player2->username;pointsLoser = pointPlayer2;
            }
            else if (pointPlayer1 < pointPlayer2) {
                winner = player2->username;
                pointsWinner = pointPlayer2;
                loser = player1->username;
                pointsLoser = pointPlayer1;
            }
            cout << "Ganador: " << winner << endl;
            cout << "Puntos: " << pointsWinner << endl;
            cout << "Perdedor: " << loser << endl;
            cout << "Puntos: " << pointsLoser << endl;
            controller->InsertHistory(winner, loser, pointsWinner, pointsLoser);
            cout << "---------------------------------------------" << endl;
          

        }
        else
        {
            cout << "Empate: " << player1->username << "/ " << player2->username << endl;
            cout << "Puntos: " << pointPlayer1 << endl;
            controller->InsertHistory(player1->username + "/ " + player2->username, "", pointPlayer1, pointPlayer1);
        }

        cout << "---------------------------------------------" << endl;
        controller->InsertScore(player2->username, pointPlayer2);
        controller->InsertScore(player1->username, pointPlayer1);
        cout << " " << endl;
        cout << "Los datos de los jugadores fueron alamcenados en el historial." << endl;
        partida = true;
        system("pause");

        
    }


    
}
// CAMBIAR FICHAS

void ChangeChips(string player, string a) {

    bool endReplace = true;

    //Crea un bucle por si desea seguir reemplazando
    while (endReplace)
    {

        LetterPlayer* letterPlayerPoint = NULL;

        string letra = "";
        controller->PrintGameChips();
        menu.Cls();



        cout << "-------------------------Turno-------------------------" << "\n";
        if (player == "player1")
        {
            cout << "Player 1:  " << player1->username << "\n";
            LDplayer1.Show();
        }
        else
        {
            cout << "Player 2:  " << player2->username << "\n";
            LDplayer2.Show();
        }
        cout << "-------------------------------------------------------" << "\n";

        //VALIDACION DE LETRA, EL BUCLE SE REPITE SI NO ENCUENTRA LA LETRA EN LA LISTA DEL USUARIO
        do
        {
            cout << "Letra por reemplazar: ";
            std::cin >> letra;
            if (player == "player1")
            {
                letterPlayerPoint = LDplayer1.Search(letra);
            }
            else
            {
                letterPlayerPoint = LDplayer2.Search(letra);
            }
        } while (letterPlayerPoint == NULL);

        if (!controller->QueueIsEmpty())
        {
            //Se hace push otra vez a la cola
            controller->PushGameChip(letterPlayerPoint->letter, letterPlayerPoint->punteo, 1);
            //Inserta a las fichas del jugador la ficha que esta al inicio de la cola
            GameChipNode* let = controller->PopChip();
            if (player == "player1")
            {
                LDplayer1.Eliminar(letra);
                LDplayer1.Add(let->letter, let->points);
                LDplayer1Temp.Add(let->letter, let->points);
                LDplayer1.Print("Nuevas " + a);
            }
            else
            {
                LDplayer2.Eliminar(letra);
                LDplayer2.Add(let->letter, let->points);
                LDplayer2Temp.Add(let->letter, let->points);
                LDplayer2.Print("Nuevas " + a);
            }
        }
        else
        {
            cout << "La lista esta vacia, No se puede reemplazar";
        }
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
}

void Temp() {
    menu.Cls();
    cout << "archivo html";

    string head = "<!DOCTYPE html>\n<html>\n<body>\n";
      
    string body = "<h1>My First Heading</h1>";

    string footer = "\n</body>\n</html> ";
    ofstream ofs("Juego.html", ofstream::out);

    
    string texto = "";
   
    //std::cout << texto;
    texto = head + body +footer;
    //std::cout << texto;
    ofs << texto;

    ofs.close();
    system("Juego.html");
}