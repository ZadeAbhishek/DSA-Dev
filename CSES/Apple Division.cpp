/*
Time limit: 1.00 s
Memory limit: 512 MB



There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,\dots,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 \le n \le 20
1 \le p_i \le 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<long long> &apples, int index , long long  currSum, long long &minDiff, long long &total){
    // base case
    if(index == apples.size()){
        long long otherDiff = total - currSum;
        long long groupDiff = llabs(otherDiff - currSum);
        if(groupDiff < minDiff) minDiff = groupDiff;
        return;
    }


    // regular case
    // take
    solve(apples, index + 1, currSum + apples[index], minDiff,total);
    solve(apples, index + 1, currSum, minDiff,total);
    return;
}

int main(){
    long long vecSize = 0;
    cin >> vecSize;

    vector<long long> apples;
    apples.reserve(vecSize);

    for(int i = 0; i < vecSize; i++){
        long long temp = 0;
        cin >> temp;
        apples.push_back(temp);
    }

    long long total = 0;
    for(auto &x : apples) {
        total += x;
    }

    long long minDiff = LLONG_MAX;

    solve(apples, 0, 0, minDiff, total);

    cout << minDiff << "\n";

    return 0;   
}