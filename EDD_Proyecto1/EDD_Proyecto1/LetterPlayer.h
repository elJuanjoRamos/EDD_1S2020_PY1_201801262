#pragma once
#include <string>

using namespace std;

class LetterPlayer
{
public:
    string letter;
    int punteo;
    int x;
    int y;
    LetterPlayer* next;
    LetterPlayer* previous;

public:
    LetterPlayer();
    LetterPlayer(string c);
    LetterPlayer(string c, int punteo);
    LetterPlayer(string c, int punteo, int x, int y);
    virtual ~LetterPlayer();
};