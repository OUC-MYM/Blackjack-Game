#include "Player.h"


Player::Player(string name)
{
    this->name = name;
    this->num = 0;
}


void Player::getCard(Card* card)
{
    haveCard[num++] = card;
}


int Player::getSum()
{
    int sum=0;
    int cnt=0;
    for(int i=0; i<num; i++)
    {
        if(haveCard[i]->getNum()>10)
            sum=sum+10;
        else if(haveCard[i]->getNum()==1)
        {
            sum=sum+11;
            cnt++;
        }
        else
            sum=sum+haveCard[i]->getNum();
    }
    while(cnt-- && sum>21)
        sum=sum-10;
    return sum;
}

string Player::getName()
{
    return name;
}


