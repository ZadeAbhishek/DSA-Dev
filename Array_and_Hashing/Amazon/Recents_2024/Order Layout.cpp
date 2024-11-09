#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;


// ##stringstream ##all_of
vector<string> getOrderLayout(string layout) {
    unordered_set<string> uniqueValues; // To ensure configuration values are unique
    vector<string> configurations(10000, ""); // Fixed-size vector for 4-digit indices
    int minIndex = 10000, maxIndex = 0; // Track the smallest and largest indices

    // Split the layout string by '|'
    stringstream ss(layout);
    string segment;
    while (getline(ss, segment, '|')) {
        if (segment.size() < 4) return {"Invalid configuration"};

        // Extract the index and configuration value
        int index = stoi(segment.substr(0, 4));
        string value = segment.substr(4);

        // Validation checks
        if (index < 1 || index > 9999 || !all_of(value.begin(), value.end(), ::isalnum)) {
            return {"Invalid configuration"};
        }
        if (!configurations[index].empty() || uniqueValues.count(value) > 0) {
            return {"Invalid configuration"};
        }

        // Store the configuration and update the min/max indices
        configurations[index] = value;
        uniqueValues.insert(value);
        minIndex = min(minIndex, index);
        maxIndex = max(maxIndex, index);
    }

    // Check if indices are sequential from minIndex to maxIndex
    for (int i = minIndex; i <= maxIndex; ++i) {
        if (configurations[i].empty()) {
            return {"Invalid configuration"};
        }
    }

    // Collect the configurations in order
    vector<string> result;
    for (int i = minIndex; i <= maxIndex; ++i) {
        result.push_back(configurations[i]);
    }

    return result;
}

int main() {
    string layout = "0001LAJ5KBX9H8|0003UKURNK403F|0002MO6K1Z9WFA|0004OWRXZFMS2C";
    vector<string> result = getOrderLayout(layout);
    
    for (const auto& config : result) {
        cout << config << " ";
    }
    cout << endl;

    return 0;
}