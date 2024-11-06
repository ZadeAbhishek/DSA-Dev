
// ##Simulation
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        // Creata a 2D board
        vector<string> board(9,".");
        /*
        0 1 2
        3 4 5
        6 7 8
       
        winning position are 
        0 1 2 , 3 4 5 , 6 7 8 , 0 3 6 , 1 4 7, 2 5 8 , 0 4 8 , 2 4 6
        */
        // add Values to board
        int parity = 1;
        for(auto x : moves){
            int currentCoordinate = (x[0] * 3) + x[1]; 
            if(parity) board[currentCoordinate] = "A";
            else board[currentCoordinate] = "B";
            parity = !parity;
        }

        // check all winning positions for board
        vector<vector<int>> winningPos = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
        for(auto x : winningPos){
            string a = board[x[0]];
            string b = board[x[1]];
            string c = board[x[2]];

            if((a != "." || b != "." || c != ".") && (a == b) && (b == c)) return board[x[0]];
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 4; // Adjust the board size to 4x4
        vector<int> rows(n, 0), cols(n, 0);
        int diag = 0, antiDiag = 0;
        int player = 1; // Player A starts with +1, Player B with -1

        for (auto move : moves) {
            int row = move[0], col = move[1];
            
            // Update counters based on the player
            rows[row] += player;
            cols[col] += player;
            if (row == col) diag += player;
            if (row + col == n - 1) antiDiag += player;
            
            // Check if this move resulted in a win
            if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(antiDiag) == n)
                return player == 1 ? "A" : "B";
            
            // Switch player for the next move
            player = -player;
        }

        // If all moves are done and no winner, check if it's pending or a draw
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};