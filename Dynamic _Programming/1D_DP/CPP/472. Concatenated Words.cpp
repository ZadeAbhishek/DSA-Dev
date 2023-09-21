#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
      unordered_set<string> hash;
      for (auto x: words) hash.insert(x);
      vector<string> result;
      for (auto x: words)
      {
        int siz = x.size();
        vector<int> dp(siz + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < siz; i++)
        {
          if (!dp[i]) continue;
          for (int j = i + 1; j <= siz; j++)
          {
           	// same as word break just here we are checking if string match lenght 
           	// of it is equal to current lenght then this is word not concatinated word 
            if (j - i < siz && hash.count(x.substr(i, j - i)))
            {
              dp[j] = 1;
            }
          }

          if (dp[siz])
          {
            result.push_back(x);
            break;
          }
        }
      }

      return result;
    }
};

int main() {}