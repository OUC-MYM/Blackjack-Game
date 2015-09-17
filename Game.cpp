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

void Game::Play()       //��ʼ��Ϸ
{
    // Ϊÿ���˷�������
    for (int i = 0; i < 2; ++i)
    {
        for (int i=0; i<players.size(); i++)
        {
            poker.extract(&players[i]);
        }
        poker.extract(&house);
    }

    // ����house�ĵ�һ����
    house.FlipFirstCard();

    // displayÿ��player����
    for (int i=0; i<players.size(); i++)
    {
        cout << players[i] << endl;
    }
    cout << house << endl;

    // ÿ���������ƣ���addtionanl�����ж��Ƿ�Ҫ����hit��
    for (int i=0; i<players.size(); i++)
    {
        poker.AdditionalCards(&players[i]);
    }

    // ����house�ĵ�һ����
    house.FlipFirstCard();
    cout << endl << house;

    // Ϊhouse��Ӷ�����
    poker.AdditionalCards(&house);

    // �ж���Ӯ
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

    // �Ƴ���
    for (int i=0; i<players.size(); i++)
    {
        players[i].Clear();
    }
    house.Clear();
    poker.destroy();
}
