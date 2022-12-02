class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // here i know 0 postion and nth positon is 1
        
        int currRow = 0;
        
        vector<vector<int>> result;
        
        while(currRow < numRows)
        {
            int columPtr = 0;
            
            vector<int> temp;
            
            while(columPtr <= currRow){
                
                if(columPtr == 0 || columPtr == currRow) temp.push_back(1);
                
                else
                {
                    temp.push_back(result[currRow-1][columPtr-1]+result[currRow-1][columPtr]);
                }
                
                columPtr++;
            }
            result.push_back(temp);
            currRow++;
        }
     return result;
    }
};
