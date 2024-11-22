#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>

// recursive approch top down
int lengthOfLIS(int nums[], int size, int curr, int prev) {
        // base case
        if(curr == size) return 0;

        // case 1 we have to include the element 
        //        if we are including elements we know if curr > prev then olny include
        //        or if prev = -1
        int includeCurr = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
        includeCurr = 1 + lengthOfLIS(nums,size,curr+1,curr); // since we are including so our prev = curr
        }
 
        int notincludeCurr = 0;
        notincludeCurr = lengthOfLIS(nums,size,curr+1,prev); // since we are not including our prev will not change

        return std::max(includeCurr,notincludeCurr); // return max
}


// recursive approch + dp top down
int lengthOfLISDp(int nums[], int size, int curr, int prev, std::vector<std::vector<int>> &memo) {
        // base case
        if(curr == size) return 0;

        // case 1 we have to include the element 
        //        if we are including elements we know if curr > prev then olny include
        //        or if prev = -1

        if(memo[curr][prev+1] != -1) return memo[curr][prev+1];

        int includeCurr = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
        includeCurr = 1 + lengthOfLISDp(nums,size,curr+1,curr,memo); // since we are including so our prev = curr
        }
 
        int notincludeCurr = 0;
        notincludeCurr = 0 + lengthOfLISDp(nums,size,curr+1,prev,memo); // since we are not including our prev will not change

        // prev + 1 becuase prev starts with -1 so -1+1 = 0 starting index
        return memo[curr][prev+1] =  std::max(includeCurr,notincludeCurr); // return max
}

// Tabulation dp bottom up approch
//tp o(n^2) sp O(n^2)
int lengthOfLISTab(int nums[], int size) {

    // Memoization
    std::vector<std::vector<int>> memo(size+1,std::vector<int>(size+1,0));

    for(int curr = size-1; curr >= 0; curr--){
        for(int prev = curr-1; prev >= -1; prev--){
             int take = 0;
             if(prev == -1 || nums[curr] > nums[prev])
             take = 1 + memo[curr+1][prev+1];

             int nottake = 0;
             nottake = 0 + memo[curr+1][prev+1];

             memo[curr][prev+1] = std::max(take,nottake);
        }
    }
    return memo[1][0];
}


// Tabulation dp bottom up approch
//tp o(n^2) sp O(n)
int lengthOfLISTabSO(int nums[], int size) {

    // Memoization
    //std::vector<std::vector<int>> memo(size+1,std::vector<int>(size+1,0));
    std::vector<int> currRow(size+1,0);
    std::vector<int> nextRow(size+1,0);

    for(int curr = size-1; curr >= 0; curr--){
        for(int prev = curr-1; prev >= -1; prev--){
             int take = 0;
             if(prev == -1 || nums[curr] > nums[prev])
             take = 1 + nextRow[curr+1];

             int nottake = 0;
             nottake = 0 + nextRow[prev+1];

             currRow[prev+1] = std::max(take,nottake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}


//using binary search
// tc O(nlogn) sc:O(n)
int lengthOfLISTabOptimal(std::vector<int> nums) {
    if(nums.size() == 0) return 0;
    std::vector<int> ans;
    ans.push_back(nums[0]);
    for(auto curr = 1 ; curr < nums.size(); curr++){
        if(nums[curr] > ans.back()) ans.push_back(nums[curr]);
        else{
             // basically lower bond is binary search return positon of lower of curr no   
             int getIndex = std::lower_bound(ans.begin(),ans.end(),nums[curr]) - ans.begin(); 
             ans[getIndex] = nums[curr];
        }
    }
    return ans.size(); 

}

int main(){
    int nums[] = {10,9,2,5,3,7,101,18};
    std::vector<int> nums2 = {10,9,2,5,3,7,101,18};
    int size = sizeof nums/sizeof nums[0];
    std::cout<<lengthOfLIS(nums,size, 0 , -1)<<"\n";
    std::vector<std::vector<int>> memo(size+1,std::vector<int>(size+1,-1));
    std::cout<<lengthOfLISDp(nums,size, 0 , -1,memo)<<"\n";
    std::cout<<lengthOfLISTab(nums,size)<<"\n";
    std::cout<<lengthOfLISTabSO(nums,size)<<"\n";
    std::cout<<lengthOfLISTabOptimal(nums2)<<"\n";
}