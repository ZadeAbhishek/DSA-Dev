#include<bits/stdc++.h>
using namespace std;

void operator<< (ostream& Cout, vector<vector<int>> arr)
{
    for(auto i = 0 ; i < size(arr) ; i++)
    {
        for(auto j = 0 ; j < size(arr[i]); j++) Cout<<arr[i][j]<<" ";
        Cout<<"\n";
    }
    return;
}


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


int main (){
    int n = 10;
    Solution* solve = new  Solution();
    cout<<solve->generate(n);
    return 0;
}