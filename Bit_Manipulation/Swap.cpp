#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 7;
    int b = 5;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<a<<" "<<b<<endl;
    return 0;
}