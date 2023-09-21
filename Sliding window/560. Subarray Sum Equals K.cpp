#include<bits/stdc++.h>
using namespace std;



// brute force
int subarraySumBrute(vector<int>& nums, int k) {
    int sum = 0;
    int count = 0;
    for(auto i = 0 ; i < nums.size(); i++){
        sum = 0;
        for(auto j = i ; j < nums.size(); j++){
            sum += nums[j];
            if(sum == k) count++; 
        }
    }
    return count;
}


// optimal solution
int subarraySum(vector<int>& nums, int k) {
         // prefix unorderd array 
         // basic intution is store the sum of each level in unordermap
         // as key = sum and value is number of occurance
         unordered_map<int,int> hash; // <sum,occorance>
         int sum = 0;
         int subArray_count = 0;
         hash[0] = 1; // start <0,1>
         for(auto i : nums){
             sum += i;
             int find_sub_array = sum - k; // check if sub is present in map if yes add count
             if(hash.count(find_sub_array)) subArray_count += hash[find_sub_array];
             hash[sum]++; 
         }
         return subArray_count;
         

    }



int main(){
    vector<int> s = {1,2,3};
    cout<<subarraySum(s,3)<<"\n";
    cout<<subarraySumBrute(s,3)<<"\n";
}