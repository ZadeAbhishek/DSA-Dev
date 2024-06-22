class Solution {
public:
    bool checkZeroOnes(string s) {
       // we can use direct approch
       int maxZeros = 0;
       int maxOnes = 0;
       int ones = 0;
       int zeros = 0;
       for(int index = 0 ; index < s.size() ; index++){
           int currentDigit = s[index] == '1'?1:0;
           if(currentDigit){
              ones++;
              maxOnes = max(maxOnes,ones);
              zeros = 0;
           }
           else {
             zeros++;
             maxZeros = max(maxZeros,zeros);
             ones = 0;
           } 
       }

       if(maxZeros >= maxOnes) return false;
       else return true;
        
    }
};