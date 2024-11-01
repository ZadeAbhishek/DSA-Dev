class LRUCache {
    list<pair<int, int>> table; // Doubly linked list for storing keys and values in order
    unordered_map<int, list<pair<int, int>>::iterator> hash; // Map to store key and iterator to the linked list
    int capacity; // Cache capacity
    
public:
    LRUCache(int capacity) : capacity(capacity) {} // Initialize capacity using initializer list
    
    int get(int key) {
        if (hash.count(key)) { // If key is found in cache
            auto node = hash[key]; // Get iterator to the node
            int value = node->second; // Extract value
            table.erase(node); // Remove from current position
            table.push_back({key, value}); // Reinsert as most recent
            hash[key] = --table.end(); // Update hash map with new iterator position
            return value;
        } else {
            return -1; // Key not found
        }
    }
    
    void put(int key, int value) {
        if (hash.count(key)) { // If key already in cache
            auto node = hash[key];
            table.erase(node); // Erase the current entry
            table.push_back({key, value}); // Update with new value
            hash[key] = --table.end(); // Update iterator in hash map
        } else {
            if (table.size() >= capacity) { // If at capacity
                auto lru = table.front(); // Least recently used element
                hash.erase(lru.first); // Remove from hash map
                table.pop_front(); // Remove from list
            }
            table.push_back({key, value}); // Insert new element as most recent
            hash[key] = --table.end(); // Update hash map with new iterator
        }
    }
};