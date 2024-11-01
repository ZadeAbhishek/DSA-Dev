class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unsigned int> people(n+1,0);
        for(auto t : trust){
            people[t[1]]++;
            people[t[0]]--;
        }
        for(size_t i = 1 ; i <= n; i++){
            if(people[i] == n-1) return i;
        }
        return -1;
    }
};