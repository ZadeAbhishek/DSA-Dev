#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// ##TicTacToe ##Simulation
class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    int n;

public:
    // Init the N rows and N cols but 1 Diagonals and 1 antiDiagonals
    TicTacToe(int n) : rows(n, 0), cols(n, 0), diagonal(0), antiDiagonal(0), n(n) {}

    // Move function that updates the board and checks for a win
    int move(int row, int col, int player) {
        // Determine the value to add based on the player (1 or 2)
        int add = (player == 1) ? 1 : -1;
        
        // Update the row and column for the given move
        rows[row] += add;
        cols[col] += add;
        
        // Update the diagonal if the move is on the main diagonal
        if (row == col) {
            diagonal += add;
        }
        
        // Update the anti-diagonal if the move is on the anti-diagonal
        if (row + col == n - 1) {
            antiDiagonal += add;
        }
        
        // Check if this move caused a win in row, column, diagonal, or anti-diagonal
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antiDiagonal) == n) {
            return player;
        }
        
        // No winner yet
        return 0;
    }
};

// Driver code to test the TicTacToe implementation
int main() {
    // Initialize a TicTacToe board of size 3x3
    TicTacToe game(3);

    // Player 1 moves to (0, 0)
    cout << "Move: (0, 0), Player: 1, Result: " << game.move(0, 0, 1) << endl;  // Expected output: 0 (no one wins yet)

    // Player 2 moves to (0, 2)
    cout << "Move: (0, 2), Player: 2, Result: " << game.move(0, 2, 2) << endl;  // Expected output: 0 (no one wins yet)

    // Player 1 moves to (1, 1)
    cout << "Move: (1, 1), Player: 1, Result: " << game.move(1, 1, 1) << endl;  // Expected output: 0 (no one wins yet)

    // Player 2 moves to (0, 1)
    cout << "Move: (0, 1), Player: 2, Result: " << game.move(0, 1, 2) << endl;  // Expected output: 0 (no one wins yet)

    // Player 1 moves to (2, 2)
    cout << "Move: (2, 2), Player: 1, Result: " << game.move(2, 2, 1) << endl;  // Expected output: 1 (Player 1 wins by completing the diagonal)

    return 0;
}