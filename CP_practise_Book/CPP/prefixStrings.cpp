#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

bool checkSub(string a, string b){
    unordered_map<char,int> aplha;
    for(auto i = 65 ; i <= 90 ; i++){
        aplha.insert({char(i),0});
    }
    for(auto i : a){
        aplha[i]++;
    }
    int count = 0;
    for(auto i : b){
        if(aplha.count(i)){
            count++;
        }
        if(count){
            return true;
        }
    }
    return false; 
}

bool isPrefix(string a, string b){
    stack<char> revstack;
    stack<char> stackA;
    stack<char> stackB;
    
    for(auto it : a){
        revstack.push(it);
    }
    while(!revstack.empty()){
       stackA.push(revstack.top());
       revstack.pop(); 
    }
    for(auto it : b){
        revstack.push(it);
    }
    while(!revstack.empty()){
       stackB.push(revstack.top());
       revstack.pop(); 
    }
    while(!stackB.empty() && !stackA.empty()){
        if(stackA.top() == stackB.top()){
            stackB.pop();
            stackA.pop();
            continue;
        }
        break;
    }
    if(stackA.empty() && !stackB.empty()){
        return true;
    }
    if(stackB.empty() && stackA.empty()){
        return true;
    }
    if(!stackA.empty() && stackB.empty()){
        return false;
    }
    return false;
}
void noPrefix(vector<string> words) {
    stack<string> res;
    unordered_map<string,string> tab;
    for(auto it = 0 ; it < words.size(); it++){
        for(auto jt = 0 ; jt < words.size(); jt++){
            cout<<it<<" "<<jt<<"\n";
            //  bool result = checkSub(words[it],words[jt]);
             if(it == jt) continue;
             bool pre = isPrefix(words[it],words[jt]);
             if(pre){
                // cout<<words[it]<<"\n";
                 res.push(words[it]);
                 tab.insert({words[it],words[jt]});
             }
           
        }
    }
    if(!res.empty()){
         cout<<"BAD SET \n";
         cout<<tab[res.top()]<<"\n";
         return;
    }
    cout<<"GOOD SET";
    return;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
