#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
using std::ostream;

class Card      //牌类
{
public:
    Card(int number,int colour);
    int getNumber();        //取得点数
    void overTurn();        //翻转牌
    bool Is_upward();       //取得朝向
    friend ostream & operator << (ostream &out,const Card &card);
private:
    int number;     //点数
    char colour;        //花色
    bool is_upward;     //朝向
};

#endif // CARD_H_INCLUDED
