// https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// https://www.youtube.com/watch?v=xElxAuBcvsU&ab_channel=takeUforward


#include<bits/stdc++.h>
using namespace std;


// first we will take LCS longest common subsequence

vector<vector<int>> longest_common_subsequence(string a, string b){
       
       // size
       int sizeA = a.size();
       int sizeB = b.size();

       // we will do 1-index
       vector<vector<int>> dp(sizeA+1,vector<int>(sizeB+1,0));

       for(int i = 1 ; i <= sizeA ; i++){
        for(int j = 1 ; j <= sizeB ; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
       }

       return dp;
}

string backtrack(vector<vector<int>> &dp,string a, string b){
    string result = "";
    int sizeA = a.size();
    int sizeB = b.size();

    int i = sizeA ;
    int j = sizeB ;

    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            result += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            result += a[i-1];
            i--;
        }
        else{
            result += b[j-1];
            j--;
        }
    }

    if(i > 0) result += a[i-1], i--;
    if(j > 0) result += b[j-1], j--;

    return result;
}

string shortestSupersequence(string a, string b)
{
    vector<vector<int>> dp = longest_common_subsequence(a,b);
    string result = backtrack(dp,a,b);
    reverse(result.begin(),result.end());
	return result;
}

int main(){
     string x = "brute";
     string y = "groot"; 
     cout<<shortestSupersequence(x,y)<<"\n";
}