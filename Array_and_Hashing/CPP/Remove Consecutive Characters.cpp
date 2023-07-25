#include<iostream>
#include<string.h>
#include<set>
using namespace std;
     
    string removeConsecutiveCharacter(string S)
    {
      
      int i = 0;
      int j = 0;
      while(true){
        
        

        if(S[i] == S[j]) j++;
        else if(S[i] != S[j]){
             i++;
             S[i] = S[j];
             j++;
        }

        if(S[j] == '\0') {
            i++;
            int len = S.size(); 
            while(i < S.size()) S[i] = '\0',i++; 
            break;
        }
      }

      return S;
    }


int main(){

    string s = "jfsjfksfkdfddddfddfdedddfsd";
    s.push_back('\0');
    cout<<removeConsecutiveCharacter(s)<<"\n";
}

/*

jfsjfksfkdfdfdfdedfsd
jfsjfksfkdfdfdfdedfsd
*/