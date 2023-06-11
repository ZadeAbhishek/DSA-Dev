#include <bits/stdc++.h>
using namespace std;

// this is also good solution
// class Solution
// {
// public:
//     int rob(vector<int> &A){
//         vector<int> memo(1001,-1);
//         return rob(A,0,memo);
//     }
    
//     int rob(vector<int> &A, int i, vector<int> &memo)
//     {

//         if (i >= size(A))
//             return 0;

//         if (memo[i] != -1)
//             return memo[i];

//         return memo[i] = max(rob(A, i + 1,memo), A[i] + rob(A, i + 2,memo));
//     }
// };


// optimised itrative and 0(1) space complexity
class Solution
{
public:
    
    int rob(vector<int> &A)
    {
        if(size(A) == 1) return A[0];
        A[1] = max(A[1],A[0]);
        for(auto i = 2 ; i < size(A) ; i++){
            A[i] = max(A[i - 1], A[i] + A[i - 2]);
        }
        return A[size(A) - 1];
    }
};

int main()
{
    vector<int> cost = {2,7,9,3,1};
    Solution *solve = new Solution();
    cout << solve->rob(cost);
}


/*


Solution - I (Brute-Force)

Let's try solving with brute-force approach. For each house, we have two choices -

Dont rob the house and move to next house.
Rob the house and move to the house after next house (We dont move directly to next house because we can rob adjacent houses).
So, we will just try with both these choices and choose the one the yields the maximum amount of loot.

C++

class Solution {
public:
    int rob(vector<int>& A, int i = 0) {
        return i < size(A) ? max(rob(A, i+1), A[i] + rob(A, i+2)) : 0;
    }
};
Python

class Solution:
    def rob(self, A, i = 0):
        return max(self.rob(A, i+1), A[i] + self.rob(A, i+2)) if i < len(A) else 0
Time Complexity : O(2N), where N is the number of elements in A. At each index, we have two choices of either robbing or not robbing the current house. Thus this leads to time complexity of 2*2*2...n times ≈ O(2N)
Space Complexity : O(N), required by implicit recursive stack. The max depth of recursion can go upto N.

✔️ Solution - II (Dynamic Programming - Memoization)

In the above solution, we were performing many redundant repeated computations. This can be observed by drawing out the recursive tree for above function and observing that rob(i) is called multiple times. But rob(i) is nothing but the maximum amount of loot we can get starting at index i and this amount remains the same at each call.

So, instead of re-computing multiple times, we can store the result of a function call and directly reuse it on future calls instead of recomputing from scratch. This calls for dynamic programming, or memoization to be more specific. Here, we can use a linear dp array where dp[i] will denote the maximum amount of loot we can get starting at i index. Initially all elements of dp are initialized to -1 denoting they haven't been computed yet, Each time, we will save the computed result in this dp for an index i and directly return it if a future call is made to this index.

C++

class Solution {
public:
    int rob(vector<int>& A) {
        vector<int> dp(size(A),-1);
        return rob(A, dp, 0);
    }
    int rob(vector<int>& A, vector<int>& dp, int i) {
        if(i >= size(A)) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(rob(A, dp, i+1), A[i] + rob(A, dp, i+2));
    }
};
One-Liner
Python

class Solution:
    def rob(self, A):
        @cache
        def rob(i):
            return max(rob(i+1), A[i] + rob(i+2)) if i < len(A) else 0
        return rob(0)
Time Complexity : O(N), We calculate the result for each index only once & there are N indices. Thus overall time complexity is O(N).
Space Complexity : O(N), required for dp and implicit recursive stack.

✔️ Solution - III (Dynamic Programming - Tabulation)

We can implement the same logic as above in an iterate approach as well. Here, we again use a dp array to save the results of computation. In this case, dp[i] will denote maximum loot that we can get by considering till ith index. At every index,

We can keep same loot as we had at previous index - dp[i-1]
Or, we can rob the current house and add it to the loot we have at i-2th index - A[i] + dp[i-2]
C++

class Solution {
public:
    int rob(vector<int>& A) {
        if(size(A) == 1) return A[0];
        vector<int> dp(A);
        dp[1] = max(A[0], A[1]);
        for(int i = 2; i < size(A); i++)
            dp[i] = max(dp[i-1], A[i] + dp[i-2]);
        return dp.back();
    }
};
Python

class Solution:
    def rob(self, A):
        if len(A) == 1: return A[0]
        dp = [*A]
        dp[1] = max(A[0], A[1])
        for i in range(2, len(A)):
            dp[i] = max(dp[i-1], A[i] + dp[i-2])
        return dp[-1]
Time Complexity : O(N), just single iteration is performed from 2 to N to compute each dp[i].
Space Complexity : O(N), required for dp.

✔️ Solution - IV (Space-Optimzed Dynamic Programming)

We can observe that the above dp solution relied only on the previous two indices in dp to compute the value of current dp[i]. So, we dont really need to maintain the whole dp array and can instead just maintain the values of previous index (denoted as prev below) and previous-to-previous index (denoted as prev2) and we can calculate the value for current index (cur) using just these two variables and roll-forward each time.

C++

class Solution {
public:
    int rob(vector<int>& A) {
        int prev2 = 0, prev = 0, cur = 0;
        for(auto i : A) {
            cur = max(prev, i + prev2);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};
Python

class Solution:
    def rob(self, A):
        prev2, prev, cur = 0,0,0
        for i in A:
            cur = max(prev, i + prev2)
            prev2 = prev
            prev = cur
        return cur
Time Complexity : O(N)
Space Complexity : O(1), only constant extra space is used.


*/