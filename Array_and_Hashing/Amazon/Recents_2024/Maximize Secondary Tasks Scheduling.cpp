#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximizeSecondaryTasks(int limit, const std::vector<int>& primary, std::vector<int> secondary) {
        int n = primary.size();
        int secondaryTasksCount = 0;

        // Sort secondary tasks to facilitate finding the largest fitting task
        std::sort(secondary.begin(), secondary.end());

        // Loop through each day and schedule primary and the largest possible secondary task
        for (int i = 0; i < n; ++i) {
            int remainingTime = limit - primary[i];

            // Find the largest secondary task that fits in the remaining time
            auto it = std::upper_bound(secondary.begin(), secondary.end(), remainingTime);
            if (it != secondary.begin()) {
                --it; // Move to the largest element that is <= remainingTime
                secondaryTasksCount++;
                secondary.erase(it); // Remove the used secondary task
            }
        }
        return secondaryTasksCount;
    }
};

void testSolution() {
    Solution solution;

    // Test Case 1
    int limit1 = 7;
    std::vector<int> primary1 = {4, 5, 2, 4};
    std::vector<int> secondary1 = {5, 6, 3, 4};
    std::cout << "Test Case 1: " << solution.maximizeSecondaryTasks(limit1, primary1, secondary1) << " (Expected: 2)\n";

    // Test Case 2: All secondary tasks can fit
    int limit2 = 10;
    std::vector<int> primary2 = {3, 4, 2, 3};
    std::vector<int> secondary2 = {5, 5, 3, 4};
    std::cout << "Test Case 2: " << solution.maximizeSecondaryTasks(limit2, primary2, secondary2) << " (Expected: 4)\n";

    // Test Case 3: No time for any secondary task
    int limit3 = 5;
    std::vector<int> primary3 = {5, 5, 5, 5};
    std::vector<int> secondary3 = {1, 1, 1, 1};
    std::cout << "Test Case 3: " << solution.maximizeSecondaryTasks(limit3, primary3, secondary3) << " (Expected: 0)\n";

    // Test Case 4: Mixed case with some days having enough time, others not
    int limit4 = 6;
    std::vector<int> primary4 = {4, 2, 5, 3};
    std::vector<int> secondary4 = {3, 4, 1, 3};
    std::cout << "Test Case 4: " << solution.maximizeSecondaryTasks(limit4, primary4, secondary4) << " (Expected: 3)\n";

    // Test Case 5: Edge case with smallest possible inputs
    int limit5 = 1;
    std::vector<int> primary5 = {1};
    std::vector<int> secondary5 = {1};
    std::cout << "Test Case 5: " << solution.maximizeSecondaryTasks(limit5, primary5, secondary5) << " (Expected: 0)\n";

    // Test Case 6: Large values to test performance
    int limit6 = 100;
    std::vector<int> primary6(1000, 50); // 1000 elements with value 50
    std::vector<int> secondary6(1000, 49); // 1000 elements with value 49
    std::cout << "Test Case 6: " << solution.maximizeSecondaryTasks(limit6, primary6, secondary6) << " (Expected: 1000)\n";
}

int main() {
    testSolution();
    return 0;
}