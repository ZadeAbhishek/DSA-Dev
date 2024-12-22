/*
Time limit: 1.00 s
Memory limit: 512 MB



Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
Constraints

1 \le n \le 10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n, int totalsum, int index, unordered_map<int,int> &set1, int currSum){
    if(currSum == totalsum){
        return 1;
    }
    if(currSum > totalsum){
     return 0;
    }

    for(int i = index ; i <= n; i++){
        currSum += i;
        int check = solve(n,totalsum,index+1,set1,currSum);
        if(check){
            set1[i] = i;
            return 1;
        }
        currSum -= i;
    }
    return 0;
}


int main(){
    long n = 0;
    cin>>n;
    long long total =  (long) (n * (n + 1)) / 2;
    if(total % 2 == 0){
        // possible
        unordered_map<int,int> set1;
        solve(n,total/2,1,set1,0);
        if(set1.size() < n){
            // possible 
            vector<int> set2;
            vector<int> set1_1;
            for(int i = 1; i <= n ; i++){
                if(set1.count(i)) set1_1.push_back(i);
                else set2.push_back(i);
            }
            for(auto x : set1_1) cout<<x<<" ";
            cout<<endl;
            for(auto x : set2) cout<<x<<" ";
            cout<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    } 
    else {
        // impossible
        cout<<"NO"<<endl;
    }
    return 0;
     
}



// optmised approch greedy approch used here
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        // Impossible to divide into two subsets
        cout << "NO\n";
    } else {
        // Possible to divide
        cout << "YES\n";
        long long target = total / 2;

        vector<int> set1, set2;

        for (long long i = n; i >= 1; i--) {
            if (target >= i) {
                set1.push_back(i);
                target -= i;
            } else {
                set2.push_back(i);
            }
        }

        // Output set 1
        cout << set1.size() << "\n";
        for (int x : set1) cout << x << " ";
        cout << "\n";

        // Output set 2
        cout << set2.size() << "\n";
        for (int x : set2) cout << x << " ";
        cout << "\n";
    }

    return 0;
}