#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> getOperations(const vector<int>& resource) {
    int rLen = resource.size();
    vector<int> sortedResources = resource;
    sort(sortedResources.begin(), sortedResources.end());
    
    unordered_map<int, int> map_num2Idx;
    for (int i = 0; i < rLen; i++) {
        map_num2Idx[resource[i]] = i; // Map each number to its index in the original array
    }
    
    vector<int> result;
    for (int i = 1; i < rLen; i++) {
        int curNum = sortedResources[i];
        int preNum = sortedResources[i - 1];
        if (map_num2Idx[curNum] < map_num2Idx[preNum]) {
            result.push_back(curNum); // Add curNum to the result if it's out of order with preNum
        }
    }
    
    return result;
}

// Driver code to test the function
int main() {
    vector<int> resource = {6, 4, 3, 5, 2, 1};
    vector<int> result = getOperations(resource);

    cout << "Operations: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}