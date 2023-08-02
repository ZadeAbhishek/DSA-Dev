#include<bits/stdc++.h>
using namespace std;

void operator<<(std::ostream &Cout,std::vector<std::vector<int>> matrix){
    for(auto x : matrix){
        for(auto y : x) Cout<<y<<" ";
        Cout<<"\n";
    }
}


class Solution {
public:

    void combination(int n, int k, vector<vector<int>> &result, vector<int> &temp, int start)
    {
        // base case
        if(temp.size() == k){
           result.push_back(temp);
           return;
        }

        // main case
        for(int i = start ; i <= n ; i++){
                 temp.push_back(i);
                 combination(n,k,result,temp,i+1);
                 temp.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;

        vector<int> temp;

        combination(n,k,result,temp,1);
        
        return result;
    }
};


int main(){

    Solution s;
    cout<<s.combine(4,2);
}