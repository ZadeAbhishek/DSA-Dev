#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        // if its odd return no used
        if(s.size() & 1) return false;
        int balance = 0;
        int counterBalance = 0;

        // one loop from start to end (to check balaqnce for opening)
        // one loop from end to start (to check balance for closing)
        for(int i = 0, j = s.size()-1 ; i < s.size() && j >= 0 ; i++, j--){
            
            if(locked[i] == '0' || s[i] == '(') balance += 1;
            else balance -= 1;

            if(locked[j] == '0' || s[j] == ')') counterBalance += 1;
            else counterBalance -= 1;

            if(counterBalance < 0 || balance < 0) return false;
        }

        return true;
    }
};

int main(){}