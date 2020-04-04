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
void StructureController::ShowPrintDictionary() {
    diccionario.ShowPrint();
}
void StructureController::ClearDictionary() {
    diccionario.first = diccionario.last = NULL;
}
void StructureController::DeleteDictionary(string w) {
    diccionario.Delete(w);
}
bool StructureController::DictionaryIsEmpty() {
    return diccionario.IsEmpty();
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
void StructureController::PrintUsers(string type) {
    arbol.Print(type);
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


// Hisori

void StructureController::InsertHistory(string winner, string loser, int wp, int lp) {
    history.Insert(winner, loser, wp, lp);
}
void StructureController::PrintHistory() {
    history.Print();
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


void StructureController::PrintBoard(string player1, string player2, int p1, int p2) {

    string head = string() + "<!DOCTYPE html>\n" +
        "<html>\n" +
        "<head>\n" +
        "    <meta charset='utf-8' http-equiv=\"refresh\" content=\"1\" >\n" +
        "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n" +
        "    <title> Repote Scrabble" + "</title>\n" +
        "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n" +
        "    <link rel='stylesheet' type='text/css' media='screen' href='main.css'>\n" +
        "    <script src='main.js'></script>\n" +
        "    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">\n" +
        "    <link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css\">\n" +
        "</head>" +
        "<body>\n" +
        "  <nav class=\"navbar navbar-light bg-light\">\n" +
        "    <span class=\"navbar-brand mb-0 h1\">Estructura de Datos</span>\n" +
        "  </nav>";


    string cadena2 = string() + "          <th scope=\"col\">Jugador 1</th>\n" +
        "          <th scope=\"col\">Tablero</th>\n" +
        "          <th scope=\"col\">Jugador 2</th>\n";

    string body1 = string() +
        "<div class=\"container\">\n" +
        "    <div class=\"jumbotron jumbotron-fluid\">\n" +
        "      <div class=\"container\">\n" +
        "        <h1 class=\"display-4\"> Juego Scrabble" + "</h1>\n" +
        "      </div>\n" +
        "    </div>\n" +
        "</div>\n";

    string pl1 = "Nombre: " + player1 + "<br>Puntos: " + to_string(p1);
    string pl2 = "Nombre: " + player2 + "<br>Puntos: " + to_string(p2);

    string contenido1 = string() +

        "<table id=\"data\"  cellspacing=\"0\" style=\"width: 100 %\" class=\"table table-striped table-bordered table-sm\">\n" +
        "<colgroup>\n" +
        "<col span = \"1\" style = \"width: 15%; \">\n" +
        "<col span = \"1\" style = \"width: 70%; \">\n" +
        "<col span = \"1\" style = \"width: 15%; \">\n" +
        "</colgroup>\n" +
        "      <thead class=\"thead-dark\">\n" +
        "        <tr>\n" +
        
        cadena2 +
        "        </tr>\n" +
        "      </thead>" +
        "<tbody>"
        "<tr>\n" +
        "     <td >" + pl1 + "</td>\n" +
        "     <td>" + "</td>\n" +
        "     <td>" + pl2 + "</td>\n" +
        "</tr>";
    string contenido2 = string() + "<tr>\n" +
        "     <td >" + "<img src=\"./LD_LetterPlayer1.png\"  border=3 >" + "</td>\n" +
        "     <td >" + "<img src=\"./Matrix.png\"  border=3 >" + "</td>\n" +
        "     <td >" + "<img src=\"./LD_LetterPlayer2.png\"  border=3 >" + "</td>\n" +
        "</tr>" + "</tbody>\n" +
        "    </table>\n";

    string script = string()+
        "  <script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js\" ></script>\n" +
        "  <script src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js\"></script>\n";
    string footer = "\n</body>\n</html> ";
    ofstream ofs("Juego.html", ofstream::out);


    string texto = "";

    //std::cout << texto;
    texto = head + body1 + contenido1 + contenido2 + script +  footer;
    //std::cout << texto;
    ofs << texto;

    ofs.close();
}

void StructureController::ShowBoard() {
    system("Juego.html");
}