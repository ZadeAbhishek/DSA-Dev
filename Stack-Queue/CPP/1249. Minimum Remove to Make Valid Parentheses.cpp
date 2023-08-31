#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;

        for(auto x = 0 ; x < s.size() ; x++){
            
            if(s[x] == '(') stk.push(x);
            else if(s[x] == ')' && stk.empty()) s[x] = '#';
            else if(s[x] == ')') stk.pop();

            
        }
        
        string res = "";

        if(stk.empty()){
        for(auto &x : s) if(x != '#') res.push_back(x);
        }
        else{
           while(!stk.empty()) s[stk.top()] = '#',stk.pop();
           for(auto &x : s) if(x != '#') res.push_back(x);
        }

        return res;
    }
};


class Solution2 {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0;
        
        for(auto &x : s){

            if(x == '(') balance++;
            else if(x == ')' && balance == 0) x = '#';
            else if(x == ')') balance--;

        }

        string res = "";

        if(balance == 0){
            for(auto &x : s) if(x != '#') res.push_back(x);
        }
        else{
            for(signed int x = s.size()-1 ; x >= 0 ; x--) if(s[x] == '(' && balance) s[x] = '#',balance--; 
            for(auto &x : s) if(x != '#') res.push_back(x);
        }


        return res;
    }
};



int main(){
    Solution2 s;
    cout<<s.minRemoveToMakeValid("))((")<<"\n";

}

