// Check if the number is a power of 2?

#include<bits/stdc++.h>
using namespace std;
int main(){
   int n = 0;
   cin>>n;
   int x = n - 1;
   if(!(n&x)) cout<<"Yes"; 
   else cout<<"No";
   return 0;
}