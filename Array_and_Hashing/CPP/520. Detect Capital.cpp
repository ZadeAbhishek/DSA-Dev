#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    // this function return if char is upper or not
    // AISCCI val of A = 65 and Z = 96
    bool isUpper(char temp)
    {
        int char_temp = (int)temp; // char to int convertion
        if(char_temp >= 65 && char_temp <= 96) return true;
        else return false;
    }
    
    bool detectCapitalUse(string word) {
        // check if first letter is upper or not
        bool first_captial = isUpper(word[0]);

        //counter for capital
        int capital = 0;

        // iterate over string calucate cappital
        for(auto i : word) if(isUpper(i)) capital++;

        // All case 
        if(capital == size(word) || capital == 1 && first_captial || capital == 0) return true;
        
        // else false
        return false;
    }
};