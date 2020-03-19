#pragma once
#include "LetterPlayer.h"
#include <string>

class LD_LetterPlayer
{
public:
	LetterPlayer* first;
	LetterPlayer* last;
	LD_LetterPlayer();
	void Add(char c);
	LetterPlayer* Search(char search);
	void Clean();
	void Show();
	char Eliminar(char search);
	void Print();
};