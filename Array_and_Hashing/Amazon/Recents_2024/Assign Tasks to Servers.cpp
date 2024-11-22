#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> assignTasksToServers(int servers, const vector<int>& requests) {
    // Min-heap to store the pair (load, server_id) for each server
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> server_queue;
    
    // Initialize server loads in the priority queue
    vector<int> server_load(servers, 0); // Track the load for each server
    for (int i = 0; i < servers; ++i) {
        server_queue.push({0, i});  // Initially, each server has load 0
    }

    vector<int> result; // To store the server assignment for each request

    for (int max_server : requests) {
        // Temporary storage to hold servers not in the allowed range (0 to max_server)
        vector<pair<int, int>> temp;

        // Find the least busy server within the allowed range
        pair<int, int> assigned_server;
        while (!server_queue.empty()) {
            auto server = server_queue.top();
            if (server.second <= max_server) {
                assigned_server = server;
                server_queue.pop();
                break;
            } else {
                temp.push_back(server);
                server_queue.pop();
            }
        }

        // Reinsert servers that were not in the allowed range
        for (const auto& server : temp) {
            server_queue.push(server);
        }

        // Record the assigned server and update its load
        result.push_back(assigned_server.second);
        server_load[assigned_server.second]++;
        assigned_server.first = server_load[assigned_server.second];

        // Push the updated server back into the queue
        server_queue.push(assigned_server);
    }

    return result;
}

// Driver code to test the function
int main() {
    int servers = 5;
    vector<int> requests = {3, 1, 0, 2, 1};

    vector<int> result = assignTasksToServers(servers, requests);

    cout << "Server assignments for each request: ";
    for (int server : result) {
        cout << server << " ";
    }
    cout << endl;

    return 0;
}