#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<long long> getSmallerItems(vector<int> items, vector<int> start, vector<int> end, vector<int> query) {
        unordered_map<int,long> itemsCount;
        int n = 0;
        while(n <= start.size() - 1){
            for(auto i = start[n]; i <= end[n] && i < items.size() - 1; i++){
                itemsCount[items[i]]++;
            }

        }
        set<int> itemsHash(items.begin(),items.end());
        vector<long long> ans;
        for(auto q : query){
             long long tempCount = 0;
             for(auto it : itemsHash){
                 if(it < q) tempCount += itemsCount[it];
             }
             ans.push_back(tempCount);
        }
        return ans;
    }

     vector<long long> cummulativegetSmallerItems(vector<int> items, vector<int> start, vector<int> end, vector<int> query) {
        unordered_map<int, long long> itemsCount;
        int n = start.size();
        // if items = {1, 2, 2, 4, 5, 5, 5}
        /*
        Frequency Count: First, we count occurrences of each element:
	•	1 appears once.
	•	2 appears twice.
	•	4 appears once.
	•	5 appears three times.
         This can be represented as:
        */
        // Count items in the specified subranges
        for(int k = 0; k < n; ++k) {
            for(int i = start[k]; i <= end[k] && i < items.size(); ++i) {
                itemsCount[items[i]]++;
            }
        }
        // ##cumulative count
        // Use a sorted map for cumulative frequency calculation
        /*
        Cumulative Count: Next, we create a cumulative count by summing frequencies up to each element in sorted order:
	•	Cumulative count up to 1 = 1
	•	Cumulative count up to 2 = 1 + 2 = 3
	•	Cumulative count up to 4 = 3 + 1 = 4
	•	Cumulative count up to 5 = 4 + 3 = 7
        So, tthe cumulative count looks like this
        */
       /*
       Cumulative Count: Next, we create a cumulative count by summing frequencies up to each element in sorted order:
	•	Cumulative count up to 1 = 1
	•	Cumulative count up to 2 = 1 + 2 = 3
	•	Cumulative count up to 4 = 3 + 1 = 4
	•	Cumulative count up to 5 = 4 + 3 = 7
So, the cumulative count looks like this:
       */
        map<int, long long> cumulativeCount;
        long long currentCount = 0;
        for(const auto &pair : itemsCount) {
            cumulativeCount[pair.first] = currentCount += pair.second;
        }

        // Prepare answer based on queries
        vector<long long> ans;
        for(int q : query) {
            // Find the largest element smaller than q
            auto it = cumulativeCount.lower_bound(q);
            if(it == cumulativeCount.begin()) {
                ans.push_back(0);
            } else {
                --it;
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};

int main() {
    // Test case
    vector<int> items = {1, 2, 5, 4, 5};
    vector<int> start = {0, 0, 1};
    vector<int> end = {1, 2, 2};
    vector<int> query = {2, 4};

    Solution solution;
    vector<long long> result = solution.getSmallerItems(items, start, end, query);

    // Output results
    cout << "Results: ";
    for(long long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}