#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;

Game::Game(vector<string>& names)
{
    for(int i=0; i<names.size(); i++)
        players.push_back(Player(names[i]));
    names.clear();
}

Game::~Game()
{
    players.clear();
}

void Game::Play()       //开始游戏
{
    // 为每个人发两张牌
    for (int i = 0; i < 2; ++i)
    {
        for (int i=0; i<players.size(); i++)
        {
            poker.extract(&players[i]);
        }
        poker.extract(&house);
    }

    // 隐藏house的第一张牌
    house.FlipFirstCard();

    // display每个player的牌
    for (int i=0; i<players.size(); i++)
    {
        cout << players[i] << endl;
    }
    cout << house << endl;

    // 每个玩家添加牌（在addtionanl里面判断是否要进行hit）
    for (int i=0; i<players.size(); i++)
    {
        poker.AdditionalCards(&players[i]);
    }

    // 亮出house的第一张牌
    house.FlipFirstCard();
    cout << endl << house;

    // 为house添加额外牌
    poker.AdditionalCards(&house);

    // 判断输赢
    cout << endl;
    if(house.IsBusted())
    {
        for (int i=0; i<players.size(); i++)
        {
            if (!players[i].IsBusted())
            {
                players[i].Win();
            }
            else
                players[i].Deuce();
        }
    }
    else
    {
        for (int i=0; i<players.size(); i++)
        {
            if (!players[i].IsBusted())
            {
                if (players[i].getSum() > house.getSum())
                {
                    players[i].Win();
                }
                else if (players[i].getSum() < house.getSum())
                {
                    players[i].Lose();
                }
                else
                {
                    players[i].Deuce();
                }
            }
            else
                players[i].Lose();
        }
    }

    // 移除牌
    for (int i=0; i<players.size(); i++)
    {
        players[i].Clear();
    }
    house.Clear();
    poker.destroy();
}
