#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long getNumTeams(vector<int>& skill, int min_skill, int max_skill) {
    sort(skill.begin(), skill.end());  // Step 1: Sort the skill array
    long count = 0;
    int n = skill.size();

    // Step 2: Iterate over each element and use binary search to find valid ranges
    for (int i = 0; i < n - 1; ++i) {
        int left = i + 1; 
        
        // Step 3: Binary search to find the smallest index where the sum is >= min_skill
        // Get the a pair with current elelemt and minmun skill
        int minIndex = lower_bound(skill.begin() + left, skill.end(), min_skill - skill[i]) - skill.begin();
        
        // Step 4: Binary search to find the largest index where the sum is <= max_skill
        int maxIndex = upper_bound(skill.begin() + left, skill.end(), max_skill - skill[i]) - skill.begin() - 1;

        // Step 5: If there are valid indices, add the number of pairs
        // Within this range all emplyee can be poosbublw pair with ith employee
        if (minIndex <= maxIndex) {
            count += (maxIndex - minIndex + 1);
        }
    }

    return count;
}

// Driver code to test the function
int main() {
    vector<int> skill = {3, 4, 1, 2, 5};
    int min_skill = 5;
    int max_skill = 7;

    long result = getNumTeams(skill, min_skill, max_skill);
    cout << "Number of valid teams: " << result << endl;  // Expected output depends on pairs in range

    return 0;
}