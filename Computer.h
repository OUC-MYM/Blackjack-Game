#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

#include "Player.h"

class Computer:public Player
{
public:
    Computer();
    bool answer();
    void disPlay();
};

#endif // COMPUTER_H_INCLUDED
