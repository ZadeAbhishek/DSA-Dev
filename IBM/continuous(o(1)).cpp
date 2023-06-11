#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // int minOperations(vector<int>& A) {
    //     int N = A.size(), i = 0, j = 0;
    //     sort(begin(A), end(A));
    //     A.erase(unique(begin(A), end(A)), end(A)); // only keep unique elements
    //     for (int M = A.size(); j < M; j++) {
    //         if (A[i] + N <= A[j]) ++i;
    //     }
    //     return N - j + i;
    // }
     int minOperations(vector<int>& A) {
        int N = A.size();
        sort(begin(A),end(A)); // function to sort array
        vector<int> difference;
        difference.push_back(A[0]);
        
        // This will help to remve any duplicate no
        for(auto i = 1 ; i < N ; i++) {
          if(A[i] != A[i-1]) difference.push_back(A[i]);
        }

        // we will check for each window so we have that element 
        // let say 1 2 2 6 10  N = 5 
        // 1 2 6 10 M = 4 
        
        auto j = 0;
        int m = INT_MIN;
        for(auto i = 0; i < size(difference) ; i++ )
        {
            if(difference[i] <= difference[j] + (N-1)) m = max(m,i-j+1);
            else j++; 
        }
        return N - m;

    }
};

int main(){

    vector<int> S = {4,2,5,3};
    Solution* solve = new Solution();
    cout<<solve->minOperations(S);
}