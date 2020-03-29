#pragma once
#include "LetterPlayer.h"
#include <string>
using namespace std;

class LD_LetterPlayer
{
public:
	LetterPlayer* first;
	LetterPlayer* last;
	LD_LetterPlayer();
	void Add(string c, int punteo);
	void Add(string c, int punteo, int x, int y);
	LetterPlayer* Search(string search);
	int GetLenght();
	void Clean();
	void Show();
	void Eliminar(string search);
	void Print(string name);
};