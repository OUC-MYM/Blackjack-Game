#include "House.h"
#include <iostream>
using std::cout;
using std::endl;

House::House():People("House") {}

void House::FlipFirstCard()     //翻转house的第一张牌
{
    haveCards[0].overTurn();
}

ostream & operator << (ostream &out,House &house)
{
    cout << house.name << "\t";
    for(int i=0; i<house.haveCards.size(); i++)
        cout << house.haveCards[i] << "\t";
    if(house.getSum()!=0)
        out <<  "(" << house.getSum() << ")" << endl;
    return out;
}

bool House::Answer()
{
    if(getSum()<=16)
        return true;
    else
        return false;
}

void House::Display()
{
    cout << *this;
}
