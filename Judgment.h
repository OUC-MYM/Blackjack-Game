#ifndef JUDGMENT_H_INCLUDED
#define JUDGMENT_H_INCLUDED

#include "Poker.h"
#include "Player.h"

class Judgment
{
public:
    void giveCard(Player *player);
    bool is_busts(Player *player);
private:
    Poker poker;
};

#endif // JUDGMENT_H_INCLUDED
