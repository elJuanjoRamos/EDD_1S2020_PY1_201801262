

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
using namespace std;



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
        //Reportes
        else if (opcion == 3) {

            menu.Cls();
            controller->RandomLetters();
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

}


void OpenFile() {
    do
    {
        puts("Carga de Archivos Simple v1");
        puts("Ingrese el nombre del archivo");
        puts("------------------------------------");
        cout << "\n| Ingrese el nombre del archivo:";
        string fileName = "";
        cin >> fileName;
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
            cout << "Dictionary: " << endl;
            cout << "----------------------" << endl;
            //INSERTA LAS PALABRAS AL DICCIONARIO
            for (int x = 0; x < j3.at("diccionario").size(); x++)
            {
                controller->InsertDictionary(j3.at("diccionario")[x].at("palabra"));
                cout << "Word: " << j3.at("diccionario")[x].at("palabra") << endl;
            }
            cout << "----------------------" << endl;

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
            puts("3. Puntajes");

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
        //Puntajes
        else if (opcion == 3) {
            controller->PrintUsers();
            puts("Ingrese El nombre de usuario para ver sus puntajes");
            puts("O ingrese ALL para ver todos los puntajes");
            string user = "";
            cout << "Nombre: ";
            cin >> user;
            controller->PrintScore(user);
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
                controller->PrintUsers();

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
                            bool letras = true;
                            while (letras)
                            {
                                int x;
                                int y;
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
                                
                                //VALIDACION DE POSICION, EL BUCLE SE REPITE SI LA POSICION XY NO ES VALDIA
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
                                        std::cout << "\n Posicion XY ya ocupada\n" ;
                                    }
                                } while ((!(controller->ValidateInsertInBoard(x, y))) || (controller->SearchLetter(x,y) != NULL));
                                
                                //INSERTAR EL ELEMENTO EN LA MATRIZ 
                                controller->InsertMatrix(x, y, letra, letterPlayerPoint->punteo, false, false);
                                LDplayer1.Eliminar(letra);


                                //Agrega las letras eliminadas a un arreglo temporal
                                LDplayer1Temp.Add(letterPlayerPoint->letter, letterPlayerPoint->punteo, x, y);

                                std::cout << "\n1. Seguir, 2. Validar, 3. Terminar Juego " << endl;
                                std::cout << "Elija una opcion: ";

                                std::cin >> opcion;
                                if (opcion == 1) {
                                    letras = true;
                                }
                                else if (opcion == 2) {
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
                                    std::cout << "\n Orientacion de Palabra: (V/H): ";
                                    std::cin >> orientacion;
                                    string palabra;

                                    MatrixNode* temp = NULL;
                                    for (size_t i = 0; i < longitud; i++)
                                    {
                                        temp = controller->SearchLetter(posX, posY);
                                       

                                        if (temp != NULL)
                                        {
                                            if (orientacion == "V") {
                                                posYTemp = posY;
                                                posY++;
                                            }
                                            else if (orientacion == "H") {
                                                posXTemp = posX;
                                                posX++;
                                            }

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
                                            cout << "No Se contro ningun elemento en la posicion X:" << posXTemp << ", Y:" << posXTemp << endl;
                                            letras = false;
                                            turno = 1;
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
                                        LDplayer1Temp.Clean();
                                        int newLenght = LDplayer1.GetLenght();

                                        if (newLenght == 0)
                                        {
                                            newLenght = 7;
                                        }
                                        for (size_t i = 0; i < newLenght; i++)
                                        {
                                            if (!controller->QueueIsEmpty())
                                            {
                                                GameChipNode* let = controller->PopChip();
                                                LDplayer1.Add(let->letter, let->points);

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
                                        pointPlayer1 = pointPlayer1 + pointPlayer1Temp;
                                        cout << "Se ha sumado: " << pointPlayer1Temp << " pts a su punteo." << endl;
                                        cout << "Su puntaje ahora es: " << pointPlayer1 << endl;
                                        //LIMPIA LOS TEMPORALES
                                        pointPlayer1Temp = 0;
                                        system("pause");
                                        letras = false;
                                        turno = 1;
                                    }
                                    else {
                                        //LIMPIA LOS TEMPORALES
                                        pointPlayer1Temp = 0;

                                        cout << "-------------------------------------\n";
                                        cout << "|        Palabra NO encontrada       |\n";
                                        cout << "-------------------------------------\n";
                                        cout << "Las fichas utilizadas se devolveran a su listado\n";


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
                                //Rendirse
                                else if (opcion == 3) {

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
                                        menu.Cls();
                                        cout << "---------------Juego terminado---------------" << endl;
                                        cout << "Ganador: " << player2->username << endl;
                                        cout << "Puntos: " << pointPlayer2 << endl;
                                        cout << "Perdedor: " << player1->username << endl;
                                        cout << "Puntos: " << pointPlayer1 << endl;
                                        cout << "---------------------------------------------" << endl;
                                        controller->InsertScore(player2->username, pointPlayer2);
                                        controller->InsertScore(player1->username, pointPlayer1);
                                        cout << " " << endl;
                                        cout << "Los datos de los jugadores fueron alamcenados en el historial." << endl;

                                        partida = true;
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        letras = false;
                                        turno = 0;
                                    }

                                }

                            }

                        }
                        //CAMBIAR FICHAS
                        else if (opc1 == "2")
                        {

                            bool endReplace = true;

                            //Crea un bucle por si desea seguir reemplazando
                            while (endReplace)
                            {

                                LetterPlayer* letterPlayerPoint = NULL;
                                

                                controller->PrintGameChips();
                                menu.Cls();
                                cout << "-------------------------Turno-------------------------" << "\n";
                                cout << "Player 1:  " << player1->username << "\n";
                                LDplayer1.Show();
                                cout << "-------------------------------------------------------" << "\n";

                                //VALIDACION DE LETRA, EL BUCLE SE REPITE SI NO ENCUENTRA LA LETRA EN LA LISTA DEL USUARIO
                                do
                                {
                                    cout << "Letra por reemplazar: ";
                                    std::cin >> letra;
                                    letterPlayerPoint = LDplayer1.Search(letra);

                                } while (letterPlayerPoint == NULL);

                                if (!controller->QueueIsEmpty())
                                {
                                    //Se hace push otra vez a la cola
                                    controller->PushGameChip(letterPlayerPoint->letter, letterPlayerPoint->punteo, 1);
                                    //Inserta a las fichas del jugador la ficha que esta al inicio de la cola
                                    LDplayer1.Eliminar(letra);
                                    GameChipNode* let = controller->PopChip();
                                    LDplayer1.Add(let->letter, let->points);
                                    LDplayer1Temp.Add(let->letter, let->points);
                                    LDplayer1.Print();

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

                        }
                    

                    }
                    else if (turno == 1)
                    {

                        LDplayer2.Print();
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
                            bool letras = true;
                            while (letras)
                            {
                                int x;
                                int y;
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

                                //VALIDACION DE POSICION, EL BUCLE SE REPITE SI LA POSICION XY NO ES VALDIA
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

                                //INSERTAR EL ELEMENTO EN LA MATRIZ 
                                controller->InsertMatrix(x, y, letra, letterPlayerPoint->punteo, false, false);
                                LDplayer2.Eliminar(letra);


                                //Agrega las letras eliminadas a un arreglo temporal
                                LDplayer2Temp.Add(letterPlayerPoint->letter, letterPlayerPoint->punteo, x, y);

                                std::cout << "\n1. Seguir, 2. Validar, 3. Terminar Juego " << endl;
                                std::cout << "Elija una opcion: ";

                                std::cin >> opcion;
                                if (opcion == 1) {
                                    letras = true;
                                }
                                else if (opcion == 2) {
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
                                    std::cout << "\n Orientacion de Palabra: (V/H): ";
                                    std::cin >> orientacion;
                                    string palabra;

                                    MatrixNode* temp = NULL;
                                    for (size_t i = 0; i < longitud; i++)
                                    {
                                        temp = controller->SearchLetter(posX, posY);


                                        if (temp != NULL)
                                        {
                                            if (orientacion == "V") {
                                                posYTemp = posY;
                                                posY++;
                                            }
                                            else if (orientacion == "H") {
                                                posXTemp = posX;
                                                posX++;
                                            }

                                            palabra = palabra + temp->data;
                                            if (temp->isTriple == true) {
                                                pointPlayer2Temp = pointPlayer2Temp + (3 * temp->points);
                                            }
                                            else if (temp->isDouble == true) {
                                                pointPlayer2Temp = pointPlayer2Temp + (2 * temp->points);
                                            }
                                            else {
                                                pointPlayer2Temp = pointPlayer2Temp + temp->points;
                                            }
                                        }
                                        else
                                        {
                                            cout << "No Se contro ningun elemento en la posicion X:" << posXTemp << ", Y:" << posXTemp << endl;
                                            letras = false;
                                            turno = 0;
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
                                        LDplayer2Temp.Clean();
                                        int newLenght = LDplayer2.GetLenght();

                                        if (newLenght == 0)
                                        {
                                            newLenght = 7;
                                        }
                                        for (size_t i = 0; i < newLenght; i++)
                                        {
                                            if (!controller->QueueIsEmpty())
                                            {
                                                GameChipNode* let = controller->PopChip();
                                                LDplayer2.Add(let->letter, let->points);

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
                                        pointPlayer2 = pointPlayer2 + pointPlayer2Temp;
                                        cout << "Se ha sumado: " << pointPlayer2Temp << " pts a su punteo." << endl;
                                        cout << "Su puntaje ahora es: " << pointPlayer2 << endl;
                                        //LIMPIA LOS TEMPORALES
                                        pointPlayer2Temp = 0;
                                        system("pause");
                                        letras = false;
                                        turno = 0;
                                    }
                                    else {
                                        //LIMPIA LOS TEMPORALES
                                        pointPlayer2Temp = 0;

                                        cout << "-------------------------------------\n";
                                        cout << "|        Palabra NO encontrada       |\n";
                                        cout << "-------------------------------------\n";
                                        cout << "Las fichas utilizadas se devolveran a su listado\n";


                                        //REGRESA LAS PALABRAS A LA LISTA ORIGINAL DEL USUARIO
                                        LD_LetterPlayer temp = LDplayer2Temp;

                                        while (temp.first != NULL)
                                        {
                                            controller->DeleteMatrixNode(temp.first->x, temp.first->y);
                                            LDplayer2.Add(temp.first->letter, temp.first->punteo);
                                            temp.first = temp.first->next;

                                        }
                                        system("pause");
                                    }
                                    letras = false;
                                    turno = 0;
                                }
                                //Rendirse
                                else if (opcion == 3) {

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
                                        menu.Cls();
                                        cout << "---------------Juego terminado---------------" << endl;
                                        cout << "Ganador: " << player1->username << endl;
                                        cout << "Puntos: " << pointPlayer1 << endl;
                                        cout << "Perdedor: " << player2->username << endl;
                                        cout << "Puntos: " << pointPlayer2 << endl;
                                        cout << "---------------------------------------------" << endl;
                                        controller->InsertScore(player2->username, pointPlayer2);
                                        controller->InsertScore(player1->username, pointPlayer1);
                                        cout << " " << endl;
                                        cout << "Los datos de los jugadores fueron alamcenados en el historial." << endl;

                                        partida = true;
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        letras = false;
                                        turno = 1;
                                    }

                                }

                            }

                        }
                        //CAMBIAR FICHAS
                        else if (opc1 == "2")
                        {

                            bool endReplace = true;

                            //Crea un bucle por si desea seguir reemplazando
                            while (endReplace)
                            {

                                LetterPlayer* letterPlayerPoint = NULL;


                                controller->PrintGameChips();
                                menu.Cls();
                                cout << "-------------------------Turno-------------------------" << "\n";
                                cout << "Player 2:  " << player2->username << "\n";
                                LDplayer2.Show();
                                cout << "-------------------------------------------------------" << "\n";

                                //VALIDACION DE LETRA, EL BUCLE SE REPITE SI NO ENCUENTRA LA LETRA EN LA LISTA DEL USUARIO
                                do
                                {
                                    cout << "Letra por reemplazar: ";
                                    std::cin >> letra;
                                    letterPlayerPoint = LDplayer2.Search(letra);

                                } while (letterPlayerPoint == NULL);

                                if (!controller->QueueIsEmpty())
                                {
                                    //Se hace push otra vez a la cola
                                    controller->PushGameChip(letterPlayerPoint->letter, letterPlayerPoint->punteo, 1);
                                    //Inserta a las fichas del jugador la ficha que esta al inicio de la cola
                                    LDplayer2.Eliminar(letra);
                                    GameChipNode* let = controller->PopChip();
                                    LDplayer2.Add(let->letter, let->points);
                                    LDplayer2Temp.Add(let->letter, let->points);
                                    LDplayer2.Print();

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
