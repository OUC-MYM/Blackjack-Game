#include "People.h"
#include <iostream>
using std::cout;
using std::endl;

People::People(string name)
{
    this->name = name;
}

void People::getCard(Card card)
{
    haveCards.push_back(card);
}

string People::getName()
{
    return name;
}

int People::getSum()
{
    int sum=0;
    int cnt=0;
    for(int i=0; i<haveCards.size(); i++)
    {
        if(!haveCards[i].Is_upward())
            return 0;
        if(haveCards[i].getNumber()>10)
            sum=sum+10;
        else if(haveCards[i].getNumber()==1)
        {
            sum=sum+11;
            cnt++;
        }
        else
            sum=sum+haveCards[i].getNumber();
    }
    while(cnt-- && sum>21)
        sum=sum-10;
    return sum;
}

bool People::IsBusted()
{
    if(getSum()>21)
        return true;
    else
        return false;
}

void People::Win()
{
    cout << name << "\tWill!" << endl;
}

void People::Lose()
{
    cout << name << "\tLose!" << endl;
}

void People::Deuce()
{
    cout << name << "\tDeuce!" << endl;
}

void People::Clear()
{
    haveCards.clear();
}
