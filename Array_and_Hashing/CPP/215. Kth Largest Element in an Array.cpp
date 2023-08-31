#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap(nums.begin(), nums.end());
        for(int i = 1; i < k; i++) heap.pop();
        return heap.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
         
        k = (nums.size()) - k;

        int start = 0;
        int end = nums.size()-1; 
        int index = start;
        while(start <= end){
            int pivot=nums[end];
            int i=start-1;
            for(int j=start;j<end;j++){
            if(nums[j]<=pivot){
                i++;
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
        i++;
        int temp=nums[end];
        nums[end]=nums[i];
        nums[i]=temp;

            if((k) < i) end = i-1,start = 0;
            else if((k) > i) start = i+1;
            else return nums[i];
            
        }
    

        return -1;
    }
};

void drive() {
    vector<int> nums = {2,1};
    // sort(nums.begin(),nums.end());
    // reverse(nums.begin(),nums.end());
    int k = 1;

    Solution3 sol1;
    Solution2 sol2;

    cout << "Using Solution1: " << sol1.findKthLargest(nums, k) << endl;
    cout << "Using Solution2: " << sol2.findKthLargest(nums, k) << endl;
}

int main() {
    drive();
    return 0;
}
