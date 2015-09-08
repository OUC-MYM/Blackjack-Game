#include "Judgment.h"
#include <iostream>
using std::cout;
using std::endl;

void Judgment::giveCard(Player *player)
{
    player->getCard(poker.pop());
}


bool Judgment::is_busts(Player *player)
{
    if(player->getSum()>21)
    {
        cout << player->getName() << " busts" << endl;
        return false;
    }
    return true;
}
