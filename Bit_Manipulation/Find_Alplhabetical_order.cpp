#include<bits/stdc++.h>
using namespace std;

char getOrder(char c){
    cout<<(c & 31)<<endl;
    return 0;
}

int main(){
    char c;
    cin>>c;
    cout<<getOrder(c)<<endl;
}