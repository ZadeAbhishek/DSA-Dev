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

class Dice {
    int dice_size = 6;

    public:
        int rollDice();
};

class Board {
    unordered_map < int, int > ladder; // ladder at 0 -> 5
    unordered_map < int, int > snake; // snake at 6 -> 4;
    vector < Player > players;
    Dice dice;

    public:
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


// we are loop unless we get winner 
// winner is one who got position at 99 first

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

        if (ladder.count(next_postion)) players[chance].setPostion(ladder[next_postion]);
        else if (snake.count(next_postion)) players[chance].setPostion(snake[next_postion]);
        else players[chance].setPostion(next_postion);

        cout << players[chance].getName() << " From:" <<curr_position<<" -------> "<< "To:" <<players[chance].getPosition()<< endl;

        chance = (chance + 1) % players.size();
    }

    cout << "Winner is: " << Winner_name << endl;
}

string Player::getName() {
    return this -> name;
}

void Board::addPlayer(Player player) {
    this -> players.push_back(player);
}


int Dice::rollDice() {

    // game is there    

    int roll;
    int min = 1; // the min number a die can roll is 1
    int max = dice_size; // the max value is the die size

    random_device rd;
    uniform_int_distribution<int> dice(min,max);
    return dice(rd);

}

void Player::setPostion(int position) {
    this -> position = position;
}
int Player::getPosition() {
    return this -> position;
}

int Player::getUniqueId() {
    static int id = 1;
    return id++;
}

Player::Player(string name) {
    this -> name = name;
    this -> id = getUniqueId();
    this -> position = 1;
}

int main() {

    Player Player1("Abhishek");
    Player Player2("Pooja");
    Player Player3("Om");
    Player Player4("Poonam");

    Board board;

    board.addPlayer(Player1);
    board.addPlayer(Player2);
    board.addPlayer(Player3);
    board.addPlayer(Player4);

    board.addLadder(4, 14);
    board.addLadder(9, 31);
    board.addLadder(21, 42);
    board.addLadder(28, 84);
    board.addLadder(51, 67);
    board.addLadder(72, 91);
    board.addLadder(80, 99);

    board.addSnake(98, 79);
    board.addSnake(95, 75);
    board.addSnake(93, 73);
    board.addSnake(87, 36);
    board.addSnake(19, 62);

    board.startGame();

}