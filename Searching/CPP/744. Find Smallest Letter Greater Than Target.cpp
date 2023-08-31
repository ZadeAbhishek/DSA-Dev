#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
      int high = letters.size() - 1;
      int low = 0;
      int mid = 0;
      char ans;

     	// edge case accroding to questions
      if (target < letters[0]) return letters[0];
      if (target >= letters[letters.size() - 1]) return letters[0];

     	// binary search to find char
      while (high >= low)
      {
        mid = (high + low) / 2;

        if (letters[mid] > target)
        {
          ans = letters[mid];
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      }

      return ans;
    }
};

int main()
{
  Solution solution;

 	// Test Case 1
  std::vector<char> letters1 = { 'c', 'f', 'j' };

  char target1 = 'a';
  char result1 = solution.nextGreatestLetter(letters1, target1);
  std::cout << "Test Case 1: Next greatest letter after '" << target1 << "' is '" << result1 << "'" << std::endl;

 	// Test Case 2
  std::vector<char> letters2 = { 'c', 'f', 'j' };

  char target2 = 'c';
  char result2 = solution.nextGreatestLetter(letters2, target2);
  std::cout << "Test Case 2: Next greatest letter after '" << target2 << "' is '" << result2 << "'" << std::endl;

 	// Test Case 3
  std::vector<char> letters3 = { 'c', 'f', 'j' };

  char target3 = 'd';
  char result3 = solution.nextGreatestLetter(letters3, target3);
  std::cout << "Test Case 3: Next greatest letter after '" << target3 << "' is '" << result3 << "'" << std::endl;

  return 0;
}