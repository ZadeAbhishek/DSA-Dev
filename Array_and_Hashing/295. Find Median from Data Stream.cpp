// 1 2 3 -------- 4 5
// max-heap    // min-heap
//          == return top of both
//          != return top of maxHeap


class MedianFinder {
    priority_queue<int,vector<int>> half_1; // maxHeap
    priority_queue<int,vector<int>,greater<int>> half_2;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // start with maxHeap because we medium element which will come on top 
        if(half_1.empty() || half_1.top() >= num) half_1.push(num);
        else half_2.push(num);

        // balance heap sicne we start with half_1 chance of odd array
        if(half_1.size() > half_2.size() + 1){
            half_2.push(half_1.top());
            half_1.pop();
        }
        else if(half_1.size() < half_2.size()){
            half_1.push(half_2.top());
            half_2.pop();
        }
    }
    
    double findMedian() {
        if(half_1.size() > half_2.size()) return (double)half_1.top();
        else return (double) (half_1.top() + half_2.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */