class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int result = 0;
        for(auto it : grid){
            result = bs(it);
            if(result == -1) continue;
            int total = size(it) - result;
            count += total;
        }
        return count;
    }

    int bs(vector<int> &arr){
         int high = arr.size()-1;
         int low = 0;
         int mid;
         while(high >= low){
             if(high == low){
                 if(arr[high]<0) return high;
                 else return -1;
             }
             mid = (low + high)/2; 
             if(arr[mid] >= 0)  low = mid+1;
             else if(arr[mid] < 0) high = mid;
         }
         return -1;
    }
};

/*
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Input: grid = [[3,2],[1,0]]
Output: 0


*/