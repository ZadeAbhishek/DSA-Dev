// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/solutions/3602458/beats-100-c-python-solutions-sort-unordered-set-set/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int max_a = INT_MIN;
        int min_a = INT_MAX;

        for(auto x : arr) min_a = min(x,min_a),max_a = max(x,max_a);

        int n = arr.size();

        double k = (max_a - min_a)/(double)(n-1);

        if(fmod(k,1.0)!=0) return false;

        int d = k;

        if(d == 0) return true;

        unordered_set<int> set;

        for(auto x : arr){
            if((x-min_a)% d != 0) return false;

            set.insert(x);
        }

        return set.size() == n;
    }
};