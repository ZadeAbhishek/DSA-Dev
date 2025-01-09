class Solution {
public:
   //##twoPointer
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int rightMax = height[right];
        int leftMax = height[left];
        int water = 0;
        

        while(left < right){
            if(leftMax < rightMax){
                /*
                 The condition if (leftMax < rightMax) is used to decide which pointer (left or right)
                 should be moved inward. This decision is based on the core observation that the amount 
                 of water trapped at a position depends on the smaller of the two heights (leftMax and rightMax) 
                 at the current pointers.
                */
                left++;
                leftMax = max(leftMax,height[left]);
                water += leftMax - height[left];
            }
            else {
                right--;
                rightMax = max(rightMax,height[right]);
                water += rightMax - height[right];
            }
        }
        return water;
    }
};