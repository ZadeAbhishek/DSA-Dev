/*
Time limit: 1.00 s
Memory limit: 512 MB



A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example 1
Input:
5

Output:
4 2 5 3 1
Example 2
Input:
3

Output:
NO SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> currList){
    for(int i = 1 ; i < currList.size(); i++){
        if(abs(currList[i] - currList[i-1]) == 1) return false;
    }
    return true;
}

void solve(int n, vector<int> &visited, vector<int> currList, vector<int> &result){
    if(currList.size() == n){
        if(check(currList)) result = currList;
        return;
    }
    for(auto x = 1; x <= n; x++){
       if(visited[x] == -1){
          currList.push_back(x);
          visited[x] = 1;
          solve(n,visited,currList,result);
          currList.pop_back();
          visited[x] = -1;
       }
    }
}

int main(){
    // basically dp needed
    int n = 0;
    cin>>n;
    vector<int> visit(n+1,-1);
    vector<int> result;
    solve(n,visit,{},result);
    if(result.size() == 0) cout<<"NO SOLUTION";
    else {
        for(auto x : result) cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}


// more optimised approch 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
    } else {
        // Print all even numbers first
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        // Print all odd numbers
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}