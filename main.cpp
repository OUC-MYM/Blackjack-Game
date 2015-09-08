#include <iostream>
#include "Card.h"
#include "Judgment.h"
#include "Computer.h"
#include "People.h"
#include "Poker.h"
#include "Player.h"
using namespace std;

int main()
{
    while(1)
    {
        int num;
        cout << "Welcome to Blackjack!" << endl;
        cout << "How many player? (1-7):";
        cin >> num;
        num++;
        Judgment judgment;
        Player *player[num];
        for(int i=0; i<num-1; i++)
        {
            cout << "Enter player name:";
            string name;
            cin >> name;
            player[i]=new People(name);
        }
        player[num-1] = new Computer;
        cout << endl;

        for(int i=0; i<num*2; i++)
        {
            judgment.giveCard(player[i%num]);
        }
        for(int i=0; i<num; i++)
            player[i]->disPlay();
        cout << endl;

        for(int i=0; i<num; i++)
        {
            while(1)
            {
                if(!judgment.is_busts(player[i]))
                    break;
                if(!player[i]->answer())
                    break;
                judgment.giveCard(player[i]);
                player[i]->disPlay();
            }
            cout << endl;
        }
        cout << endl;

        int sign;
        for(int i=0; i<num; i++)
            if(player[i]->getSum()<=21)
            {
                sign=i;
                break;
            }
        for(int i=0; i<num; i++)
        {
            player[i]->disPlay();
            if(player[i]->getSum()<=21&&player[i]->getSum()>player[sign]->getSum())
                sign=i;
        }
        cout << player[sign]->getName() << " win" << endl << endl;

        cout << "play again? <Y/N>:" ;
        char end;
        cin >> end;
        cout << endl;
        if(end=='N'||end=='n')
            break;
    }
    return 0;
}
