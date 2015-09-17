#include "People.h"
#include <iostream>
using std::cout;
using std::endl;

People::People(string name)
{
    this->name = name;
}

void People::getCard(Card card)        //得到牌
{
    haveCards.push_back(card);
}

string People::getName()       //取得姓名
{
    return name;
}

int People::getSum()       //取得手上牌的总点数
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

bool People::IsBusted()        //判断是否超过21点
{
    if(getSum()>21)
        return true;
    else
        return false;
}

void People::Win()     //赢
{
    cout << name << "\tWill!" << endl;
}

void People::Lose()     //输
{
    cout << name << "\tLose!" << endl;
}

void People::Deuce()        //平局
{
    cout << name << "\tDeuce!" << endl;
}

void People::Clear()        //移除手上的牌
{
    haveCards.clear();
}
