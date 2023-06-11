#include<bits/stdc++.h>
using namespace std;


string reverse_words(string &s){
    s.push_back(' ');
    vector<string> arr;
    string temp = "";
    
    for(auto c : s){
        if(c == ' ') {
            arr.push_back(temp);
            temp.clear();
            continue;
        }
        temp += c;
    }
 
     s.clear();
    for(auto i = arr.size() - 1 ; i > 0 ; i--){
        s += arr[i] + " ";
    }
    s += arr[0] + " "; 
    return s;
}

int main(){
    string s = "Declare and implement your function here eg:function example";
    reverse_words(s);
    cout<<s;
}