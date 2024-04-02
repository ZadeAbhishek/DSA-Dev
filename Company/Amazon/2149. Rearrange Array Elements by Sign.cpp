#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm library for the reverse function

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int counter = 0;
        int nums_size = nums.size();
        for(auto num : nums){
            if(num < 0) neg.push_back(num);
            else pos.push_back(num);
        }

        reverse(pos.begin(),pos.end());
        reverse(neg.begin(), neg.end());

        nums.clear();

        while(nums_size){
            if(counter) nums.push_back(neg.back()), neg.pop_back();
            else nums.push_back(pos.back()), pos.pop_back();
            counter = !counter;
            nums_size--;
        }

        return nums;
    }
};


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
 
      // another solution might relatd to pointer
      int posptr = 0;
      int negptr = 1;
      vector<int>result(nums.size(),0);
      for(auto &num : nums){
        if(num < 0) result[negptr] = num, negptr += 2;
        else result[posptr] = num, posptr += 2;
      }
      return result; 


    }
    
    };

int main() {
    // Test the rearrangeArray function
    vector<int> nums = {1, -2, 3, -4, 5, -6};
    Solution solution;
    vector<int> result = solution.rearrangeArray(nums);

    // Output the result
    cout << "Rearranged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}