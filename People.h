#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

#include <iostream>
#include <vector>
#include "Card.h"
using std::string;
using std::vector;

class People
{
public:
    People(string name);
    void getCard(Card card);        //得到牌
    string getName();       //取得姓名
    int getSum();       //取得手上牌的总点数
    virtual bool answer()=0;        //回答是否要牌
    virtual void disPlay()=0;       //显示手中的牌
    bool IsBusted();        //判断是否超过21点
    void Win();     //赢
    void Lose();        //输
    void Deuce();       //平局
    void Clear();       //移除手上的牌
protected:
    string name;        //姓名
    vector <Card> haveCards;        //手上的牌
};

#endif // PEOPLE_H_INCLUDED
