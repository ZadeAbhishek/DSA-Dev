/**
 * Given a rows x cols binary matrix filled with 0's and 1's, 
 * find the largest rectangle containing only 1's and return its area.
 * Input: matrix = [["1","0","1","0","0"],
 *                  ["1","0","1","1","1"],
 *                  ["1","1","1","1","1"],
 *                  ["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
 * 
*/

class Solution {
public:
int largestRectangleAreaOptimal1Pass(vector<int>& heights){
    stack<int> s;
    int uB = heights.size(); // upper Bound
    int max_Area = INT_MIN;
    for(int i = 0 ; i <= uB ; i++){
        while(!s.empty() && (i == uB || heights[s.top()] > heights[i])){
             int h = heights[s.top()]; // height
             s.pop();
             int w; // width
             if(s.empty()) w = i;
             else w = i - s.top() - 1;
             int area = h * w;
             max_Area = max(max_Area,area);
        }
        s.push(i);
    }
    return max_Area;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> currHeights(matrix[0].size(),0);
        int max_Area = INT_MIN;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size(); j++){
                if(matrix[i][j] == '1') currHeights[j] += 1;
                else currHeights[j] = 0; 
            }
            int curr_max_Area = largestRectangleAreaOptimal1Pass(currHeights);
            max_Area = max(max_Area,curr_max_Area);
        }
        return max_Area;
    }
};