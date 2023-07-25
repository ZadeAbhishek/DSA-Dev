// Alien Grammer

#include <bits/stdc++.h>
using namespace std;

int main() {
     string s;
     string t;
     getline(cin,s);
     int sq = 0; //sqaure
     int c = 0; //circle braket
     bool result = true; // flag 
     char missing = ' ';
     // irr over string
     for(auto i = 0 ; i < s.size() - 1; i++){
         

         if(s[i] == '{' && sq == 0) {
             sq = 1;
             continue;
         }
         if(s[i] == '{' && sq == 1){
             result = false;
             missing = '}';
             break; 
         }
         if(s[i] == '}' && sq == 1 && c == 1 ){ 
             result = false;
             missing = ')';
             break;
         }
         if(s[i] == '}' && sq == 1){ 
             sq = 0;
             continue;
         }
         
         if(s[i] == '(' && c == 0){
             c = 1;
             t = "";
             continue;
         }
         if(s[i] == '(' && c == 1){
             result = false;
             missing = ')';
             break;
         }
         if(s[i] == ')' && c == 1){
             c = 0;
             t = "";
             continue;
         }
         if(s[i] == ')' && c == 0){
            result = false;
            missing = '(';
             break;
         }
         if(sq == 1){
             t += s[i];
             continue;
         }
         if(c == 0 && sq == 1 && s[i] != ' '){
             t = "";
             for(auto j = i ; j < s.size() - i ; i++){
                 if(s[j] == ')') {
                     result = false;
                     missing = ')';
                     break;
                 }
                 t += s[j];
             }
             t += s[i];
             continue;
         }
    }
    if(missing == ')' && !result) cout<<"Invalid message -> missing "<<"'"<<missing<<"'"<<"After "<<t<<"\n";
    else if(missing == '(' && !result) cout<<"Invalid message -> missing "<<"'"<<missing<<"'"<<"Before "<<t<<"\n";
    else if(s[(s.size() - 1)] != '!') cout<<"Invalid Message missing '!' ";
    else cout<<"valid message";
    
    return 0;
    
}