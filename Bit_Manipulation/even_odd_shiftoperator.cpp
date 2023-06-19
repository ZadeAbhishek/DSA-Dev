// >> right divides
// << left multiply
#include<bits/stdc++.h>
using namespace std;
int main(){
   int n = 0;
   cin>>n;
   int x = (n >> 1)<<1;
   if(n == x) cout<<"even";
   else cout<<"odd";
   return 0;
}