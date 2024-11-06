// ##minHeap
class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // Min heap to keep track of K largest elements
    int K;

public:
    KthLargest(int k, std::vector<int>& nums) {
        K = k;
        
        // Insert elements in the min heap, ensuring it has at most K elements
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > K) {
                minHeap.pop();  // Keep only K largest elements in the heap
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > K) {
            minHeap.pop();  // Remove smallest element to maintain K elements
        }
        
        // The top of the min heap is the Kth largest element
        return minHeap.top();
    }
};

/**
 * Example usage:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */