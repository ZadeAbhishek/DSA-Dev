#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countSubstrings(string S) {
        int len = S.length(), ans = 0;
        for (int i = 0; i < len; i++) {
            int j = i - 1, k = i;
            while (k < len - 1 && S[k] == S[k+1]){ 
                k++;
            }
            ans += (k - j) * (k - j + 1) / 2, i = k++;
            //while (~j && k < len && S[k++] == S[j--]) ans++;
        }
        return ans;
    }
};



// first approch usng matrix
class Solution2 {
public:
    int countSubstrings(string s) {
        vector<vector<int>> table(size(s),vector<int>(size(s),0));
        int cPalindrom = 0;

        int i=0,j=0;

        for(auto diff = 0 ; diff < size(s) ; diff++)
        {
            for(i = 0 , j = i + diff ; j < size(s) ; i++ , j++ )
            {
                //cout<<i<<" "<<j<<"\n";
                if(diff == 0)
                {
                   table[i][j] = 1;
                }
                else if(diff == 1 && s[i] == s[j])
                {
                    table[i][j] = 2;
                }
                else if(s[i] == s[j] && table[i + 1][j - 1])
                {
                    table[i][j] = table[i+1][j-1] + 2;
                }
                
                if(table[i][j]) cPalindrom++;
                
            }
        }
        return cPalindrom;
    }
};

int main()
{
   string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
   Solution* solve = new Solution();
   cout<<solve->countSubstrings(s);
}