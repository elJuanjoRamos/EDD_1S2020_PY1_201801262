#include <windows.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "JSON.h";

using namespace std;
class Menu
{
public:
	void Print(const char* txt);
	void PrintXY(int x, int y, int color);
	void Print(int x, int y, const char* txt, int color);
	void Cls();
	void SetColorText(int color);
	void getMenu();
	bool IsNumber(string text);



	//Metodos funcionales

	void OpenFile();

};

