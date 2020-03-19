#include "LetterPlayer.h"
#include <windows.h>
#include <stdio.h>

LetterPlayer::LetterPlayer()
{
}

LetterPlayer::LetterPlayer(char c)
{
    letter = c;
    next = previous = NULL;
}

LetterPlayer::~LetterPlayer()
{
}
