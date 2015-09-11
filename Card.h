#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
using std::ostream;

class Card
{
public:
    Card(int number,int colour);
    int getNumber();
    void overTurn();
    bool Is_upward();
    friend ostream & operator << (ostream &out,const Card &card);
private:
    int number;
    char colour;
    bool is_upward;
};

#endif // CARD_H_INCLUDED
