/*
Time limit: 1.00 s
Memory limit: 512 MB



You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.
Input
The first input line has an integer t: the number of tests.
After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.
Output
For each test, print "YES" if you can empty the piles and "NO" otherwise.
Constraints

1 \le t \le 10^5
0 \le a, b \le 10^9

Example
Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<pair<int,int>> piles;
    while(t--){
        int p1, p2;
        cin>>p1>>p2;
        piles.push_back({p1,p2});
    }
    for(auto pile : piles){
        int p1 = pile.first;
        int p2 = pile.second;
        
        // Check if the sum of all are odd and on pile is greater than other pile
        if(((p1 + p2) % 3 == 0) && (2 * p1) >= p2 && (2 * p2) >= p1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}