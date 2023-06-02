// Single Board Multiplayer game

// Snake and Ladder Game 
// components of game 
// 1. board
//  1. Players
//  2. Snakes
//  3. Ladder
//  4. Gamne Start
//  5. Declare Winner

// 2. player
//  1. id:int
//  2. Name:string
//  3  Position:int

// 3. dice
//  1.vector<int>={1,2,3,4,5,6}
//  2. RollDice();

#include<bits/stdc++.h>

using namespace std;

class Board;
class Player;
class Dice;
class Game;

class Dice {
    vector < int > dice = {1,2,3,4,5,6};

    public:
        int rollDice();
};

class Board {
    int id;
    unordered_map < int, int > ladder; // ladder at 0 -> 5
    unordered_map < int, int > snake; // snake at 6 -> 4;
    vector < Player > players;
    Dice dice;

    public:
    void setId(int);
    int getId();
    void startGame();
    void addPlayer(Player);
    void addLadder(int, int);
    void addSnake(int, int);
};

class Player {
    int id;
    int position;
    string name;
    int getUniqueId();
    public:
    int getPosition();
    void setPostion(int);
    string getName();
    Player(string);
};

class Game{
    vector<Board> boards;

    public:
    void createBoard(int id);
    void addPlayer(int id, Player);
    void addLadder(int id,vector<vector<int>> ladder);
    void addSnake(int id,vector<vector<int>> ladder);
    void startGame(int id);
    
};


void Game::startGame(int id){
    for(auto &b: boards){
        if(b.getId() == id){
            b.startGame();
            return;
        }
    }
    cout <<"Game Not Found";
    return;
}

void Game::addSnake(int id, vector<vector<int>> snakes){
    for(auto &b: boards){
        if(b.getId() == id){
            for(auto l : snakes) b.addLadder(l[0],l[1]);
        }
    }
    return;
}

void Game::addLadder(int id, vector<vector<int>> ladder){
    for(auto &b: boards){
        if(b.getId() == id){
            for(auto l : ladder) b.addLadder(l[0],l[1]);
        }
    }
    return;
}

void Game::addPlayer(int id, Player player){
    for(auto &b: boards){
        if(b.getId() == id){
            b.addPlayer(player);
            return;
        }
    }
    return;
}

void Game::createBoard(int id){
    for(auto &b : boards){
        if(b.getId() == id){
            cout<<"Board Already Created";
            return;
        }
    }
      Board board;
      board.setId(id);
      cout<<board.getId();
      boards.push_back(board);
      return;
}
// we are loop unless we get winner 
// winner is one who got position at 99 first


void Board::setId(int id){
    this->id = id;
}

int Board::getId(){
    return this->id;
}
void Board::addLadder(int start, int end) {

    if (end <= start) {
        cout << "Invalid Input Start is Great than end" << endl;
        return;
    }

    if (this -> ladder.count(start)) {
        cout << "Ladder Already exist" << endl;
        return;
    }

    this -> ladder.insert({start,end});
    return;
};

void Board::addSnake(int start, int end) {
    if (end >= start) {
        cout << "Invalid Input Start is Smaller than end" << endl;
        return;
    }

    if (this -> snake.count(start)) {
        cout << "Snake Already exist" << endl;
        return;
    }

    this -> snake.insert({
        start,
        end
    });
    return;
};

void Board::startGame() {
    int chance = 0;
    bool winner = false;
    string Winner_name;
    while (!winner) {

        int curr_position = players[chance].getPosition();
        int dice_number = dice.rollDice();
        int next_postion = curr_position + dice_number;

        if (next_postion > 100) continue;
        if (next_postion == 100) {
            Winner_name = players[chance].getName();
            winner = true;
            break;
        }

        cout << players[chance].getName() << " currPosition:" << curr_position << " nextPossition:" << next_postion << endl;

        if (ladder.count(next_postion)) players[chance].setPostion(ladder[next_postion]);
        else if (snake.count(next_postion)) players[chance].setPostion(snake[next_postion]);
        else players[chance].setPostion(next_postion);

        chance = (chance + 1) % players.size();
    }

    cout << "The Winner for Board "<<id<<"is :"<< Winner_name << endl;
}


string Player::getName() {
    return this -> name;
}

void Board::addPlayer(Player player) {
    this -> players.push_back(player);
}

int random(int low, int high) {
    srand((unsigned int) time(0));
    if (low > high) return high;
    return low + (std::rand() % (high - low + 1));
}

int Dice::rollDice() {

    // game is there    

    int roll;
    int min = 1; // the min number a die can roll is 1
    int max = this -> dice.size(); // the max value is the die size

    unsigned seed;
    seed = time(0);
    srand(seed);

    roll = rand() % (max - min + 1) + min;

    return roll;

}

void Player::setPostion(int position) {
    this->position = position;
}
int Player::getPosition() {
    return this->position;
}

int Player::getUniqueId() {
    static int id = 1;
    return id++;
}

Player::Player(string name) {
    this->name = name;
    this->id = getUniqueId();
    this->position = 1;
}

int main() {

    Player Player1("Abhishek");
    Player Player2("Pooja");
    Player Player3("Om");
    Player Player4("Poonam");
     
    Game game;
    game.createBoard(1);
    game.addPlayer(1,Player1);
    game.addPlayer(1,Player2);
    
    game.createBoard(2);
    game.addPlayer(2,Player3);
    game.addPlayer(2,Player4);

    game.addLadder(1,{{4, 14},{9, 31},{21, 42},{28, 84},{51, 67},{72, 91},{80, 99}});

    game.startGame(1);
    game.startGame(2);
}