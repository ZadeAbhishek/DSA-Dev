/*
Number Spiral
Time limit: 1.00 s
Memory limit: 512 MB



A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.
Constraints

1 \le t \le 10^5
1 \le y,x \le 10^9

Example
Input:
3
2 3
1 1
4 2

Output:
8
1
15


explanation : https://medium.com/@Rigor_08/cses-number-spiral-solution-304bebe1793b
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    // input
    ll t;
    cin>>t;
    for(int i = 1 ; i <= t ; i++){
    ll x,y;
    cin>>x>>y;
      

    // check of inner circle or outer circle
    ll maxiNum = max(x,y);
    ll innerCircle = (maxiNum - 1) * (maxiNum - 1);
    ll outerCircle = maxiNum * maxiNum;

    if(maxiNum % 2 == 0){
        if(x > y) cout<<innerCircle + y<<endl;
        else cout<<outerCircle - x + 1<<endl;
    }
    else{
        if(x > y) cout<<outerCircle - y + 1<<endl;
        else cout<<innerCircle + x<<endl;
    }
    
    }

    return 0;

}