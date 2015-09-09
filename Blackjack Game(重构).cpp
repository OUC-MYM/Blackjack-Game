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


class Player
{
public:
    Player(string name)
    {
        this->name = name;
    }
    void getCard(Card card)
    {
        haveCards.push_back(card);
    }
    void disPlay()
    {
        for(int i=0; i<haveCards.size(); i++)
            cout << haveCards[i] << "\t";
    }
    int getSum()
    {
        int sum=0;
        int cnt=0;
        for(int i=0; i<haveCards.size(); i++)
        {
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
    string getName()
    {
        return name;
    }
    friend ostream & operator << (ostream &out,Player & player)
    {
        cout << player.name << "\t";
        player.disPlay();
        out << "(" << player.getSum() << ")" << endl;
        return out;
    }
    virtual bool answer()
    {
        char cmd;
        cout << getName() << ",want a hit? <Y/N>:";
        cin >> cmd;
        if(cmd=='N'||cmd=='n')
            return false;
        else
            return true;
    }
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
    void Push()
    {
        cout << name << "\tPush!" << endl;
    }
    void Clear()
    {
        haveCards.clear();
    }
protected:
    string name;
    vector <Card> haveCards;
};

class House:public Player
{
public:
    House():Player("House") {}
    void FlipFirstCard()
    {
        haveCards[0].overTurn();
    }
    friend ostream & operator << (ostream &out,House & house)
    {
        cout << house.name << "\t";
        house.disPlay();
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
    bool IsBusted()
    {
        if(getSum()>21)
            return true;
        else
            return false;
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
    void extract(Player *player)
    {
        if(!cards.empty())
        {
            Card temp=cards.top();
            cards.pop();
            temp.overTurn();
            player->getCard(temp);
        }
        else
            cout << "The Poker is empty!" << endl;
    }
    void AdditionalCards(Player *player)
    {
        cout << endl;
        while(player->answer())
        {
            extract(player);
            cout << *player;
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
    Game(const vector<string>& names)
    {
        for(int i=0; i<names.size(); i++)
            players.push_back(Player(names[i]));
    }
    ~Game() {}
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
    if(house.IsBusted())
    {
        for (int i=0; i<players.size(); i++)
        {
            if (!players[i].IsBusted())
            {
                players[i].Win();
            }
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
                    players[i].Push();
                }
            }
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
    cout << "\t\tWelcome to Blackjack!\n\n";
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
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
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        game.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}
