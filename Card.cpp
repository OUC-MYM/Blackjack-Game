#include "Card.h"

Card::Card(int num,int colour)
{
    this->num = num;
    this->colour = colour;
}

int Card::getNum()
{
    return num;
}

char Card::getColour()
{
    return colour;
}

ostream & operator << (ostream &out,const Card & card)
{
    if(card.num>10)
    {
        switch (card.num)
        {
        case 11:
            out << "J";
            break;
        case 12:
            out << "Q";
            break;
        case 13:
            out << "K";
            break;
        }
    }
    else
        out << card.num;
    out << card.colour;
    return out;
}
