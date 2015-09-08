#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;

Computer::Computer():Player("House") {}

bool Computer::answer()
{
    if(getSum()<=16)
        return true;
    else
        return false;
}

void Computer::disPlay()
{
    cout << name << "   ";
    cout << "**" << "    ";
    for(int i=1; i<num; i++)
        cout << *haveCard[i]<< "    ";
    cout << endl;
}
