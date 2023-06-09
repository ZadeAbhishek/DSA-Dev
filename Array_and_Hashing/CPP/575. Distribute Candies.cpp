class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        for(auto c : candyType) s.insert(c);
        int t = s.size();
        int r = candyType.size()/2;
        if(r >= t) return t;
        return r;
    }
};