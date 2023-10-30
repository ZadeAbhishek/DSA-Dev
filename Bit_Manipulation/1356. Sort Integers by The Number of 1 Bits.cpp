class Solution {
public:
    int countOnes(int num) {
        int ones = 0;
        while (num > 0) {
            if (num % 2 == 1) ones++;
            num /= 2;
        }
        return ones;
    }

    vector<int> sortByBits(vector<int>& arr) {
        // Using a lambda function for custom sorting
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            int countX = countOnes(x);
            int countY = countOnes(y);
            if (countX != countY) {
                return countX < countY;
            } else {
                return x < y;
            }
        });
        return arr;
    }
};



class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // Using a lambda function for custom sorting
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            int countX = __builtin_popcount(x); // count set bits
            int countY = __builtin_popcount(y);
            if (countX != countY) {
                return countX < countY;
            } else {
                return x < y;
            }
        });
        return arr;
    }
};
