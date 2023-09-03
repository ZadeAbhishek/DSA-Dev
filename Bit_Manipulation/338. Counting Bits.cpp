#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to count the number of set bits (1s) for numbers from 0 to n.
    std::vector<int> countBits(int n) {
        std::vector<int> ans;

        // Iterate from 0 to n.
        for (int i = 0; i <= n; i++) {
            int count = 0; // Initialize count to 0.
            int num = i;   // Store the current number in 'num'.

            // Count the number of set bits in the binary representation of 'num'.
            while (num) {
                count += num & 1; // Increment count if the least significant bit is 1.
                num >>= 1;        // Right-shift 'num' to check the next bit.
            }

            ans.push_back(count); // Add the count to the result vector.
        }

        return ans; // Return the vector containing counts.
    }
};

// Brain Kernighan's Algorithm
class Solution2 {
public:
    // Function to count the number of set bits (1s) for numbers from 0 to n.
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n + 1);

        // Iterate from 0 to n.
        for (int i = 0; i <= n; i++) {
            int count = 0;
            int curr_no = i;

            // Using Brain Kernighan's Algorithm to count set bits.
            while (curr_no != 0) {
                curr_no &= (curr_no - 1); // Turn off the rightmost set bit.
                count++;                  // Increment count for each set bit.
            }

            ans[i] = count; // Store the count in the result vector.
        }

        return ans; // Return the vector containing counts.
    }
};

class Solution3 {
public:
    // Function to count the number of set bits (1s) for numbers from 0 to n.
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n + 1);
        ans[0] = 0; // The count of set bits for 0 is 0.

        // Iterate from 1 to n.
        for (int i = 1; i <= n; i++) {
            // Using a dynamic programming approach: ans[i] = ans[i/2] + i%2.
            ans[i] = ans[i / 2] + i % 2;
        }

        return ans; // Return the vector containing counts.
    }
};

int main() {
    // Test the three solutions with different 'n' values here.

    return 0;
}


int main() {
    Solution solution;
    
    int n = 5; // Change n to the desired value
    std::vector<int> result = solution.countBits(n);

    std::cout << "Count of set bits for numbers from 0 to " << n << ":" << std::endl;
    for (int i = 0; i <= n; i++) {
        std::cout << i << ": " << result[i] << std::endl;
    }

    return 0;
}
