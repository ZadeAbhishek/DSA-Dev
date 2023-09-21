#include<bits/stdc++.h>
using namespace std;

// word checker
bool checkWord(vector<string> table,string s){
     int i = 0;
     while(i < table.size()){
        if(table[i] == s)
        return true;

        i++;
    }
    string temp; 
    temp = sub

}

int main() {
    // hashmap
   vector<string> table;
   table.push_back("IBM");
   table.push_back("I");
   table.push_back("LOVE");

   string s = "ILOVEIBM";
 cout<<checkWord(table,s);
   // idea is to use two pointer
//    int i,j;
//    i = j = 0;
//    string temp;
//    while(j<s.size()){
//     int t = i;
//     while(t <= j){
//         temp.push_back(s[t]);
//         t++;
//     }
    
//     for(auto x = 0 ; x < table.size() ; x++){
//         if(temp == table[x]){
//             i = j+1;
//             break;
//         }
//     }
//      temp.erase();
//      j++;
//    }
   
//    if(j = i+1 )
//    return true;
//    else 
//    return false;
}
