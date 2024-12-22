typedef pair<string, int> custVar;
class Solution {
    static bool cmp(custVar &a , custVar &b){
        return (a.second < b.second) || (a.second == b.second && a.first > b.first);
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> hash;
        for(auto x : words){
            hash[x]++;
        }
        priority_queue<custVar,vector<custVar>,decltype(&cmp)> pq(cmp);
        for(auto x : hash){
            pq.push({x.first,x.second});
        }
        
        vector<string> result;
        while(k-- && !pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;

    }
};


// chatgpt solution for optimised solution 
// Yes, we can optimize this solution by reducing the number of elements stored in the priority queue. Instead of inserting all elements and then extracting the top k, we can use a min-heap that only keeps the top k most frequent elements.


#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<string, int> custVar;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequencyMap;
        
        // Count the frequency of each word
        for (const auto& word : words) {
            frequencyMap[word]++;
        }

        // Use a min-heap to store the top k elements
        auto cmp = [](const custVar& a, const custVar& b) {
            return (a.second > b.second) || (a.second == b.second && a.first < b.first); // for topological
        };
        
        priority_queue<custVar, vector<custVar>, decltype(cmp)> minHeap(cmp);

        // Maintain only top k elements in the heap
        for (const auto& entry : frequencyMap) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove the least frequent or lexicographically largest
            }
        }

        // Extract elements from the heap and store in reverse order
        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<string> words = {"apple", "banana", "apple", "orange", "banana", "banana", "pear"};
    int k = 2;
    vector<string> topK = solution.topKFrequent(words, k);

    for (const string& word : topK) {
        cout << word << " ";
    }

    return 0;
}