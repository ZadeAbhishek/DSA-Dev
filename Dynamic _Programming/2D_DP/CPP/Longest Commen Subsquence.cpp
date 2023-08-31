#include<bits/stdc++.h>
using namespace std;


// optimised 
int longestCommonSubsequence(string text1, string text2) {
        
        // idea is to use dp tabulation method

        int size_text1 = size(text1);
        int size_text2 = size(text2);
       

        // buffer table
        vector<vector<int>> string_table(size_text1,vector<int>(size_text2,0));

        // calculate occuraences

        for(auto i = 0 ; i < size_text1 ; i++)
        {
            for(auto j = 0 ; j < size_text2; j++)
            {
                if(text1[i] == text2[j]) {
                    if(i-1 >= 0 && j - 1 >= 0) string_table[i][j] = 1 + string_table[i-1][j-1];
                    else string_table[i][j] = 1;
                }
                else
                {
                     if(i-1 >= 0 && j-1 >= 0) string_table[i][j] = max(string_table[i-1][j],string_table[i][j-1]);
                     else if(i == 0 && j > 0) string_table[i][j] = string_table[i][j-1];
                     else if(i > 0 && j == 0) string_table[i][j] = string_table[i-1][j];

        
                }
        }
        }
        return string_table[size_text1-1][size_text2-1];

    }
// more optimised
int longest_common_subsequence_optimised(string a, string b){
       
       // size
       int sizeA = a.size();
       int sizeB = b.size();
       
       // we will do 1-index
       vector<vector<int>> dp(sizeA+1,vector<int>(sizeB+1,0));

       vector<int> curr(sizeB+1,0);
       vector<int> prev(sizeB+1,0);

       for(int i = 1 ; i <= sizeA ; i++){
        for(int j = 1 ; j <= sizeB ; j++){
            if(a[i-1] == b[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(prev[j],curr[j-1]);
        }
        prev= curr;
       }

       return prev.back();
}

int main(){
    string x = "brute";
    string y = "groot"; 
    cout<<longest_common_subsequence_optimised(x,y)<<"\n";
}