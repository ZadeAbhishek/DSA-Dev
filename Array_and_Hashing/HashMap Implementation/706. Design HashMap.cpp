#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
   vector<list<pair<int, int>>> table;
   int size = 769;

public:
   // Constructor to initialize the hash map with a fixed size
   MyHashMap() {
      table.resize(size);
   }

   // Hash function to calculate the index for the given key
   int hashFunction(int key) {
      // A good prime number is used to reduce collisions
      return (key % size);
   }

   // Function to insert a key-value pair into the hash map
   // Parameters:
   // - key: The key to be inserted
   // - value: The value to be associated with the key
   void put(int key, int value) {
      // Get the index using the hash function
      int index = hashFunction(key);

      // Check if the index is already present in the hash map (chaining method)
      auto& chain = table[index];
      for (auto& curr : chain) {
         if (curr.first == key) {
            // Update the value if the key already exists in the hash map
            curr.second = value;
            return;
         }
      }

      // If the key is not found, add the key-value pair to the chain
      chain.push_back({ key, value });
   }

   // Function to get the value associated with a given key from the hash map
   // Parameters:
   // - key: The key for which the value is to be retrieved
   // Returns:
   // - The value associated with the given key, or -1 if the key is not found
   int get(int key) {
      // Get the index using the hash function
      int index = hashFunction(key);

      // Loop through the chain to find the key and retrieve its value
      auto& chain = table[index];
      for (auto curr : chain) {
         if (curr.first == key)
            return curr.second;
      }

      // Return -1 if the key is not found in the hash map
      return -1;
   }

   // Function to remove a key-value pair from the hash map
   // Parameters:
   // - key: The key to be removed from the hash map
   void remove(int key) {
      // Get the index using the hash function
      int index = hashFunction(key);

      // Find the key in the chain and remove the corresponding pair
      auto& chain = table[index];
      for (auto curr : chain) {
         if (curr.first == key) {
            chain.remove(curr);
            return;
         }
      }
   }
};

int main() {
   MyHashMap myHashMap;
   myHashMap.put(1, 1); // The map is now [[1,1]]
   myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
   cout << myHashMap.get(1) << "\n"; // Output: 1, The map is now [[1,1], [2,2]]
   cout << myHashMap.get(3) << "\n"; // Output: -1 (i.e., not found), The map is now [[1,1], [2,2]]
   myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
   cout << myHashMap.get(2) << "\n"; // Output: 1, The map is now [[1,1], [2,1]]
   myHashMap.remove(2); // Remove the mapping for key 2, The map is now [[1,1]]
   cout << myHashMap.get(2) << "\n"; // Output: -1 (i.e., not found), The map is now [[1,1]]
}
