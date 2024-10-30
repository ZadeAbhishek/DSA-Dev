class Solution {
public:
// time limted existed
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if sorted i.e binary searh we can use
        for(auto arr : matrix){
            auto begin = arr.begin();
            auto end = arr.end();
            auto result = binary_search(begin, end, target);
            if(result) return result; 
        }
        return false;
    }
};



// optimised
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start with top right corner
        int i = 0;
        int j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0){
            int curr = matrix[i][j];
            if(curr == target) return true;
            else if(curr > target) j--;
            else if(curr < target) i++;
        }
        return false;
    }
};