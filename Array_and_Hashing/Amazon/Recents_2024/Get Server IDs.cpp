#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> getServerIds(int num_servers, const vector<int>& requests) {
    // Initialize an array to store the number of requests assigned to each server
    vector<int> server_requests(num_servers, 0);
    vector<int> assigned_servers;

    // Process each request in the 'requests' array
    for (int req : requests) {
        int min_requests = INT_MAX;
        int chosen_server = 0;  // Start with the first server as the default

        // Find the server with the minimum number of requests in the range [0, req - 1]
        for (int i = 0; i < req; i++) {
            if (server_requests[i] < min_requests) {
                min_requests = server_requests[i];
                chosen_server = i;
            }
        }

        // Assign the request to the chosen server and increment its request count
        server_requests[chosen_server]++;
        assigned_servers.push_back(chosen_server);
    }

    return assigned_servers;
}

// Driver code to test the function
int main() {
    int num_servers = 5;
    vector<int> requests = {3, 3, 4, 2, 1};

    vector<int> result = getServerIds(num_servers, requests);

    // Output the server assignments
    cout << "Server assignments: ";
    for (int server : result) {
        cout << server << " ";
    }
    cout << endl; // Expected output: [0, 1, 2, 0, 0]

    return 0;
}






#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Custom comparator for the priority queue to sort by load and then by server_id
struct ServerComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first) {
            return a.second > b.second; // if loads are the same, prefer the smaller server_id
        }
        return a.first > b.first; // otherwise, prefer the lower load
    }
};


// ##minHeap
vector<int> getServerIds(int num_servers, const vector<int>& requests) {
    // Initialize the priority queue with (load, server_id) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, ServerComparator> min_heap;
    vector<int> server_requests(num_servers, 0);
    vector<int> assigned_servers;

    // Initially, all servers have 0 load
    for (int i = 0; i < num_servers; ++i) {
        min_heap.push({0, i});
    }

    // Process each request
    for (int req : requests) {
        vector<pair<int, int>> temp; // Temporarily hold servers not in the range [0, req-1]

        // Find the server with the minimum load in the specified range
        pair<int, int> chosen_server;
        while (!min_heap.empty()) {
            chosen_server = min_heap.top();
            if (chosen_server.second < req) {
                min_heap.pop();
                break;
            } else {
                temp.push_back(chosen_server);
                min_heap.pop();
            }
        }

        // Restore the elements outside the range back to the heap
        for (auto& p : temp) {
            min_heap.push(p);
        }

        // Assign the request to the chosen server and increment its load
        assigned_servers.push_back(chosen_server.second);
        chosen_server.first++; // Increment the load of the chosen server

        // Push the updated server back into the heap
        min_heap.push(chosen_server);
    }

    return assigned_servers;
}

// Driver code to test the function
int main() {
    int num_servers = 5;
    vector<int> requests = {3, 3, 4, 2, 1};

    vector<int> result = getServerIds(num_servers, requests);

    // Output the server assignments
    cout << "Server assignments: ";
    for (int server : result) {
        cout << server << " ";
    }
    cout << endl; // Expected output: [0, 1, 2, 0, 0]

    return 0;
}