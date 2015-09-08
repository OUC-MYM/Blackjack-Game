#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
using std::ostream;

class Card
{
public:
    Card(int num,int colour);
    int getNum();
    char getColour();
    friend ostream & operator << (ostream &out,const Card & card);
private:
    int num;
    char colour;
};


#endif // CARD_H_INCLUDED
