#pragma once
class LetterPlayer
{
public:
    char letter;
    LetterPlayer* next;
    LetterPlayer* previous;

public:
    LetterPlayer();
    LetterPlayer(char c);
    virtual ~LetterPlayer();
};