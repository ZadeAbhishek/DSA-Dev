#include <unordered_map>
#include <map>
#include <string>
using namespace std;
// ##BinarySearch
struct Node {
    map<int, string> hash; // Use map for efficient timestamp lookup
};

class TimeMap {
private:
    unordered_map<string, Node*> primaryHash;

public:
    TimeMap() {
        // Initialize data structure
    }
    
    void set(string key, string value, int timestamp) {
        // Check if the key exists
        if (!primaryHash.count(key)) {
            primaryHash[key] = new Node();
        }
        // Insert the value into the timestamp map for the given key
        primaryHash[key]->hash[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // Check if the key exists
        if (!primaryHash.count(key)) {
            return "";
        }

        auto temp = primaryHash[key];

        // Use lower_bound/upper_bound to find the closest timestamp
        auto it = temp->hash.upper_bound(timestamp);
        if (it == temp->hash.begin()) {
            // No valid timestamp exists
            return "";
        }
        --it; // Move to the largest timestamp <= given timestamp

        return it->second; // Return the corresponding value
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */