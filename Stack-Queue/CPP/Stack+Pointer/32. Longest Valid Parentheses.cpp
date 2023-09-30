#include<bits/stdc++.h>
using namespace std;

// 2 pass solution without stack 
int longestValidParentheses(string s) {
         int opening = 0;
         int closing = 0;
         int maxValid = 0;

         // pass 1
         for(int index = 0 ; index < s.size(); index++){
            // increment the open and close
            if(s[index] == '(') opening++;
            else if(s[index] == ')') closing++;
            
            // check validity according to count
            if(opening == closing) {
                maxValid = max(maxValid,opening*2);
            }
            else if(closing > opening) opening = 0, closing = 0;
         }

          // this is reverse pass somecase need "(()"
          // pass 2
            opening = 0;
          closing = 0;
         for(int index = s.size()-1 ; index >= 0; index--){
            // increment the open and close
            if(s[index] == '(') opening++;
            else if(s[index] == ')') closing++;
            
            // check validity according to count
            if(opening == closing) {
                 maxValid = max(maxValid,opening*2);
            }
            else if(opening > closing) opening = 0, closing = 0;
         }
         return maxValid;
    }


// 1 pass solution
// (())()())
// i = 0 s =  0 -1 
// i = 1 s =  1  0 -1 
// i = 2 s =  0 -1     l = 2 - 0 = 2
// i = 3 s = -1        l = 3 + 1 = 4
// i = 4 s =  4 -1 
// i = 5 s = -1        l = 5 + 1 = 6
// i = 6 s =  6 -1
// i = 7 s = -1        l = 7 + 1 = 8
// i = 8 s =  e        
int longestValidParentheses1Pass(string s){
    // stack to track opening index
    stack<int> sq;
    sq.push(-1); // start point to get valid length
    int maxValid = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '(') sq.push(i);
        else{
            sq.pop();
            if(sq.empty()) sq.push(i); // this defines new starting point for
            else maxValid = max(maxValid,(i-sq.top()));
        }
    }
    return maxValid;

}


int main(){
    string question = "(())()())";
    cout<<longestValidParentheses(question)<<"\n";
    cout<<longestValidParentheses1Pass(question)<<"\n";
}