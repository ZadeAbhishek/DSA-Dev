#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
 string s;
 getline(cin,s);
 int count = 0;
 for(auto i = 0 ; i < s.size() ; i++)
 {
     if((s[i] != ' ')) count++;
        
     else {
         if(count > 3) s[i-1] = toupper(s[i-1]);
         count = 0;
     }
}
 
 if(count>3)  s[s.size()-1] = toupper(s[s.size()-1]);
 cout<<s;
}