#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include "Card.h"
using std::string;

class Player
{
public:
    Player(string name);
    void getCard(Card* card);
    virtual void disPlay()=0;
    virtual bool answer()=0;
    int getSum();
    string getName();
protected:
    string name;
    Card *haveCard[52];
    int num;
};

#endif // PLAYER_H_INCLUDED
