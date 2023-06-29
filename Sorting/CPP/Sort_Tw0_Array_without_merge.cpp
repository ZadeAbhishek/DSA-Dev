// Sort Two array withour Merging
// for This we are using Gap method 

#include<iostream>
#include<vector>
#include<math.h>


void operator<<(std::ostream &Cout ,std::vector<int> nums){
    for(int x : nums) Cout<<x<<" ";
    Cout<<"\n";
}

void gapSort(std::vector<int> &nums1 , std::vector<int> &nums2){
    // basic init
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;
    int gap = std::ceil(n/2.0);
    while(gap){
        int i = 0;
        int j = gap;
        while(j < n){
            if(i<n1 && j<n1 && nums1[i] > nums1[j]) std::swap(nums1[i],nums1[j]);
            else if(i<n1 && j>=n1 && nums1[i] > nums2[j-n1]) std::swap(nums1[i],nums2[j-n1]);
            else if(i>=n1 && j>=n1 && nums2[i-n1] > nums2[j - n1]) std::swap(nums2[i-n1],nums2[j-n1]);
            i++,j++;
        }
        if(gap == 1) gap = 0; // ciel never let gap == 0 since ciel(0.5) == 1
        gap = std::ceil(gap/2.0);
    }
    return;
}

int main(){
    std::vector<int> nums1 = {1,3,8,5,9,4,10,1,6};
    std::vector<int> nums2 = {2,4,6};
    gapSort(nums1,nums2);
    std::cout<<nums1;
    std::cout<<nums2;
}