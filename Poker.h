#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include <iostream>
#include <stack>
#include "People.h"
using std::stack;


class Poker     //�˿���
{
public:
    Poker();
    void extract(People *people);       //����
    void AdditionalCards(People *people);       //�����
    void destroy();     //�����˿�
    ~Poker();
private:
    stack <Card> cards;     //�˿��е���
};

#endif // POKER_H_INCLUDED
