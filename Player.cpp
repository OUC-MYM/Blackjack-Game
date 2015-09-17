#include "Player.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Player::Player(string name):People(name) {}

ostream & operator << (ostream &out,Player &player)
{
    cout << player.name << "\t";
    for(int i=0; i<player.haveCards.size(); i++)
        cout << player.haveCards[i] << "\t";
    out << "(" << player.getSum() << ")" << endl;
    return out;
}

bool Player::Answer()
{
    char cmd;
    while(true)
    {
        cout << name << ",want a hit? <Y/N>:";
        cin >> cmd;
        if(cmd=='N'||cmd=='n')
            return false;
        if(cmd=='Y'||cmd=='y')
            return true;
    }
}

void Player::Display()
{
    cout << *this;
}
