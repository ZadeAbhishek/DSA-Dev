class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int curr = pref[0];
        for(int i = 1 ; i < pref.size(); i++){
            int prev = pref[i];
            pref[i] = prev ^ curr;
            curr = prev;
        }
        return pref;
    }
};