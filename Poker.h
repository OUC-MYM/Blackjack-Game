#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include "Card.h"

class Poker
{
public:
    Poker();
    Card* pop();
    ~Poker();
private:
    bool vis[52];
    Card *cards[52];
    int top;
    char numToCard(int num);
};

#endif // POKER_H_INCLUDED
