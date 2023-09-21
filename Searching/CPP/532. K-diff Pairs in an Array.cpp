#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        // unordered mao init
        unordered_map<int,int> hash;

        for(auto &x : nums) hash[x]++;

        int count = 0;

        for(auto &x : hash){
            // edges case
            if(k == 0){
                // if any number has count greater t han zero
                if(x.second > 1) count++;
            }
            else{

                if(hash.count(x.first + k)) count++;
            }
        }

        return count;
    
    }
};


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, i = 0, j = 1;
        for(i, j; i<nums.size() && j<nums.size(); ) {
            if(i==j || nums[j]-nums[i]<k) j++;
            else {
                if(nums[j]-nums[i]==k) {
                    ans++;
                    j++;
                    while(j<nums.size() && nums[j]==nums[j-1]) j++; // remove redundant
                }
                i++;
                while(i<j && nums[i]==nums[i-1]) i++; // remove redundant
            }
        }
        return ans;
    }
};

int main(){}