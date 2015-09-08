#include "People.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

People::People(string name):Player(name) {}


bool People::answer()
{
    char cmd;
    cout << getName() << ",want a hit? <Y/N>:";
    cin >> cmd;
    if(cmd=='N'||cmd=='n')
        return false;
    else
        return true;
}

void People::disPlay()
{
    cout << name << "   ";
    for(int i=0; i<num; i++)
        cout << *haveCard[i]<< "    ";
    cout << "(" << getSum()  << ")" << endl;
}
