// Bitwaise And of a lowercase charector with '_' will unset/clear the third bit
// and we will get uppercase Charector

#include<bits/stdc++.h>
using namespace std;

// we can convert lower case to upperCase by char and with dash (c & '')

char toUpper(char c){
    return (c & '_');
}

int main(){
    char c;
    cin>>c;
    cout<<toUpper(c)<<endl;
}