#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include <iostream>
#include "House.h"
#include "Poker.h"
#include "Player.h"
using std::vector;

class Game
{
public:
    Game(vector<string>& names);
    ~Game();
    void Play();
private:
    Poker poker;
    House house;
    vector <Player> players;
};


#endif // GAME_H_INCLUDED
