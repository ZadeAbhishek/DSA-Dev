//Find the position of rightmost set bit

#include<bits/stdc++.h>
using namespace std;
int main(){
   unsigned int n = 7;
   cout<<(n & ~(n-1))<<"\n";
}