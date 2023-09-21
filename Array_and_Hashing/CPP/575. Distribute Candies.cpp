#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        int uniqueCandy = s.size();
        int totalCandiesAllowed = candyType.size() / 2;
        if (totalCandiesAllowed >= uniqueCandy) {
            return uniqueCandy;
        }
        return totalCandiesAllowed;
    }
};

int main() {
    Solution solution;

    // Test the distributeCandies function
    vector<int> candyTypes1 = {1, 1, 2, 2, 3, 3};
    int result1 = solution.distributeCandies(candyTypes1);
    cout << "Sister can have " << result1 << " distinct types of candies." << endl;

    vector<int> candyTypes2 = {1, 1, 2, 3};
    int result2 = solution.distributeCandies(candyTypes2);
    cout << "Sister can have " << result2 << " distinct types of candies." << endl;

    return 0;
}
