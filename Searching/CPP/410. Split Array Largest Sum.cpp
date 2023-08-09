/// https://www.youtube.com/watch?v=bcAwHkL7A3A&ab_channel=CodewithAlisha

// https://leetcode.com/problems/split-array-largest-sum/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:

   	// function to check if we can divide the array into k part or not
    int get_max_sum_minimun_elemnt(vector<int> &nums, int maxSum)
    {
      int count = 1;
      int sum = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        if (sum + nums[i] > maxSum)
        {
          count++;
          sum = nums[i];
        }
        else sum += nums[i];
      }

      return count;
    }

  int splitArray(vector<int> &nums, int k)
  {
   	// we are taking max element as low so if we divied array in size one subparts
   	// the low would be max element
    int low = *max_element(nums.begin(), nums.end());	// max element of nums

   	// we are taking sum of array as high when sub array of size equal to array size is max sum of array
    int high = accumulate(nums.begin(), nums.end(), 0);	// sum of all elements

    int ans = 0;

   	// apply binary search on the range and check can we divide the array into K parts we yes
   	// store value as ans else shift to right side of range
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int currMaxPartition = get_max_sum_minimun_elemnt(nums, mid);
      if (currMaxPartition > k) low = mid + 1;
      else
      {
        ans = mid;
        high = mid - 1;
      }
    }

    return ans;
  }
};

// Driver function to test the splitArray function
void testSplitArray()
{
  Solution solution;

 	// Test Case 1
  std::vector<int> nums1 = { 7, 2, 5, 10, 8 };

  int m1 = 2;
  int result1 = solution.splitArray(nums1, m1);
  std::cout << "Test Case 1: Largest sum after splitting nums1 with m = " << m1 << " is " << result1 << std::endl;

 	// Test Case 2
  std::vector<int> nums2 = { 1, 2, 3, 4, 5 };

  int m2 = 3;
  int result2 = solution.splitArray(nums2, m2);
  std::cout << "Test Case 2: Largest sum after splitting nums2 with m = " << m2 << " is " << result2 << std::endl;

 	// Test Case 3
  std::vector<int> nums3 = { 1, 4, 4 };

  int m3 = 3;
  int result3 = solution.splitArray(nums3, m3);
  std::cout << "Test Case 3: Largest sum after splitting nums3 with m = " << m3 << " is " << result3 << std::endl;
}

int main()
{
  testSplitArray();
  return 0;
}