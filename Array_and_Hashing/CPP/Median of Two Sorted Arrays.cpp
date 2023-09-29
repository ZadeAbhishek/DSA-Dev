#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedArray; 
        int i = 0 , j = 0;
        while(i < size(nums1) && j < size(nums2))
        {
             if(nums1[i] > nums2[j]) sortedArray.push_back(nums2[j]),j++;
             else sortedArray.push_back(nums1[i]),i++;
        }
        while(i < size(nums1)) sortedArray.push_back(nums1[i]),i++;
        while(j < size(nums2)) sortedArray.push_back(nums2[j]),j++;
        
        if(size(sortedArray) % 2 == 0) return (float) (sortedArray[size(sortedArray)/2] + sortedArray[(size(sortedArray)/2)-1])/2; 
        return (float) sortedArray[size(sortedArray)/2];
    }
};

class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // edge case
        if(size(nums1) == 1 && size(nums2) == 0) return nums1[0];
        if(size(nums2) == 1 && size(nums1) == 0) return nums2[0];
        
        int mid = (size(nums1) + size(nums2))/2;
        mid++;
        int j = 0, k = 0;
        int curr = 0 , prev = 0, count = 0;
        while(j < size(nums1) && k < size(nums2) && count < mid)
        {
            if(nums1[j] <= nums2[k]) prev = curr,curr = nums1[j],j++;
            else prev = curr,curr = nums2[k],k++;
            count++;
        }
        while(j < size(nums1) && count!=mid) prev = curr,curr = nums1[j],j++,count++;
        while(k < size(nums2) && count!=mid) prev = curr,curr = nums2[k],k++,count++;
        if((size(nums1) + size(nums2)) % 2 == 0) return (float) (curr + prev)/2;
        else return (float) curr;  
    }
};

int main() {
    Solution solution1;
    Solution2 solution2;

    // Test cases
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result1 = solution1.findMedianSortedArrays(nums1, nums2);
    double result2 = solution2.findMedianSortedArrays(nums1, nums2);

    cout << "Median (Solution 1): " << result1 << endl;
    cout << "Median (Solution 2): " << result2 << endl;

    return 0;
}
