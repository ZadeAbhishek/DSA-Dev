// 1769. Minimum Number of Operations to Move All Balls to Each Box


// brute force
class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> onesIndex;
        for(int i = 0 ; i < boxes.size() ; i++){
            if(boxes[i] == '1') onesIndex.push_back(i);
        }
        
        vector<int> answer(boxes.length());
        for(int i = 0 ; i < boxes.size() ; i++){
            for(int j = 0 ; j < onesIndex.size() ; j++){
                answer[i] += abs(onesIndex[j] - i);
            }
        }
        return answer;
    }
};

// optimise prefix solution
class Solution {
public:
    vector<int> minOperations(string boxes) {
        // prefix approch we can use
        vector<int> answer(boxes.size(),0);
        int countOnes = 0;
        int moves = 0;
        for(int index = 0 ; index < boxes.size() ; index++){
              answer[index] = moves;
              countOnes += boxes[index] == '1'?1:0;
              moves += countOnes;
        }
        countOnes = 0;
        moves = 0;
        for(int index = boxes.size() - 1; index >= 0 ; index--){
              answer[index] += moves;
              countOnes += boxes[index] == '1'?1:0;
              moves += countOnes;
        }
        return answer;
    }
};