#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int max_a = INT_MIN;
        int min_a = INT_MAX;

        // Find the maximum and minimum elements in the array
        for (auto &x : arr) {
            min_a = min(x, min_a);
            max_a = max(x, max_a);
        }

        int n = arr.size();

        // Calculate the common difference 'k'
        double k = (max_a - min_a) / (double)(n - 1);

        // If 'k' is not an integer, it's not an arithmetic progression
        if (fmod(k, 1.0) != 0) {
            return false;
        }

        int d = k;

        // If 'd' is 0, it's a valid arithmetic progression
        if (d == 0) {
            return true;
        }

        unordered_set<int> set;

        // Check if each element is part of the progression
        for (auto x : arr) {
            if ((x - min_a) % d != 0) {
                return false;
            }

            set.insert(x);
        }

        // Check if all elements are distinct
        return set.size() == n;
    }
};

class Solution2 {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int diff = arr[1] - arr[0];
        
        // Check if the difference between consecutive elements is consistent
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    Solution2 solution2;

    // Test cases
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {3, 5, 1};

    cout << "Solution 1:" << endl;
    cout << "Can make arithmetic progression (arr1): " << solution.canMakeArithmeticProgression(arr1) << endl;
    cout << "Can make arithmetic progression (arr2): " << solution.canMakeArithmeticProgression(arr2) << endl;

    cout << "Solution 2:" << endl;
    cout << "Can make arithmetic progression (arr1): " << solution2.canMakeArithmeticProgression(arr1) << endl;
    cout << "Can make arithmetic progression (arr2): " << solution2.canMakeArithmeticProgression(arr2) << endl;

    return 0;
}
