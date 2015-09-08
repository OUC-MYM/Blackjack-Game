#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

#include "Player.h"

class People:public Player
{
public:
    People(string name);
    bool answer();
    void disPlay();
};

#endif // PEOPLE_H_INCLUDED
