#include<bits/stdc++.h>
using namespace std;

// Custom operator to print a 2D vector
void operator<< (ostream& Cout, vector<vector<int>> arr)
{
    for(auto &x : arr){ 
       for(auto &y : x) cout<<y<<" ";
       cout<<"\n";
       }

    return;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Initialize current row
        int currRow = 0;
        
        // Initialize the result vector to store Pascal's Triangle
        vector<vector<int>> result;
        
        while(currRow < numRows)
        {
            int columPtr = 0;
            
            vector<int> temp;
            
            while(columPtr <= currRow){
                
                if(columPtr == 0 || columPtr == currRow)
                    temp.push_back(1);
                else
                {
                    // Calculate the current element based on the previous row
                    temp.push_back(result[currRow - 1][columPtr - 1] + result[currRow - 1][columPtr]);
                }
                
                columPtr++;
            }
            result.push_back(temp);
            currRow++;
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        // Initialize current row
        int currRow = 0;
        
        // Initialize the result vector to store Pascal's Triangle
        vector<vector<int>> result;

        for(int col = 0; col < numRows; col++){
            result.push_back({});
            for(int j = 0; j <= col; j++){
                if(j == 0 || j == col)
                    result[col].push_back(1);
                else
                    // Calculate the current element based on the previous row
                    result[col].push_back(result[col - 1][j - 1] + result[col - 1][j]); 
            }
        }

        return result;
    }
};

class Solution3 {
public:
    vector<vector<int>> generate(int numRows) {
        // Initialize the result vector to store Pascal's Triangle
        vector<vector<int>> result(numRows);

        for(int col = 0; col < numRows; col++){
            result[col].resize(col + 1, 1);
            for(int j = 0; j <= col; j++){
                if(j == 0 || j == col)
                    continue;
                else
                    // Calculate the current element based on the previous row
                    result[col][j] = result[col - 1][j - 1] + result[col - 1][j]; 
            }
        }
        return result;
    }
};

int main (){
    int n = 10;
    Solution* solve = new  Solution();
    cout << "Solution 1:\n";
    cout << solve->generate(n);

    Solution2 solve2;
    cout << "Solution 2:\n";
    cout << solve2.generate(n);

    Solution3 solve3;
    cout << "Solution 3:\n";
    cout << solve3.generate(n);
    
    return 0;
}
