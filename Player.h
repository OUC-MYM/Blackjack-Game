#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "People.h"

class Player:public People
{
public:
    Player(string name);
    friend ostream & operator << (ostream &out,Player &player);
    bool answer();
    void disPlay();
};

#endif // PLAYER_H_INCLUDED
