class Solution {
public:

    int gcd(int min , int max)
    {
        if(max == 0 || min == 0) return 0;
        
        if(max == min) return max;

        if(max > min) return gcd(min,max-min);
        
        return gcd(min-max,max);
    }


    int findGCD(vector<int>& nums) {
        // idea is to send the two number and great there
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for(auto it : nums)
        {
            if(it >= maximum) maximum = it;
            if(it <= minimum) minimum = it;
        }
        cout<<maximum<<" "<<minimum<<"\n";
        return gcd(minimum,maximum); 
    }
};