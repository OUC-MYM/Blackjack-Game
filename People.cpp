#include "People.h"
#include <iostream>
using std::cout;
using std::endl;

People::People(string name)
{
    this->name = name;
}

void People::getCard(Card card)        //�õ���
{
    haveCards.push_back(card);
}

string People::getName()       //ȡ������
{
    return name;
}

int People::getSum()       //ȡ�������Ƶ��ܵ���
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

bool People::IsBusted()        //�ж��Ƿ񳬹�21��
{
    if(getSum()>21)
        return true;
    else
        return false;
}

void People::Win()     //Ӯ
{
    cout << name << "\tWill!" << endl;
}

void People::Lose()     //��
{
    cout << name << "\tLose!" << endl;
}

void People::Deuce()        //ƽ��
{
    cout << name << "\tDeuce!" << endl;
}

void People::Clear()        //�Ƴ����ϵ���
{
    haveCards.clear();
}
