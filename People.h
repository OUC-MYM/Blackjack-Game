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
    void getCard(Card card);
    string getName();
    int getSum();
    virtual bool answer()=0;
    virtual void disPlay()=0;
    bool IsBusted();
    void Win();
    void Lose();
    void Deuce();
    void Clear();
protected:
    string name;
    vector <Card> haveCards;
};

#endif // PEOPLE_H_INCLUDED
