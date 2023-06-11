// https://leetcode.com/problems/first-bad-version/

// Application of binary search

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // kind of binary search problem 
        
        // we know input are sorted obviosly
        
        // asume aleast one must be bad
        
        long high = n; 
        long low = 1;
        long mid = 0;
        
        while(mid != low)
        {
            mid = (long)abs((high + low)/2);
            if(!isBadVersion(mid)) low = mid + 1;
            else high = mid;
        }
        
         if(isBadVersion(mid)) return mid;
         else return 0;
    }
};