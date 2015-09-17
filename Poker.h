#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include <iostream>
#include <stack>
#include "People.h"
using std::stack;


class Poker     //扑克类
{
public:
    Poker();
    void Extract(People *people);       //发牌
    void AdditionalCards(People *people);       //添加牌
    void Destroy();     //丢弃扑克
    ~Poker();
private:
    stack <Card> cards;     //扑克中的牌
};

#endif // POKER_H_INCLUDED
