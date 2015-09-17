#include <iostream>
#include "Card.h"
#include "People.h"
#include "Player.h"
#include "House.h"
#include "Poker.h"
#include "Game.h"
using namespace std;

int main()
{
    cout << "\t\tWelcome to Blackjack!";
    char again = 0;
    while (again != 'n' && again != 'N')
    {
        int numPlayers = 0;     //玩家人数
        while (numPlayers < 1 || numPlayers > 7)
        {
            cout << endl << "How many players? (1 - 7): ";
            cin >> numPlayers;
        }

        vector <string> names;
        for (int i = 0; i < numPlayers; i++)
        {
            cout << "Enter player name: ";
            string name;
            cin >> name;
            names.push_back(name);
        }
        cout << endl;
        Game game(names);       //新游戏
        game.Play();        //开始游戏

        again = 0;
        while ( !(again == 'n' || again == 'N' || again == 'y' || again == 'Y') )
        {
            cout << "\nDo you want to play again? (Y/N): ";
            cin >> again;
        }
    }

    return 0;
}
