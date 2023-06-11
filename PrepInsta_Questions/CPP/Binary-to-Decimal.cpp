// Write a program for Binary to Decimal to conversion

#include<bits/stdc++.h>
using namespace std;

int convert(long i){
    int x = 0, decimal = 0;
    int resut = 0;
   while(i != 0){
    int rem = i % 10;
    int res = rem * pow(2,x);
    x++;
    i /= 10;
    resut += res; 
}
return resut;
}

int main(){
long i = 0;
cout<<"Enter No: ";
cin>>i;
cout<<"\n"<<convert(i);
return 0;
}