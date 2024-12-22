#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Custom comparator for the Min Heap
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Min Heap based on login count
    }
};

void findLeastLoggedInUsers(vector<int>& logins) {
    unordered_map<int, int> loginCount; // Map to store login counts for each user

    // Step 1: Count logins for each user
    for (int user : logins) {
        loginCount[user]++;
    }

    // Step 2: Push all user-loginCount pairs into a Min Heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    for (auto& entry : loginCount) {
        minHeap.push({entry.first, entry.second});
    }

    // Step 3: Extract the minimum login count
    int minCount = minHeap.top().second;
    cout << "Users with the least amount of logins (" << minCount << " logins): ";

    // Step 4: Retrieve all users with the minimum count
    while (!minHeap.empty() && minHeap.top().second == minCount) {
        cout << minHeap.top().first << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of login attempts: ";
    cin >> n;

    cout << "Enter the user IDs for each login attempt:\n";
    vector<int> logins(n);
    for (int i = 0; i < n; i++) {
        cin >> logins[i];
    }

    findLeastLoggedInUsers(logins);

    return 0;
}



#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findLeastLoggedInUsers(vector<int>& logins) {
    unordered_map<int, int> loginCount; // Map to store login counts for each user

    // Step 1: Count logins for each user
    for (int user : logins) {
        loginCount[user]++;
    }

    // Step 2: Find the minimum login count
    int minCount = INT_MAX;
    for (auto& entry : loginCount) {
        minCount = min(minCount, entry.second);
    }

    // Step 3: Collect users with the minimum login count
    vector<int> leastLoggedInUsers;
    for (auto& entry : loginCount) {
        if (entry.second == minCount) {
            leastLoggedInUsers.push_back(entry.first);
        }
    }

    // Output the result
    cout << "Users with the least amount of logins (" << minCount << " logins): ";
    for (int user : leastLoggedInUsers) {
        cout << user << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of login attempts: ";
    cin >> n;

    cout << "Enter the user IDs for each login attempt:\n";
    vector<int> logins(n);
    for (int i = 0; i < n; i++) {
        cin >> logins[i];
    }

    findLeastLoggedInUsers(logins);

    return 0;
}