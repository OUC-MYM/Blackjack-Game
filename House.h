#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

#include "People.h"

class House:public People
{
public:
    House();
    void FlipFirstCard();       //翻转house的第一张牌
    friend ostream & operator << (ostream &out,House &house);
    bool answer();
    void disPlay();
};

#endif // HOUSE_H_INCLUDED
