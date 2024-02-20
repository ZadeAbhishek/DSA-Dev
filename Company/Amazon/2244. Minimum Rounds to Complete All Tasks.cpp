#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minimumRoundsWithArray(vector<int>& tasks) {
        if(tasks.empty()) 
            return -1;
        
        int maxElement = *max_element(tasks.begin(), tasks.end());
        vector<long long int> counter(maxElement + 1, 0);

        for(auto task : tasks) 
            counter[task]++;

        int minTime = 0;

        for(auto currNo : counter) {
            if(currNo == 0) 
                continue;

            if(currNo == 1) 
                return -1;

            minTime += (currNo / 3) + (currNo % 3 != 0);
        }
        return minTime;
    }

    int minimumRoundsWithHashMap(vector<int>& tasks) {
        unordered_map<int, int> counterForTasks;

        for(auto diffLevTask : tasks) {
            if(counterForTasks.count(diffLevTask)) 
                counterForTasks[diffLevTask]++;
            else 
                counterForTasks.insert({diffLevTask, 1});
        }
        
        int minTime = 0;

        for(auto &taskDiffLevPair : counterForTasks) {
            if(taskDiffLevPair.second == 1) 
                return -1;
            minTime += (taskDiffLevPair.second / 3) + (taskDiffLevPair.second % 3 != 0);
        }

        return minTime;
    }
};

int main() {
    vector<int> tasks = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9};
    
    Solution solution;
    
    // Timing for minimumRoundsWithArray
    auto start = high_resolution_clock::now();
    int result1 = solution.minimumRoundsWithArray(tasks);
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);
    
    cout << "Result with array: " << result1 << endl;
    cout << "Time taken with array: " << duration1.count() << " microseconds" << endl;

    // Timing for minimumRoundsWithHashMap
    start = high_resolution_clock::now();
    int result2 = solution.minimumRoundsWithHashMap(tasks);
    stop = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop - start);

    cout << "Result with hashmap: " << result2 << endl;
    cout << "Time taken with hashmap: " << duration2.count() << " microseconds" << endl;

    return 0;
}
