#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
      unordered_set<string> hash;
      for (auto x : words) hash.insert(x);
      vector<string> result;
      for (auto x : words)
      {
        int siz = x.size();
        vector<int> dp(siz + 1, 0);
        dp[0] = 1; // Base case: An empty string is a valid split.

        for (int i = 0; i < siz; i++)
        {
          if (!dp[i]) continue; // Skip if no valid split up to position i.

          for (int j = i + 1; j <= siz; j++)
          {
            // Check if the substring is a valid word and not the whole word itself.
            if (j - i < siz && hash.count(x.substr(i, j - i)))
            {
              dp[j] = 1; // Mark j as a valid split position.
            }
          }

          if (dp[siz])
          {
            result.push_back(x); // If the whole word is a valid split, it's a concatenated word.
            break;
          }
        }
      }

      return result;
    }
};

// Driver function to test the code
int main()
{
    Solution solution;
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};

    vector<string> concatenatedWords = solution.findAllConcatenatedWordsInADict(words);

    cout << "Concatenated words in the dictionary: ";
    for (const string &word : concatenatedWords)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
