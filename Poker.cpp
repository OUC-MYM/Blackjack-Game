#include "Poker.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

Poker::Poker()
{
    memset(vis,0,sizeof(vis));
    srand(time(NULL));
    while(cards.size()<52)
    {
        int temp=rand()%52;
        if(vis[temp])
            continue;
        vis[temp]=1;
        cards.push(Card(temp/4+1,numToColour(temp)));
    }
}

void Poker::extract(People *people)
{
    if(!cards.empty())
    {
        Card temp=cards.top();
        cards.pop();
        temp.overTurn();
        people->getCard(temp);
    }
    else
        cout << "The Poker is empty!" << endl;
}

void Poker::AdditionalCards(People *people)
{
    cout << endl;
    while(people->answer())
    {
        extract(people);
        people->disPlay();
        if(people->IsBusted())
        {
            cout << people->getName() << " bust!" << endl;
            break;
        }
    }
}

Poker::~Poker()
{
    while(!cards.empty())
        cards.pop();
}

char Poker::numToColour(int num)
{
    switch(num%4)
    {
    case 1:
        return 'a';
    case 2:
        return 'b';
    case 3:
        return 'c';
    case 0:
        return 'd';
    }
}
