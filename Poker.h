#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include <iostream>
#include <stack>
#include "People.h"
using std::stack;


class Poker
{
public:
    Poker();
    void extract(People *people);
    void AdditionalCards(People *people);
    ~Poker();
private:
    bool vis[52];
    stack <Card> cards;
    char numToColour(int num);
};

#endif // POKER_H_INCLUDED
