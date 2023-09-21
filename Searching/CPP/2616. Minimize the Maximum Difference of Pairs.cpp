#include<bits/stdc++.h>
using namespace std;

// brute  force 
/*
Brute force O(N^2) 

*/
// 1023/1503 test case runed 
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        // using pair and sorting

        if(p == 0) return 0;
        
        unordered_set<int> diff;

        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ;j++){
                  diff.insert(abs(nums[i]-nums[j]));

            }
        }


        sort(diff.begin(),diff.end());

        int maxi = INT_MIN;

        int i = 0; 

        for(auto &x : diff){
        
        if(i == p) break;
        maxi = max(maxi,x);
        i++;

        }


        return maxi;       
    }
};

// binary plus greedy is solution
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {

       int mid, left , right;
       
       sort(nums.begin(),nums.end());

       left = 0;

       right = nums.back() - nums.front();

       while(left < right){

           mid = (left + right)/2;

           if(pair_banrahe_hai(nums,mid,p)) right = mid;
           else left = mid + 1;
       }

       return left;    
    }


    bool pair_banrahe_hai(vector<int>& nums,int mid,int p){

        int pair_formed = 0;

        for(int i = 0 ; i < nums.size() - 1 && pair_formed < p;){
            
            if(nums[i+1] - nums[i] <= mid) pair_formed++,i+=2;
            else i++;
        }

        return pair_formed >= p;
    }
};


int main(){}