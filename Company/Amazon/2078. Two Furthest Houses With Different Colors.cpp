class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // edge case 
        int noOfHouse = colors.size();
        if (noOfHouse < 1) return 0;
        if (noOfHouse == 2) return 1;

        // might be case if first and last house are different optimal case
        if (colors[0] != colors.back()) return noOfHouse - 1;

        // pointer approach
        int start = 0;
        int end = noOfHouse - 1;
        int paintStart = colors[0];
        int paintEnd = colors.back();
        int maxFromStart = INT_MIN;
        int maxFromEnd = INT_MIN;

        for (int i = 0; i < noOfHouse; i++) {
            if (paintStart != colors[i]) maxFromStart = max(maxFromStart, abs(i - 0));
            if (paintEnd != colors[noOfHouse - i - 1]) maxFromEnd = max(maxFromEnd, abs(noOfHouse - i - 1 - (noOfHouse - 1)));
        }
        return max(maxFromStart, maxFromEnd);
    }
};