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
    void getCard(Card card);        //�õ���
    string getName();       //ȡ������
    int getSum();       //ȡ�������Ƶ��ܵ���
    virtual bool Answer()=0;        //�ش��Ƿ�Ҫ��
    virtual void Display()=0;       //��ʾ���е���
    bool IsBusted();        //�ж��Ƿ񳬹�21��
    void Win();     //Ӯ
    void Lose();        //��
    void Deuce();       //ƽ��
    void Clear();       //�Ƴ����ϵ���
protected:
    string name;        //����
    vector <Card> haveCards;        //���ϵ���
};

#endif // PEOPLE_H_INCLUDED
