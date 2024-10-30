class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> hash;
        for(auto i = 0 ; i < s.size(); i++){
            hash[s[i]] = i;
        }
        int currentWindowIndex = 0;
        int start = 0;
        vector<int> ans;
        for(auto i = 0 ; i < s.size(); i++){
            currentWindowIndex = max(hash[s[i]],currentWindowIndex);
            if(i == currentWindowIndex){
                  ans.push_back(currentWindowIndex - start + 1);
                  start = i+1;
            }
        }
        return ans;
    }
};