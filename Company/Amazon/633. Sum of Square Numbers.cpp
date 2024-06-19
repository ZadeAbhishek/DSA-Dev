class Solution {
public:
    bool judgeSquareSum(int c) {
        long long lower_bound = 0;
        long long upper_bound = sqrt(c);
        while(lower_bound <= upper_bound){
            long long mid = lower_bound + (upper_bound - lower_bound)/2;
            long long lower_square = lower_bound * lower_bound;
            long long upper_sqaure = upper_bound * upper_bound;
            if(lower_square + upper_sqaure == c) {
                return true;
            }

            if(lower_square + upper_sqaure > c) upper_bound--;
            else lower_bound++;
        }
        return false;
    }
};