#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // ##BruteForce
    // Brute-force solution for comparison
    vector<long long> brutefindNetworkCalls(vector<int> reviews, vector<int> counts) {
        vector<long long> result;
        for (auto x : counts) {
            long long temp = 0;
            for (auto y : reviews) {
                temp += std::abs(x - y);
            }
            result.push_back(temp);
        }
        return result;
    }

    // ##BinarySearch ##PrefixSum
    // Optimized solution with prefix sums and binary search
    vector<long long> findNetworkCalls(vector<int> reviews, vector<int> counts) {
        vector<long long> result;
        sort(reviews.begin(), reviews.end());
        vector<long long> prefix(reviews.size(), 0);
        prefix[0] = reviews[0];

        // Create prefix sum array
        for (size_t i = 1; i < reviews.size(); i++) {
            prefix[i] = prefix[i - 1] + reviews[i];
        }

        // For each target, calculate API calls
        for (auto target : counts) {
            long long apiCalls = 0;

            // Find position to divide less than and greater than target
            int pos = lower_bound(reviews.begin(), reviews.end(), target) - reviews.begin();

            // Calculate API calls for elements less than target
            if (pos > 0) {
                apiCalls += (long long)(target * pos) - prefix[pos - 1];
            }
            
            // Calculate API calls for elements greater than target
            if (pos < reviews.size()) {
                apiCalls += (prefix.back() - (pos > 0 ? prefix[pos - 1] : 0)) - (long long)(target * (reviews.size() - pos));
            }

            result.push_back(apiCalls);
        }
        return result;
    }

    // ##Median ##AbsoluteDifferences
    // Median-based approach to minimize API calls
    vector<long long> medianfindNetworkCalls(vector<int> reviews, vector<int> counts) {
        vector<long long> result;
        sort(reviews.begin(), reviews.end());
        int n = reviews.size();
        
        // Find the median of reviews
        int median = reviews[n / 2];

        // Calculate base API calls to make all reviews equal to the median
        long long baseApiCalls = 0;
        for (int review : reviews) {
            baseApiCalls += abs(review - median);
        }

        // For each target, adjust the base API calls
        for (int target : counts) {
            long long apiCalls = baseApiCalls;

            if (target != median) {
                long long adjustment = 0;
                for (int review : reviews) {
                    adjustment += abs(review - target) - abs(review - median);
                }
                apiCalls += adjustment;
            }
            result.push_back(apiCalls);
        }
        return result;
    }
};

// Function to run a test and compare all three solutions
void runTest(vector<int> reviews, vector<int> counts, int testCaseNum) {
    Solution solution;
    vector<long long> bruteResult = solution.brutefindNetworkCalls(reviews, counts);
    vector<long long> optimizedResult = solution.findNetworkCalls(reviews, counts);
    vector<long long> medianResult = solution.medianfindNetworkCalls(reviews, counts);
    
    bool passed = (bruteResult == optimizedResult) && (optimizedResult == medianResult);
    cout << "Test Case " << testCaseNum << ": " << (passed ? "Pass" : "Fail") << endl;

    // Print detailed comparison if test case fails
    if (!passed) {
        cout << "Brute-force Result: ";
        for (long long val : bruteResult) cout << val << " ";
        cout << "\nOptimized Result: ";
        for (long long val : optimizedResult) cout << val << " ";
        cout << "\nMedian-based Result: ";
        for (long long val : medianResult) cout << val << " ";
        cout << endl;
    }
}

int main() {
    // Test Case 8: Large size reviews array with repetitive values
    vector<int> reviews1(100000, 100); // 100,000 elements, all with the value 100
    vector<int> counts1 = {0, 50, 100, 200};
    runTest(reviews1, counts1, 8);

    // Test Case 9: Large size reviews with high variance
    vector<int> reviews2(100000);
    for (int i = 0; i < 100000; i++) reviews2[i] = i % 1000; // Values from 0 to 999 in a repeating pattern
    vector<int> counts2 = {500, 1000, 1500};
    runTest(reviews2, counts2, 9);

    // Test Case 10: Edge case with maximum integer values
    vector<int> reviews3(100000, INT_MAX); // All elements are INT_MAX
    vector<int> counts3 = {INT_MAX - 1, INT_MAX};
    runTest(reviews3, counts3, 10);

    // Test Case 11: Incremental array for reviews
    vector<int> reviews4(100000);
    for (int i = 0; i < 100000; i++) reviews4[i] = i;
    vector<int> counts4 = {50000};
    runTest(reviews4, counts4, 11);

    // Test Case 12: Random large input array with extreme values
    srand(time(0));
    vector<int> reviews5(100000);
    for (int i = 0; i < 100000; i++) reviews5[i] = rand() % 2000000 - 1000000;
    vector<int> counts5 = {-500000, 0, 500000};
    runTest(reviews5, counts5, 12);

    // Test Case 13: Alternating high and low values
    vector<int> reviews6(100000);
    for (int i = 0; i < 100000; i++) reviews6[i] = (i % 2 == 0) ? 1000 : -1000;
    vector<int> counts6 = {0};
    runTest(reviews6, counts6, 13);

    // Test Case 14: Increasing counts size with fixed reviews
    vector<int> reviews7 = {5, 10, 15, 20, 25};
    vector<int> counts7;
    for (int i = 0; i < 1000; i++) counts7.push_back(i * 5);
    runTest(reviews7, counts7, 14);

    return 0;
}