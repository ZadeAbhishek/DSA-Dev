/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // finding the peak of moutain array
        int n = mountainArr.length();
        int left = 0;
        int right = n-1;
        int mid = 0;
        int peak = 0;

        while(left < right){
            mid = (left+right)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) left = peak = mid + 1;
            else right = mid;
        }
        // find target in the left of peak
        left = 0;
        right = peak;
        while(left <= right){
            mid = (left+right)/2;
            if(mountainArr.get(mid) < target) left = mid + 1;
            else if(mountainArr.get(mid) > target) right = mid - 1;
            else return mid;
        }
        // find target in the right of peak
        left = peak;
        right = n-1;
        while(left <= right){
            mid = (left+right)/2;
            if(mountainArr.get(mid) > target) left = mid + 1;
            else if(mountainArr.get(mid) < target) right = mid - 1;
            else return mid;
        }
        return -1;        
    }
};