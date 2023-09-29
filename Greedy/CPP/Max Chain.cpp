#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int counter = 1; // Initialize a counter to keep track of the length of the chain.

        int maximun = INT_MIN; // Initialize a variable to store the maximum chain length.

        auto prev = pairs[0]; // Initialize a variable to store the previous pair.

        for(int i = 1; i < pairs.size(); i++) {
            auto curr = pairs[i]; // Get the current pair.

            if(curr[0] > prev[1]) {
                counter++; // If the current pair's first element is greater than the previous pair's second element, it's a valid chain.
            } else {
                counter = 1; // Otherwise, reset the chain length counter to 1.
            }

            maximun = max(maximun, counter); // Update the maximum chain length.

            prev = curr; // Update the previous pair for the next iteration.
        }

        return maximun; // Return the maximum chain length.
    }
};

// Driver function to test the Solution class
int main() {
    Solution solution;

    // Example input: a vector of pairs
    vector<vector<int>> pairs = {{1, 2}, {3, 4}, {5, 6}};

    // Call the findLongestChain function to find the longest chain length
    int longestChain = solution.findLongestChain(pairs);

    // Print the result
    cout << "The longest chain length is: " << longestChain << endl;

    return 0;
}
