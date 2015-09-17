#include "Card.h"

Card::Card(int number,int colour)
{
    this->number = number;
    this->colour = colour;
    this->is_upward = false;
}

int Card::getNumber()       //取得点数
{
    return number;
}

void Card::overTurn()       //翻转牌
{
    is_upward = !is_upward;
}

bool Card::Is_upward()      //取得朝向
{
    if(is_upward)
        return true;
    else
        return false;
}

ostream & operator << (ostream &out,const Card & card)
{
    if(card.is_upward)
    {
        if(card.number>10)
        {
            switch (card.number)
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
            out << card.number;
        out << card.colour;
    }
    else
        out << "**";
    return out;
}
