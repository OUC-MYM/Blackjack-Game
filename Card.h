#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
using std::ostream;

class Card      //����
{
public:
    Card(int number,int colour);
    int getNumber();        //ȡ�õ���
    void overTurn();        //��ת��
    bool Is_upward();       //ȡ�ó���
    friend ostream & operator << (ostream &out,const Card &card);
private:
    int number;     //����
    char colour;        //��ɫ
    bool is_upward;     //����
};

#endif // CARD_H_INCLUDED
