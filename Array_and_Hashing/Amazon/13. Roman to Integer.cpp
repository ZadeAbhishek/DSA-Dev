class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToInteger = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int num = romanToInteger[s.back()]; // Start with the last character's value
        for (int i = s.size() - 2; i >= 0; i--) {
            if (romanToInteger[s[i]] < romanToInteger[s[i + 1]]) {
                num -= romanToInteger[s[i]];
            } else {
                num += romanToInteger[s[i]];
            }
        }
        return num;
    }
};