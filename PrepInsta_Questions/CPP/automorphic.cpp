// Write a code to find an Automorphic number

#include<bits/stdc++.h>
using namespace std;

int main(){
    int num,flag;
    flag = 0;
    cout<<"Enter No : ";
    cin>>num;
    int sq = num * num;
    while(num>0){
        if(sq%10 != num%10){
            flag = 1;
            break;
        }
        num /= 10;
        sq /= 10; 
    }
    if(flag) cout<<"NO AUTOMORPHIC";
    else cout<<"AUTOMORPHIC";
    return 0;
}