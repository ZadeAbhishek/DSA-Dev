class Solution {
public:
    bool isValid(string t) {
        stack<char> s;
        for(auto x:t){
            if(x == '}'){
                if(s.empty()) return false;
                if(s.top() == '{') s.pop();
                else return false;
            }
            else if(x == ')'){
                if(s.empty()) return false;
                if(s.top() == '(') s.pop();
                else return false;
            }
            else if(x == ']'){
                if(s.empty()) return false;
                if(s.top() == '[') s.pop();
                else return false;
            }
           else s.push(x);
        }
        if(s.empty()) return true;
        else return false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};