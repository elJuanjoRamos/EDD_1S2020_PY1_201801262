#include "LetterPlayer.h"
#include <windows.h>
#include <stdio.h>

LetterPlayer::LetterPlayer()
{
}

LetterPlayer::LetterPlayer(string c)
{
    letter = c;
    next = previous = NULL;
}

LetterPlayer::LetterPlayer(string c, int punteo)
{
    letter = c;
    this->punteo = punteo;
    x = y = 0;
    next = previous = NULL;
}
LetterPlayer::LetterPlayer(string c, int punteo, int x1, int y1)
{
    letter = c;
    this->punteo = punteo;
    x = x1;
    y = y1;
    next = previous = NULL;
}

LetterPlayer::~LetterPlayer()
{
}
