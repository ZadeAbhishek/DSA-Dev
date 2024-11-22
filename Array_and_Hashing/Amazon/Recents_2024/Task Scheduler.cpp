#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    // Step 1: Count the frequency of each task
    unordered_map<char, int> taskCount;
    for (char task : tasks) {
        taskCount[task]++;
    }

    // Step 2: Initialize a min-heap to store the next available time for each task
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> minHeap;
    int currentTime = 0;

    // Step 3: Push all tasks into the heap with an initial next available time of 0
    for (const auto& entry : taskCount) {
        minHeap.push({0, entry.first});
    }

    // Step 4: Simulate scheduling
    while (!minHeap.empty()) {
        auto [nextAvailableTime, task] = minHeap.top();
        
        if (nextAvailableTime > currentTime) {
            // If the task's next available time is greater than the current time, we idle
            currentTime++;
        } else {
            // Step 5: Schedule the task
            minHeap.pop(); // Remove it from the heap

            // Reduce the task count and check if it needs to be scheduled again
            taskCount[task]--;
            if (taskCount[task] > 0) {
                // If more instances of this task remain, update its next available time and push back
                minHeap.push({currentTime + n + 1, task});
            } else {
                // Remove the task from the map if it has no more instances
                taskCount.erase(task);
            }
            
            // Move to the next time slot after scheduling
            currentTime++;
        }
    }

    return currentTime;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'C'};
    int n = 2;
    cout << "Minimum intervals required: " << leastInterval(tasks, n) << endl; // Expected output: 6
    return 0;
}