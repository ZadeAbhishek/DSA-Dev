#include<bits/stdc++.h>
using namespace std;


bool check_sub_string(string a, string b)
{
    int l1 = size(a);
    int l2 = size(b);
    int memo[l1][l2];
    
    for(auto i = 0 ; i < l1 ; i++){
        for(auto j = 0 ; j < l2 ; j++){
            if(a[i] != b[j]){
                if(i == 0 && j == 0) memo[i][j] = 0;
                else if(i == 0 && j != 0) memo[i][j] = memo[i][j-1];
                else if(i !=0) memo[i][j] = memo[i-1][j];
            }
            else {
                if(i == 0 && j == 0) memo[i][j] = 1;
                else memo[i][j] = memo[i][j-1] + 1;
            } 
        }
    }
    //cout<<memo[l1-1][l2-1]<<"\n";
    if(memo[l1-1][l2-1] > 1) return true;
    else return false;
}

int main() {
    string a = "Hacker Who Has Access To Your Operating System";
    string b = "Hacker Who Has Access To Your Operating System";
    bool result = check_sub_string(a,b);
    if(result) cout<<"Contains SuBstring"<<"\n";
    else cout<<"Dont Contains SuBstring"<<"\n";
    return 0;
}