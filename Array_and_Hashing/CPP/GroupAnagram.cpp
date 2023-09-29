#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
#include <queue>
using namespace std;
class Solution {
public:
string sortString(string str)
{
   sort(str.begin(), str.end());
   return str;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        int i = 0;
        while(i< strs.size()){
            string sorted = sortString(strs[i]);
            cout<<strs[i]<<endl;
            if(hash.count(sorted)){
                hash[sorted].push_back(strs[i]);
            }
            else{
                vector<string> temp;
                temp.push_back(strs[i]);
                hash.insert({sorted,temp});
            }
            i++;
        }
        vector<vector<string>> result;
        int hash_index = 0;
        for (auto x : hash){
            result.push_back(x.second);
        }
        return result;
    }
    
};

int main (){
     vector<string>  s = {"eat","tea","tan","ate","nat","bat"};
    Solution* solve = new Solution();    
    vector<vector<string>> result = solve->groupAnagrams(s);
    for(int i = 0;i<result.size();i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

}