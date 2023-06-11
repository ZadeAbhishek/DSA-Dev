#include <bits/stdc++.h>
using namespace std;

int main() {
 int f = 0;
 cin>>f;
 int day = 1;
 while(f >= day){
     f = abs(f - day);
     f += 1;
     day++;
 }
 cout<<day - 1<<" "<<f;
}