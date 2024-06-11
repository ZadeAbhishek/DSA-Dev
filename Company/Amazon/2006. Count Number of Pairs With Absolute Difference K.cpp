// basic solutions
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // basic for loop will also work i guess
        int counter = 0;
        for(int i = 0; i < nums.size() ; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(abs(nums[j] - nums[i]) == k) counter++;
            }
        }
        return counter;
    }
};

// optimised solution
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // we can use hasham here
        int counter = 0;
        unordered_map<int,int> hash;
        for(auto &num : nums) hash[num]++; // store in hash
        for(auto &p : hash){
            // p == key , value
            if(hash.count(p.first + k)){
                counter += p.second * hash[p.first + k];
            }
        }
        return counter;
    }
};


// chatgpt Solution 
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int counter = 0;
        unordered_map<int, int> hash;
        
        for (int num : nums) {
            // Check for the presence of num - k and num + k
            if (hash.count(num - k)) {
                counter += hash[num - k];
            }
            if (hash.count(num + k)) {
                counter += hash[num + k];
            }
            // Increment the count for the current number in the hash map
            hash[num]++;
        }
        
        return counter;
    }
};