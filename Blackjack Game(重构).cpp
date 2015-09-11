#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <stack>
using namespace std;

class Card
{
public:
    Card(int number,int colour)
    {
        this->number = number;
        this->colour = colour;
        this->is_upward = false;
    }
    int getNumber()
    {
        return number;
    }
    void overTurn()
    {
        is_upward = !is_upward;
    }
    bool Is_upward()
    {
        if(is_upward)
            return true;
        else
            return false;
    }
    friend ostream & operator << (ostream &out,const Card & card)
    {
        if(card.is_upward)
        {
            if(card.number>10)
            {
                switch (card.number)
                {
                case 11:
                    out << "J";
                    break;
                case 12:
                    out << "Q";
                    break;
                case 13:
                    out << "K";
                    break;
                }
            }
            else
                out << card.number;
            out << card.colour;
        }
        else
            cout << "**";
        return out;
    }
private:
    int number;
    char colour;
    bool is_upward;
};


class People
{
public:
    People(string name)
    {
        this->name = name;
    }
    void getCard(Card card)
    {
        haveCards.push_back(card);
    }
    string getName()
    {
        return name;
    }
    int getSum()
    {
        int sum=0;
        int cnt=0;
        for(int i=0; i<haveCards.size(); i++)
        {
            if(!haveCards[i].Is_upward())
                return 0;
            if(haveCards[i].getNumber()>10)
                sum=sum+10;
            else if(haveCards[i].getNumber()==1)
            {
                sum=sum+11;
                cnt++;
            }
            else
                sum=sum+haveCards[i].getNumber();
        }
        while(cnt-- && sum>21)
            sum=sum-10;
        return sum;
    }
    virtual bool answer()=0;
    bool IsBusted()
    {
        if(getSum()>21)
            return true;
        else
            return false;
    }
    void Win()
    {
        cout << name << "\tWill!" << endl;
    }
    void Lose()
    {
        cout << name << "\tLose!" << endl;
    }
    void Deuce()
    {
        cout << name << "\tDeuce!" << endl;
    }
    void Clear()
    {
        haveCards.clear();
    }
    virtual void disPlay()=0;
protected:
    string name;
    vector <Card> haveCards;
};

class Player:public People
{
public:
    Player(string name):People(name) {}
    friend ostream & operator << (ostream &out,Player &player)
    {
        cout << player.name << "\t";
        for(int i=0; i<player.haveCards.size(); i++)
            cout << player.haveCards[i] << "\t";
        out << "(" << player.getSum() << ")" << endl;
        return out;
    }
    bool answer()
    {
        char cmd;
        cout << name << ",want a hit? <Y/N>:";
        cin >> cmd;
        if(cmd=='N'||cmd=='n')
            return false;
        else
            return true;
    }
    void disPlay()
    {
        cout << *this;
    }
};

class House:public People
{
public:
    House():People("House") {}
    void FlipFirstCard()
    {
        haveCards[0].overTurn();
    }
    friend ostream & operator << (ostream &out,House &house)
    {
        cout << house.name << "\t";
        for(int i=0; i<house.haveCards.size(); i++)
            cout << house.haveCards[i] << "\t";
        if(house.getSum()!=0)
            out <<  "(" << house.getSum() << ")" << endl;
        return out;
    }
    bool answer()
    {
        if(getSum()<=16)
            return true;
        else
            return false;
    }
    void disPlay()
    {
        cout << *this;
    }
};


class Poker
{
public:
    Poker()
    {
        memset(vis,0,sizeof(vis));
        srand(time(NULL));
        while(cards.size()<52)
        {
            int temp=rand()%52;
            if(vis[temp])
                continue;
            vis[temp]=1;
            cards.push(Card(temp/4+1,numToColour(temp)));
        }
    }
    void extract(People *people)
    {
        if(!cards.empty())
        {
            Card temp=cards.top();
            cards.pop();
            temp.overTurn();
            people->getCard(temp);
        }
        else
            cout << "The Poker is empty!" << endl;
    }
    void AdditionalCards(People *people)
    {
        cout << endl;
        while(people->answer())
        {
            extract(people);
            people->disPlay();
            if(people->IsBusted())
            {
                cout << people->getName() << " bust!" << endl;
                break;
            }
        }
    }
    ~Poker()
    {
        while(!cards.empty())
            cards.pop();
    }
private:
    bool vis[52];
    stack <Card> cards;
    char numToColour(int num)
    {
        switch(num%4)
        {
        case 1:
            return 'a';
        case 2:
            return 'b';
        case 3:
            return 'c';
        case 0:
            return 'd';
        }
    }
};


class Game
{
public:
    Game(vector<string>& names)
    {
        for(int i=0; i<names.size(); i++)
            players.push_back(Player(names[i]));
        names.clear();
    }
    ~Game()
    {
        players.clear();
    }
    void Play();
private:
    Poker poker;
    House house;
    vector <Player> players;
};

void Game::Play()
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

    // 移除所有玩家的牌
    for (int i=0; i<players.size(); i++)
    {
        players[i].Clear();
    }
    house.Clear();
}

int main()
{
    cout << "\t\tWelcome to Blackjack!";
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        int numPlayers = 0;
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
        Game game(names);
        game.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}
