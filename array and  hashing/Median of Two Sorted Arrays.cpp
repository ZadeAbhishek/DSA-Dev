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