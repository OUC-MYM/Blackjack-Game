#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include <iostream>
#include "House.h"
#include "Poker.h"
#include "Player.h"
using std::vector;

class Game      //游戏类
{
public:
    Game(vector<string>& names);
    ~Game();
    void Play();        //开始游戏
private:
    Poker poker;        //扑克
    House house;        //庄家
    vector <Player> players;        //玩家
};


#endif // GAME_H_INCLUDED
