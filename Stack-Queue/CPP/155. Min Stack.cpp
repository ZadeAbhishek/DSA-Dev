/***
 * Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/


class MinStack {
    vector<int> stack;
    vector<int> min;
    int minElement;
public:
    MinStack() {
        stack.resize(0);
        minElement = INT_MAX;
        min.resize(0);
    }
    
    void push(int val) {
        stack.push_back(val);
        if(val <= minElement) minElement = val, min.push_back(val);
        return;
    }
    
    void pop() {
        int currval = stack.back();
        if(min.size() != 0 && currval == minElement) min.pop_back();
        if(min.size() == 0) minElement = INT_MAX;
        else minElement = min.back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
};


//optimised

class MinStack {
public:

vector<pair<int,int>> arr;
    MinStack() {

    }
    
    void push(int val) {
        if(arr.empty()){
            arr.push_back({val,val});
        }else{
            arr.push_back({val,min(val,arr.back().second)});
        }
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */