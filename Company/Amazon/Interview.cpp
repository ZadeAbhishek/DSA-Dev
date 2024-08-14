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
    std::vector<int> dp(n, 1);  // DP array initialized to 1
    
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