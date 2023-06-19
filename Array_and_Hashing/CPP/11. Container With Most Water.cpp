#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = INT_MIN;
        while(left < right){
            int height = min(heights[left],heights[right]);
            int width = right - left;
            int area = height * width;
            maxArea = max(maxArea,area);
            if(heights[left] < heights[right]) left++;
            else if(heights[left] > heights[right]) right--;
            else left++,right--;
        }
        return maxArea;
    }
};


int main(){
   vector<int> arr = {1,8,6,2,5,4,8,3,7};
   Solution *s;
   cout<<s->maxArea(arr);

}