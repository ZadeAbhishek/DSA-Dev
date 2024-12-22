/*
Time limit: 1.00 s
Memory limit: 512 MB



Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.
Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints

1 \le n \le 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848


explanation https://www.geeksforgeeks.org/cses-solutions-two-knights/
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i = 1 ; i <= t; i++){
        long totalWays = (long)((i * i) * (i * i - 1 )) / 2;
        long totalAttackingWays = 4 * (i - 1) * (i - 2);
        cout<<totalWays - totalAttackingWays<<endl;
    }
    return 0;
}
