#include <bits/stdc++.h>
using namespace std;

int main() {
 int n = 0;
 cin>>n;
 int complete = 0 , incomplete = 0;
 int height = 1;
 for(int i = 1 ; i <= n; i++){
     
     if(n >= height){ 
     n -= height;
     height++;
     }
     else{
         break;
     }
     if(n == 0){
             complete = incomplete = height - 1;
         }
         else{
             complete = height - 1;
             incomplete = height;
         }
 }
 cout<<complete<<" "<<incomplete;
}