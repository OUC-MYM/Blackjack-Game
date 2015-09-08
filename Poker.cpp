#include "Poker.h"
#include <cstring>
#include <cstdlib>
#include <ctime>

Poker::Poker()
{
    memset(vis,0,sizeof(vis));
    top=0;
    srand(time(NULL));
    while(top<52)
    {
        int temp=rand()%52;
        if(vis[temp])
            continue;
        vis[temp]=1;
        cards[top++]=new Card(temp/4+1,numToCard(temp));
    }
}


Card* Poker::pop()
{
    return cards[--top];
}


Poker::~Poker()
{
    for(int i=0; i<52; i++)
        delete cards[i];
}


char Poker::numToCard(int num)
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
