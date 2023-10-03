class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                    if(nums[i] == nums[j]) count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> frequency; // Using a hash table to store frequencies
        int count = 0;

        for (int num : nums) {
            count += frequency[num]; // Add the current frequency to the count
            frequency[num]++; // Increment the frequency of the current number
        }

        return count;
    }
};