/*
Code Question 1:

	•	Scenario: Data analysts at Amazon are analyzing outliers in data containing two co-related features. These features are represented as two arrays of integers, feature1 and feature2.
	•	Outliers Condition: A dataset is considered free of outliers if, for any two indices i and j where 0 \leq i < j < n:
	1.	If feature1[i] > feature1[j] then feature2[i] > feature2[j]
	2.	If feature1[i] < feature1[j] then feature2[i] < feature2[j]
If feature1[i] == feature1[j], the dataset is not considered free of outliers.
	•	Objective: Given the arrays feature1 and feature2, find the length of the largest array of indices (e.g., \(i_1, i_2, i_3, \dots, i_k\)) such that the dataset formed by these indices (i.e., feature1[i_1], feature1[i_2], …, feature1[i_k] and feature2[i_1], feature2[i_2], …, feature2[i_k]) is free of outliers.
	•	Example:
	•	Suppose n = 5, feature1 = [4, 5, 3, 1, 2] and feature2 = [2, 1, 3, 4, 5].
	•	The optimal choice of indices is [3, 4], corresponding to the values [1, 2] in feature1 and [4, 5] in feature2.
	•	Here, feature1[0] < feature1[1] and feature2[0] < feature2[1], so the condition holds true.
	•	The answer is 2 (the size of the chosen subset).
	•	Function Description:
	•	Complete the function getLargestIndexLen.
	•	This function takes two arguments:
	•	int feature1[n]: Values of the first feature.
	•	int feature2[n]: Values of the second feature.
*/

#include <vector>
#include <algorithm>
#include <iostream>

int getLargestIndexLen(const std::vector<int>& feature1, const std::vector<int>& feature2) {
    int n = feature1.size();
    std::vector<int> dp(n, 1);
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((feature1[i] > feature1[j] && feature2[i] > feature2[j]) ||
                (feature1[i] < feature1[j] && feature2[i] < feature2[j])) {
                dp[j] = std::max(dp[j], dp[i] + 1);
            }
        }
    }
    
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<int> feature1 = {4, 5, 3, 1, 2};
    std::vector<int> feature2 = {2, 1, 3, 4, 5};
    
    std::cout << getLargestIndexLen(feature1, feature2) << std::endl;  // Output: 2
    
    return 0;
}

/*
Dry Run code
{5,3,1,2}
{1,3,4,5}

dp = {1,1,1,1}; // since smallest valid sub sequent is one

for i = 0 
    j = 1 
    5 > 3 && 1 < 3 not valid
    i = 0 
    j = 2
    5 > 1 && 1 < 4 not valid
    i = 0
    j = 3
    5 > 2 && i < 5 not valid
    i = 0
    j = 4 loop over 

    dp = {1,1,1,1}

    i = 1
    j = 2
    3 > 1 && 3 < 4 not valid
    i = 1
    j = 3
    3 > 2 && 3 < 5 not valid
    i = 1
    j = 4 loop over

    dp = {1,1,1,1}

    i = 2
    j = 3
    1 < 2 && 4 < 5  true
    dp[3] = max(dp[3],dp[2]+1)
    dp[3] = max(1,2)
    dp[3] = 2

    i = 2
    j = 4 loop over

    dp = {1,1,2,1}

    i = 3
    j = 4 loop over

    i = 4 loop over

    dp = {1,1,2,1}

    max = 2

    ans = 2
*/


// recursive approch 

#include <vector>
#include <algorithm>
#include <iostream>

int getLargestIndexLenHelper(const std::vector<int>& feature1, const std::vector<int>& feature2, int i, int prevIndex) {
    if (i == feature1.size()) {
        return 0;
    }

    // Option 1: Don't include the current element (skip to the next element)
    int exclude = getLargestIndexLenHelper(feature1, feature2, i + 1, prevIndex);

    // Option 2: Include the current element if it forms a valid subsequence
    int include = 0;
    if (prevIndex == -1 || 
       (feature1[prevIndex] > feature1[i] && feature2[prevIndex] > feature2[i]) ||
       (feature1[prevIndex] < feature1[i] && feature2[prevIndex] < feature2[i])) {
        include = 1 + getLargestIndexLenHelper(feature1, feature2, i + 1, i);
    }

    // Return the maximum of including or excluding the current element
    return std::max(include, exclude);
}

int getLargestIndexLen(const std::vector<int>& feature1, const std::vector<int>& feature2) {
    return getLargestIndexLenHelper(feature1, feature2, 0, -1);
}

int main() {
    std::vector<int> feature1 = {4, 5, 3, 1, 2};
    std::vector<int> feature2 = {2, 1, 3, 4, 5};
    
    std::cout << getLargestIndexLen(feature1, feature2) << std::endl;  // Output: 2
    
    return 0;
}