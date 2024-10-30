// ##Heap Questions

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() <= 1) return stones[0];
        while(stones.size() > 1){
            sort(stones.begin(),stones.end());
            // ittereate till one
            int lastElement = stones[stones.size() - 1];
            int secondlastElement = stones[stones.size() - 2];
            int temp = 0;
            if(lastElement > secondlastElement){
                temp = lastElement - secondlastElement;
            }
                stones.pop_back();
                stones.pop_back();
                if(temp != 0) stones.push_back(temp);
        }
        return stones.size() == 0?0:stones[0];
    }
};

// optimised Approch
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // we can use heap Here MaxHeap
        priority_queue<int> maxHeap(stones.begin(),stones.end());
        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if(stone1 != stone2){
                maxHeap.push(stone1 - stone2);
            }
        }
        return maxHeap.empty()?0:maxHeap.top();

    }
};
