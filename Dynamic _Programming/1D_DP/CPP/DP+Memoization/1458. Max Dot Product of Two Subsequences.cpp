class Solution {
    int n1;
    int n2;
    vector<int> array1;
    vector<int> array2;
    vector<vector<int>> dp;
    int res = INT_MIN;
    int solve(int i , int j){
        // edge case
        if(i == n1 || j == n2) return INT_MIN;

        // check dp
        if(dp[i][j] != INT_MIN) return dp[i][j];

        int x = array1[i] * array2[j];

        int ans = max({x,x+(i+1 < n1 && j+1 < n2 ? solve(i+1,j+1):0),solve(i,j+1),solve(i+1,j)});
        res = max(res,ans);
        return dp[i][j] = ans; 
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        array1 = nums1;
        array2 = nums2;
        n1 = nums1.size();
        n2 = nums2.size();
        dp.resize(n1+1,vector<int>(n2+1,INT_MIN));
        solve(0,0);
        return res; 
    }
};