class MyQueue {
    // FOR this according to me stack is need
    stack<int> stack1;
    stack<int> stack2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        while(! stack1.empty()) stack2.push(stack1.top()),stack1.pop();
        int temp = stack2.top();
        stack2.pop();
        while( ! stack2.empty()) stack1.push(stack2.top()),stack2.pop();
        return temp;
    }
    
    int peek() {
        while(! stack1.empty()) stack2.push(stack1.top()),stack1.pop();
        int temp = stack2.top();
        while(! stack2.empty()) stack1.push(stack2.top()),stack2.pop();
        return temp;
    }
    
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */