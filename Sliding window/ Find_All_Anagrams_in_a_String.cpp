// we can optimised more of this 
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    
    bool check_anagram(string s,vector<int> aux_p){
        vector<int> temp(200,0);
        
        for(auto x : s) temp[(int)x]++;
        
        int i = 0;
        
        while(i < 200) {
            if(!(temp[i] == aux_p[i])) return false;
            i++;
        }
        return true;
        
    } 
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> aux_p(200,0);
        
        vector<int> result;
        
        for(auto x : p) aux_p[(int)x]++; // compelte aux with p string
        
        int x = 0 , y = p.size();
        
        while(y <= s.size())
        {
           bool res = check_anagram(s.substr(x,p.size()),aux_p);
            
            if(res) {
                result.push_back(x);
                res = false;
            }
            
            x++;
            y++;
        }
        
        return result;
    }
};


int main() {
    Solution solution;

    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = solution.findAnagrams(s, p);

    cout << "Indices of anagram occurrences: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

// optimised version