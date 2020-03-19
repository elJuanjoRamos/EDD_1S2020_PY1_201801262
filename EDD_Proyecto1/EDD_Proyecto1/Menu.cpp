#include "Menu.h"




void Menu::getMenu() {
	//SetColorB(2,19);
	//Rectangle(20,8,40,12,"#");
	//SetColorA(2,22);
	Menu::Print(20, 2, "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA", 10);
	Menu::Print(20, 3, "FACULTAD DE INGENIERIA", 10);
	Menu::Print(20, 4, "ESTRUCTURA DE DATOS", 10);
	Menu::Print(20, 5, "Proyecto 1", 10);
	Menu::Print(20, 6, "JUAN JOSE RAMOS CAMPOS", 10);
	Menu::Print(20, 7, "201801262", 10);
	Menu::Print(28, 10, "*** MENU PRINCIPAL ***", 15);
	Menu::Print(28, 11, " ", 15);
	Menu::Print(28, 12, " ", 15);
	Menu::Print(28, 13, "1. Lectura de Archivo", 15);
	Menu::Print(28, 14, "2. Jugadores", 15);
	Menu::Print(28, 15, "3. Iniciar Juego", 15);
	Menu::Print(28, 16, "4. Reportes", 15);
	Menu::Print(28, 17, "5. Salir", 15);
	Menu::Print(28, 18, " ", 15);

}

void Menu::SetColorText(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Menu::PrintXY(int x, int y, int color) {
	HANDLE var;
	var = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(var, coord);
	Menu::SetColorText(color);
}

void Menu::Print(const char* txt)
{
	printf("%s", txt);
}


void Menu::Print(int x, int y, const char* txt, int color)
{
	Menu::PrintXY(x, y, color);
	printf("%s", txt);
}

void Menu::Cls() {
	system("cls");
}

bool Menu::IsNumber(string cadena)
{
	for (size_t i = 0; i < cadena.size(); i++)
	{
		// En cuanto un caracter no sea numerico
		if (!isdigit(cadena[i]))
			return false;
	}

	return true;
}





void Menu::OpenFile() {
	Cls();

	
}