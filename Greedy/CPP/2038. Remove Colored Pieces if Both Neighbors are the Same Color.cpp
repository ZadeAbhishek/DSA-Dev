class Solution {
public:
    bool winnerOfGame(string colors) {
        int AliceScore = 0;
        int BobScore = 0;
        for(int i = 1 ; i < colors.size()-1 ; i++){
            char currColor = colors[i];
            char prevColor = colors[i-1];
            char nextColor = colors[i+1];

            // Alice can only change if there is A
            if(currColor == 'A' && prevColor == 'A' && nextColor == 'A') AliceScore++;

            // Bob can only change if there is B
            if(currColor == 'B' && prevColor == 'B' && nextColor == 'B') BobScore++;

        }
        return AliceScore > BobScore;
    }
};