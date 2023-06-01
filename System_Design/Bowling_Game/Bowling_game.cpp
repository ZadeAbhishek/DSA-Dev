#include<bits/stdc++.h>
using namespace std;

class Player;
class GameSession;
class Game;

class Player{};


class GameSession{
    public:
    void setAlley(int alley);
    int getId();
    void setPlayers(const vector<Player> &players);
    bool declareWinner();
    GameSession();


    private:
    int alley;
    int id;
    int getUniqueId();
    vector<Player> players;
};

class Game{
    
};

void GameSession::setAlley(int alley){
   this->alley = alley;   
}

void GameSession::setPlayers(const vector<Player> &players){
    this->players = players;
}

int GameSession::getId(){
   return this->id;
}

GameSession::GameSession(){
    this->id = this->getUniqueId();
    this->alley = -1;
    this->players.clear();
}

int GameSession::getUniqueId(){
    static int gamesessionId = 1;
    return gamesessionId++;
}

int main(){

}