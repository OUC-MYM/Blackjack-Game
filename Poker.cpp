#include "Poker.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

Poker::Poker()
{
    bool vis[52];
    memset(vis,0,sizeof(vis));
    srand(time(NULL));
    while(cards.size()<52)
    {
        int temp=rand()%52;
        if(vis[temp])
            continue;
        vis[temp]=1;

        int num = temp/4+1;
        char colour;
        switch(temp%4)
        {
        case 1:
            colour = 3;
            break;
        case 2:
            colour = 4;
            break;
        case 3:
            colour = 5;
            break;
        case 0:
            colour = 6;
            break;
        }
        cards.push(Card(num,colour));
    }
}

void Poker::Extract(People *people)     //发牌
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

void Poker::AdditionalCards(People *people)     //添加牌
{
    cout << endl;
    while(people->Answer())
    {
        Extract(people);
        people->Display();
        if(people->IsBusted())
        {
            cout << people->getName() << " bust!" << endl;
            break;
        }
    }
}

void Poker::Destroy()     //丢弃扑克
{
    while(!cards.empty())
        cards.pop();
}

Poker::~Poker()
{
    while(!cards.empty())
        cards.pop();
}
