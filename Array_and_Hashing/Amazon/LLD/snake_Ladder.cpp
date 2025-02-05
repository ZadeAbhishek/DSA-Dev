#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()
#include <stdexcept>
using namespace std;

// Board class manages the board, snakes, and ladders.
class Board {
private:
    int size; // Total number of squares on the board.
    unordered_map<int, int> snakes;  // Mapping: head -> tail.
    unordered_map<int, int> ladders; // Mapping: start -> end.

public:
    Board(int s) : size(s) {
        // Define some ladders.
        ladders[2]  = 38;
        ladders[7]  = 14;
        ladders[8]  = 31;
        ladders[15] = 26;
        ladders[21] = 42;
        ladders[28] = 84;
        ladders[36] = 44;
        
        // Define some snakes.
        snakes[16] = 6;
        snakes[46] = 25;
        snakes[49] = 11;
        snakes[62] = 19;
        snakes[64] = 60;
        snakes[74] = 53;
        snakes[89] = 68;
        snakes[92] = 88;
        snakes[95] = 75;
        snakes[99] = 80;
    }
    
    int getSize() const {
        return size;
    }
    
    // Checks if the position contains a snake or ladder.
    // Returns the new position after moving, or the same if nothing happens.
    int checkSnakeOrLadder(int pos) {
        if (ladders.find(pos) != ladders.end()) {
            cout << "Hit a ladder! Climbing up from " << pos << " to " << ladders[pos] << ".\n";
            return ladders[pos];
        } else if (snakes.find(pos) != snakes.end()) {
            cout << "Oops, bitten by a snake! Sliding down from " << pos << " to " << snakes[pos] << ".\n";
            return snakes[pos];
        } else {
            return pos;
        }
    }
};

// Player class stores the player's name and current board position.
class Player {
private:
    string name;
    int position;

public:
    Player(const string &n) : name(n), position(0) {}
    
    string getName() const {
        return name;
    }
    
    int getPosition() const {
        return position;
    }
    
    void setPosition(int pos) {
        position = pos;
    }
};

// Game class manages the game loop, dice roll, and player turns.
class Game {
private:
    Board board;
    vector<Player> players;
    int currentPlayerIndex;
    int winningPosition;

public:
    Game(Board b, const vector<Player> &p)
        : board(b), players(p), currentPlayerIndex(0) {
        winningPosition = board.getSize();
    }
    
    // Simulate rolling a six-sided dice.
    int rollDice() {
        return (rand() % 6) + 1;
    }
    
    // Main game loop.
    void play() {
        while (true) {
            Player &currentPlayer = players[currentPlayerIndex];
            cout << currentPlayer.getName() << "'s turn. Current position: " 
                 << currentPlayer.getPosition() << endl;
            
            int diceValue = rollDice();
            cout << "Rolled a " << diceValue << ".\n";
            
            int nextPos = currentPlayer.getPosition() + diceValue;
            if (nextPos > winningPosition) {
                cout << "Roll exceeds board size. " << currentPlayer.getName() 
                     << " stays at " << currentPlayer.getPosition() << ".\n";
            } else {
                // Check for snakes or ladders.
                nextPos = board.checkSnakeOrLadder(nextPos);
                cout << currentPlayer.getName() << " moves to position " << nextPos << ".\n";
                currentPlayer.setPosition(nextPos);
            }
            
            // Check for win condition.
            if (nextPos == winningPosition) {
                cout << currentPlayer.getName() << " wins the game!\n";
                break;
            }
            
            // Move to the next player.
            currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
            cout << "------------------------------\n";
        }
    }
};

int main() {
    // Initialize random seed.
    srand(static_cast<unsigned int>(time(0)));
    
    // Create a board of size 100.
    Board board(100);
    
    // Create players using push_back
    vector<Player> players;
    players.push_back(Player("Alice"));
    players.push_back(Player("Bob"));
    
    // Create and start the game.
    Game game(board, players);
    game.play();
    
    return 0;
}